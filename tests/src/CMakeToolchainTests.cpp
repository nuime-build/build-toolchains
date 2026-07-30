// SPDX-FileCopyrightText: 2015-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeToolchainTests.h"
#include "Nuime/BuildToolchains/CMakeToolchain.h"
#include <Ishiko/BasePlatform.hpp>
#include <Ishiko/Process.hpp>
#include <boost/filesystem.hpp>

using namespace Nuime;

CMakeToolchainTests::CMakeToolchainTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "CMakeToolchain tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("generate test 1", GenerateTest1);
    append<Ishiko::HeapAllocationErrorsTest>("generate test 2", GenerateTest2);
}

void CMakeToolchainTests::ConstructorTest1(Ishiko::Test& test)
{
    CMakeToolchain toolchain;

    ISHIKO_TEST_PASS();
}

void CMakeToolchainTests::GenerateTest1(Ishiko::Test& test)
{
    const boost::filesystem::path& cmakelists_path = test.context().getOutputPath("GenerateTest1/CMakeLists.txt");
    boost::filesystem::create_directories(cmakelists_path.parent_path());
    test.utils().copy("${context.data}/cmake/hello-world/CMakeLists.txt", cmakelists_path.string());
    test.utils().copy("${context.data}/cmake/hello-world/main.cpp", "${context.output}/GenerateTest1/main.cpp");

    CMakeToolchain toolchain;
    toolchain.generate(cmakelists_path.string(), Ishiko::CurrentEnvironment());

    ISHIKO_TEST_PASS();
}

void CMakeToolchainTests::GenerateTest2(Ishiko::Test& test)
{
    const boost::filesystem::path& cmakelists_path = test.context().getOutputPath("GenerateTest2/CMakeLists.txt");
    boost::filesystem::create_directories(cmakelists_path.parent_path());
    test.utils().copy("${context.data}/cmake/hello-world/CMakeLists.txt", cmakelists_path.string());
    test.utils().copy("${context.data}/cmake/hello-world/main.cpp", "${context.output}/GenerateTest2/main.cpp");

    CMakeToolchain toolchain;

#if ISHIKO_OS == ISHIKO_OS_LINUX
    CMakeGenerationOptions options("Unix Makefiles", "", {});
#elif ISHIKO_OS == ISHIKO_OS_WINDOWS
    CMakeGenerationOptions options("Visual Studio 17 2022", "x64", {});
#else
#error Unsupported or unrecognized OS
#endif

    toolchain.generate(cmakelists_path.string(), options, Ishiko::CurrentEnvironment());

    ISHIKO_TEST_PASS();
}
