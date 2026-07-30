/*
    Copyright (c) 2020-2026 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "MSBuildToolchainTests.h"
#include "Nuime/BuildToolchains/MSBuildToolchain.h"

using namespace Ishiko;

MSBuildToolchainTests::MSBuildToolchainTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "MSBuildToolchain tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void MSBuildToolchainTests::ConstructorTest1(Test& test)
{
    Nuime::MSBuildToolchain toolchain;
    
    ISHIKO_TEST_PASS();
}
