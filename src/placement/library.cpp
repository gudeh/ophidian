/*
 * library.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: csguth
 */

#include "library.h"

namespace openeda {
namespace placement {

library::library(openeda::standard_cell::standard_cells * std_cells) : m_system(std_cells->system()) {
	std_cells->register_property(&m_geometries);
}

library::~library() {
}

void library::geometry(entity::entity cell, multipolygon geometry) {
    m_geometries[m_system.lookup(cell)] = geometry;
}

void library::dist2microns(int32_t dist)
{
    m_dist2microns = dist;
}

} /* namespace placement */
} /* namespace openeda */
