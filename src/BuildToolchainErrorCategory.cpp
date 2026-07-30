/*
    Copyright (c) 2020-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#include "BuildToolchainErrorCategory.h"

using namespace Ishiko;

namespace Nuime
{

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
