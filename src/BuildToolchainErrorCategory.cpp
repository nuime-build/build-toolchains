/*
    Copyright (c) 2020-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "BuildToolchainErrorCategory.h"

using namespace Ishiko;

namespace Nuime
{

BuildToolchainErrorCategory::BuildToolchainErrorCategory() noexcept
    : ErrorCategory(ID(0xaf2004b884154a20ULL, 0xa18ecf97052a8a91ULL)) // af2004b8-8415-4a20-a18e-cf97052a8a91
{
}

const BuildToolchainErrorCategory& BuildToolchainErrorCategory::Get() noexcept
{
    static BuildToolchainErrorCategory theCategory;
    return theCategory;
}

const char* BuildToolchainErrorCategory::name() const noexcept
{
    return "CodeSmithy::BuildToolchainErrorCategory";
}

const char* BuildToolchainErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    case Value::build_error:
        return "build error";

    default:
        return "unknown value";
    }
}

void Fail(Error& error, BuildToolchainErrorCategory::Value value) noexcept
{
    error.fail(BuildToolchainErrorCategory::Get(), static_cast<int>(value));
}

void Fail(Error& error, BuildToolchainErrorCategory::Value value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(BuildToolchainErrorCategory::Get(), static_cast<int>(value), message, file, line);
}

void Throw(BuildToolchainErrorCategory::Value value, const std::string& message, const char* file, int line)
{
    throw Exception(static_cast<int>(value), BuildToolchainErrorCategory::Get(), message, file, line);
}

}
