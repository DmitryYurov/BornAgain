// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Aggregate/InterferenceFunction3DLattice.h
//! @brief     Defines class InterferenceFunction3DLattice.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef INTERFERENCEFUNCTION3DLATTICE_H
#define INTERFERENCEFUNCTION3DLATTICE_H

#include "IInterferenceFunction.h"
#include "Lattice.h"

class IPeakShape;

//! Interference function of a 3D lattice.
//! @ingroup interference

class BA_CORE_API_ InterferenceFunction3DLattice : public IInterferenceFunction
{
public:
    InterferenceFunction3DLattice(const Lattice& lattice);
    ~InterferenceFunction3DLattice() final;

    InterferenceFunction3DLattice* clone() const override final;

    void accept(INodeVisitor* visitor) const override final { visitor->visit(this); }

    void setPeakShape(const IPeakShape& peak_shape);

    const Lattice& lattice() const;

    bool supportsMultilayer() const override final { return false; }

    std::vector<const INode*> getChildren() const override final;

    void onChange() override final;
private:
    double iff_without_dw(const kvector_t q) const override final;
    InterferenceFunction3DLattice(const InterferenceFunction3DLattice& other);
    void initRecRadius();
    Lattice m_lattice;
    std::unique_ptr<IPeakShape> mP_peak_shape;
    double m_rec_radius;  //!< radius in reciprocal space defining the nearest q vectors to use
};

#endif // INTERFERENCEFUNCTION3DLATTICE_H
