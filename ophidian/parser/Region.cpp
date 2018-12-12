/*
 * Copyright 2018 Ophidian
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

#include "Region.h"

namespace ophidian::parser
{
    const Region::name_type& Region::name() const noexcept
    {
        return m_name;
    }

    const Region::rectangles_container_type& Region::rectangles() const noexcept
    {
        return m_rectangles;
    }

    bool Region::operator==(const Region& rhs) const noexcept
    {
        auto boxComparator = [](const database_unit_box_type & box1, const database_unit_box_type & box2) -> bool {
                return box1.min_corner().x() == box2.min_corner().x() && box1.max_corner().x() == box2.max_corner().x()
                && box1.min_corner().y() == box2.min_corner().y() && box1.max_corner().y() == box2.max_corner().y();
        };

        return m_name == rhs.m_name 
                && m_rectangles.size() == rhs.m_rectangles.size()
                && std::is_permutation(m_rectangles.begin(), m_rectangles.end(), rhs.m_rectangles.begin(), boxComparator);
    }

    std::ostream& operator<<(std::ostream& os, const Region& region)
    {
        os << "{name: " << region.m_name;

        os << ", rectangles: {";
        for (auto rectangle : region.rectangles()) {
            os << "(" << rectangle.min_corner().x() << ", " << rectangle.min_corner().y() << ")" << " -> (" 
            << rectangle.max_corner().x() << "," << rectangle.max_corner().y() << ") ";
        }
        os << "}";
        
        os << "}";

        return os;
    }
}