//--------------------------------------------------------------------------
// Copyright (C) 2018-2018 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------

// ips_context_data.cc author Russ Combs <rucombs@cisco.com>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "ips_context_data.h"

#include <cassert>
#include "detection/ips_context.h"

#ifdef UNIT_TEST
#include "catch/snort_catch.h"
#endif

using namespace snort;

//--------------------------------------------------------------------------
// context data
//--------------------------------------------------------------------------

// ips_id is not a member of context data so that
// tests (and only tests) can reset the id
static unsigned ips_id = 0;
static unsigned max_id = IpsContext::max_ips_id;

unsigned IpsContextData::get_ips_id()
{ 
    ++ips_id;
    assert( ips_id < max_id );
    return ips_id; 
}

//--------------------------------------------------------------------------
// unit tests
//--------------------------------------------------------------------------

#ifdef UNIT_TEST

TEST_CASE("IpsContextData id", "[IpsContextData]")
{
    ips_id = 0;

    auto id1 = IpsContextData::get_ips_id();
    auto id2 = IpsContextData::get_ips_id();
    CHECK(id1 != id2);

    CHECK(max_id > id2 );
}

#endif
