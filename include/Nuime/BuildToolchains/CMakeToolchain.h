// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_CMAKETOOLCHAIN_H
#define GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_CMAKETOOLCHAIN_H

#include "CMakeGenerationOptions.h"
#include <Ishiko/Process.hpp>
#include <string>

namespace CodeSmithy
{
    class CMakeToolchain
    {
    public:
        CMakeToolchain();

        void generate(const std::string& makefilePath, const Ishiko::Environment& environment) const;
        void generate(const std::string& makefilePath, const CMakeGenerationOptions& options,
            const Ishiko::Environment& environment) const;

        void build(const std::string& makefile_path, const Ishiko::Environment& environment) const;
        void build(const std::string& makefile_path, const std::string& target,
            const Ishiko::Environment& environment) const;

    private:
        std::string m_cmakePath;
    };
}

#endif
