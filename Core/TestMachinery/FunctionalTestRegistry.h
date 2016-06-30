// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/TestMachinery/FunctionalTestRegistry.h
//! @brief     Declares class FunctionalTestRegistry.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FUNCTIONALTESTREGISTRY_H
#define FUNCTIONALTESTREGISTRY_H

#include <vector>
#include <string>
#include <map>

#include "WinDllMacros.h"
#include "FunctionalTestInfo.h"
#include "ISingleton.h"

//! @class FunctionalTestRegistry
//! @ingroup standard_samples
//! @brief The registry which holds information about available functional tests.

class BA_CORE_API_ FunctionalTestRegistry : public ISingleton<FunctionalTestRegistry>
{
public:
    FunctionalTestRegistry();
    void add(const std::string& test_name, const std::string& test_description,
             const std::string& simulation_name, const std::string& sample_builder_name,
             const std::string& component_registry_name, double threshold);
    const FunctionalTestInfo* getItemOrExplain(
        const std::string& test_name, const std::string& suite_name) const;
    void printCatalogue(std::ostream& ostr) const;

private:
    std::map<std::string, FunctionalTestInfo> m_catalogue;
};

#endif