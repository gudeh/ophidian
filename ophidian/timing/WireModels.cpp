#include "WireModels.h"

namespace ophidian
{
namespace timing
{
namespace wiremodel
{

EffectiveCapacitance::EffectiveCapacitance() :
    m_precision(1e-6),
    m_slews(nullptr),
    m_delays(nullptr),
    m_ceff(nullptr),
    m_slews_owner(true),
    m_delays_owner(true),
    m_ceff_owner(true)
{

}

EffectiveCapacitance::~EffectiveCapacitance()
{
    if(m_ceff_owner && m_ceff)
        delete m_ceff;

    if(m_delays_owner && m_delays)
        delete m_delays;

    if(m_slews_owner && m_slews)
        delete m_slews;
}

void EffectiveCapacitance::precision(precicion_type epsilon)
{
    m_precision = epsilon;
}

const node_mapper_type<slew_type>& EffectiveCapacitance::slews() const
{
    return *m_slews;
}

void EffectiveCapacitance::slews(node_mapper_type<slew_type>& sm)
{
    m_slews_owner = false;
    m_slews = &sm;
}

const node_mapper_type<slew_type>& EffectiveCapacitance::delays() const
{
    return *m_delays;
}

void EffectiveCapacitance::delays(node_mapper_type<slew_type>& dm)
{
    m_delays_owner = false;
    m_delays = &dm;
}

void EffectiveCapacitance::ceff(node_mapper_type<capacitance_type> &cm)
{
    m_ceff_owner = false;
    m_ceff = &cm;
}

const node_mapper_type<capacitance_type>& EffectiveCapacitance::ceff() const
{
    return *m_ceff;
}

}   // namespace wiremodel
}   // namespace timing
}   // namespace ophidian
