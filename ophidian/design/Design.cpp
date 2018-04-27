/*
 * Copyright 2017 Ophidian
   Licensed to the Apache Software Foundation (ASF) under one
   or more contributor license agreements.  See the NOTICE file
   distributed with this work for additional information
   regarding copyright ownership.  The ASF licenses this file
   to you under the Apache License, Version 2.0 (the
   "License"); you may not use this file except in compliance
   with the License.  You may obtain a copy of the License at
   http://www.apache.org/licenses/LICENSE-2.0
   Unless required by applicable law or agreed to in writing,
   software distributed under the License is distributed on an
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
   KIND, either express or implied.  See the License for the
   specific language governing permissions and limitations
   under the License.
 */

#include "Design.h"

namespace ophidian
{
namespace design
{
    Design::netlist_type& Design::netlist() noexcept
    {
        return m_netlist;
    }

    const Design::netlist_type& Design::netlist() const noexcept
    {
        return m_netlist;
    }

    Design::floorplan_type& Design::floorplan() noexcept
    {
        return m_floorplan;
    }

    const Design::floorplan_type& Design::floorplan() const noexcept
    {
        return m_floorplan;
    }

    Design::placement_type& Design::placement() noexcept
    {
        return m_placement;
    }

    const Design::placement_type& Design::placement() const noexcept
    {
        return m_placement;
    }

    Design::standard_cell_type& Design::standard_cells() noexcept
    {
        return m_standard_cells;
    }

    const Design::standard_cell_type& Design::standard_cells() const noexcept
    {
        return m_standard_cells;
    }

    Design::library_type& Design::library() noexcept
    {
        return m_library;
    }

    const Design::library_type& Design::library() const noexcept
    {
        return m_library;
    }
}     //namespace design
}     //namespace ophidian
