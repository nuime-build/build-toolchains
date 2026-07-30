/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-toolchains/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_MAKETOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_MAKETOOLCHAIN_H_

#include <Ishiko/Process.hpp>
#include <string>

namespace CodeSmithy
{

class MakeToolchain
{
public:
    MakeToolchain();

    void build(const std::string& makefilePath, const Ishiko::Environment& environment) const;

private:
    std::string m_makePath;
};

}

#endif
