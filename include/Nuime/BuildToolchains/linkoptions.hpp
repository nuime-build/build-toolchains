// SPDX-FileCopyrightText: 2020-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_LINKOPTIONS_HPP
#define GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_LINKOPTIONS_HPP

#ifdef _DEBUG
#pragma comment(lib, "nuime_buildtoolchains-d.lib")
#else
#pragma comment(lib, "nuime_buildtoolchains.lib")
#endif

#endif
