// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_CMAKEGENERATIONOPTIONS_H
#define GUARD_CODESMITHYIDE_BUILDTOOLCHAINS_CMAKEGENERATIONOPTIONS_H

#include <boost/optional/optional.hpp>
#include <map>
#include <string>

namespace CodeSmithy
{
    class CMakeGenerationOptions
    {
    public:
        CMakeGenerationOptions();
        CMakeGenerationOptions(const std::string& generator_name, const std::string& architecture_name,
            const std::map<std::string, std::string>& cache_entries);

        const boost::optional<std::string>& generatorName() const;
        const boost::optional<std::string>& architectureName() const;
        const std::map<std::string, std::string> cacheEntries() const;

    private:
        boost::optional<std::string> m_generator_name;
        boost::optional<std::string> m_architecture_name;
        std::map<std::string, std::string> m_cache_entries;
    };
}

#endif
