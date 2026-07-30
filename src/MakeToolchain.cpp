/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "MakeToolchain.h"
#include "BuildToolchainErrorCategory.h"
#include <boost/filesystem/path.hpp>

namespace Nuime
{

namespace
{

std::string CreateCommandLine(const std::string& makePath, const std::string& makefilePath)
{
    std::string commandLine = makePath;
    commandLine.append(" -C ");
    commandLine.append(boost::filesystem::path(makefilePath).parent_path().string());
    commandLine.append(" -f ");
    commandLine.append(boost::filesystem::path(makefilePath).filename().string());
    return commandLine;
}

}

MakeToolchain::MakeToolchain()
    : m_makePath("/usr/bin/make")
{
}

void MakeToolchain::build(const std::string& makefilePath, const Ishiko::Environment& environment) const
{
    std::string commandLine = CreateCommandLine(m_makePath, makefilePath);
    Ishiko::ChildProcess processHandle = Ishiko::ChildProcess::Spawn(commandLine, environment);
    processHandle.waitForExit();
    int exitCode = processHandle.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::Value::build_error, "Process launched by " + commandLine
            + " exited with code " + std::to_string(exitCode), __FILE__, __LINE__);
    }
};

}
