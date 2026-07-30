/*
    Copyright (c) 2020-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAINERRORCATEGORY_H
#define GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_BUILDTOOLCHAINERRORCATEGORY_H

#include <Ishiko/Errors.hpp>
#include <string>

namespace CodeSmithy
{

class BuildToolchainErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum class Value
    {
        generic_error = -1,
        build_error = -2
    };

    static const BuildToolchainErrorCategory& Get() noexcept;

    const char* name() const noexcept override;
    const char* message(int ev, char* buffer, size_t len) const noexcept override;

private:
    BuildToolchainErrorCategory() noexcept = default;
};

void Fail(Ishiko::Error& error, BuildToolchainErrorCategory::Value value) noexcept;
void Fail(Ishiko::Error& error, BuildToolchainErrorCategory::Value value, const std::string& message,
    const char* file, int line) noexcept;
void Throw(BuildToolchainErrorCategory::Value value, const std::string& message, const char* file, int line);

}

#endif
