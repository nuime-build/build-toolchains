// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeGenerationOptions.h"

using namespace Nuime;

CMakeGenerationOptions::CMakeGenerationOptions()
{
}

CMakeGenerationOptions::CMakeGenerationOptions(const std::string& generator_name, const std::string& architecture_name,
    const std::map<std::string, std::string>& cache_entries)
    : m_generator_name(generator_name), m_cache_entries(cache_entries)
{
    if (!architecture_name.empty())
    {
        m_architecture_name = architecture_name;
    }
}

const boost::optional<std::string>& CMakeGenerationOptions::generatorName() const
{
    return m_generator_name;
}

const boost::optional<std::string>& CMakeGenerationOptions::architectureName() const
{
    return m_architecture_name;
}

const std::map<std::string, std::string> CMakeGenerationOptions::cacheEntries() const
{
    return m_cache_entries;
}
