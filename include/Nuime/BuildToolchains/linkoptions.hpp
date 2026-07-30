// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_LINKOPTIONS_HPP
#define GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_LINKOPTIONS_HPP

#ifdef _DEBUG
#pragma comment(lib, "CodeSmithyBuildToolchains-d.lib")
#else
#pragma comment(lib, "CodeSmithyBuildToolchains.lib")
#endif

#endif
