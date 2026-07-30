// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeToolchain.h"
#include "BuildToolchainErrorCategory.h"
#include <Ishiko/BasePlatform.hpp>

using namespace Nuime;

namespace
{
    Ishiko::CommandLine CreateGenerationCommandLine(const std::string& cmake_path, const std::string& makefile_path,
        const CMakeGenerationOptions& options)
    {
        Ishiko::CommandLine command_line(cmake_path);
        boost::optional<std::string> generator_name = options.generatorName();
        if (generator_name)
        {
            command_line.appendArgument("-G");
            command_line.appendArgument(*generator_name);
        }
        boost::optional<std::string> architecture_name = options.architectureName();
        if (architecture_name)
        {
            command_line.appendArgument("-A");
            command_line.appendArgument(*architecture_name);
        }
        command_line.appendArgument("-S");
        command_line.appendArgument(boost::filesystem::path(makefile_path).parent_path().string());
        command_line.appendArgument("-B");
        command_line.appendArgument(boost::filesystem::path(makefile_path).parent_path().string());
        for (const std::pair<std::string, std::string>& cacheEntry : options.cacheEntries())
        {
            command_line.appendArgument("-D" + cacheEntry.first + "=" + cacheEntry.second);
        }
        return command_line;
    }

    Ishiko::CommandLine CreateBuildCommandLine(const std::string& cmake_path, const std::string& makefile_path,
        const std::string* target)
    {
        Ishiko::CommandLine command_line(cmake_path);
        command_line.appendArgument("--build");
        command_line.appendArgument(boost::filesystem::path(makefile_path).parent_path().string());
        if (target)
        {
            command_line.appendArgument("--target");
            command_line.appendArgument(*target);
        }
        return command_line;
    }
}

CMakeToolchain::CMakeToolchain()
// TODO: proper way to configure the cmake path
#if ISHIKO_OS == ISHIKO_OS_LINUX
    : m_cmakePath("/usr/local/bin/cmake")
#elif ISHIKO_OS == ISHIKO_OS_WINDOWS
    : m_cmakePath("cmake")
#else
#error Unsupported or unrecognized OS
#endif
{
}

void CMakeToolchain::generate(const std::string& makefilePath, const Ishiko::Environment& environment) const
{
    CMakeGenerationOptions options;
    generate(makefilePath, options, environment);
}

void CMakeToolchain::generate(const std::string& makefilePath, const CMakeGenerationOptions& options,
    const Ishiko::Environment& environment) const
{
    Ishiko::CommandLine command_line = CreateGenerationCommandLine(m_cmakePath, makefilePath, options);
    Ishiko::ChildProcessBuilder process_builder(command_line, environment);
    Ishiko::ChildProcess process = process_builder.start();
    process.waitForExit();
    int exit_code = process.exitCode();
    if (exit_code != 0)
    {
        Throw(BuildToolchainErrorCategory::Value::build_error, "Process launched by "
            + command_line.toString(Ishiko::CommandLine::Mode::quote_if_needed) + " exited with code "
            + std::to_string(exit_code), __FILE__, __LINE__);
    }
}

void CMakeToolchain::build(const std::string& makefile_path, const Ishiko::Environment& environment) const
{
    Ishiko::CommandLine command_line = CreateBuildCommandLine(m_cmakePath, makefile_path, nullptr);
    Ishiko::ChildProcessBuilder process_builder(command_line, environment);
    Ishiko::ChildProcess process = process_builder.start();
    process.waitForExit();
    int exit_code = process.exitCode();
    if (exit_code != 0)
    {
        Throw(BuildToolchainErrorCategory::Value::build_error, "Process launched by "
            + command_line.toString(Ishiko::CommandLine::Mode::quote_if_needed) + " exited with code "
            + std::to_string(exit_code), __FILE__, __LINE__);
    }
}

void CMakeToolchain::build(const std::string& makefile_path, const std::string& target,
    const Ishiko::Environment& environment) const
{
    Ishiko::CommandLine command_line = CreateBuildCommandLine(m_cmakePath, makefile_path, &target);
    Ishiko::ChildProcessBuilder process_builder(command_line, environment);
    Ishiko::ChildProcess process = process_builder.start();
    process.waitForExit();
    int exit_code = process.exitCode();
    if (exit_code != 0)
    {
        Throw(BuildToolchainErrorCategory::Value::build_error, "Process launched by "
            + command_line.toString(Ishiko::CommandLine::Mode::quote_if_needed) + " exited with code "
            + std::to_string(exit_code), __FILE__, __LINE__);
    }
}
