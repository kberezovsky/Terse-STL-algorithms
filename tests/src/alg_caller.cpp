//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "algorithm_dst_concrete.hpp"
#include "catch.hpp"
#include <array>
#include <deque>
#include <set>

TEST_CASE("alg_caller")
{
    using namespace terse;
    using namespace std;
    using DI = deque<int>;
    using SI = set<int>;
    using AI1 = array<int, 1>;
    using AI2 = array<int, 2>;
    using AI3 = array<int, 3>;

    SECTION("copy")
    {
        REQUIRE((DI { 1, 2, 3 } == dst_concrete::copy<DI >({ 1, 2, 3 })));
        REQUIRE((AI3{ 1, 2, 3 } == dst_concrete::copy<AI3>({ 1, 2, 3 })));
    }

    SECTION("partition_copy 1")
    {
        const pair<DI, SI> res{ { 1, 2 }, { 3 } };
        REQUIRE((res == dst_concrete::partition_copy<DI, SI  >({ 1, 3, 2 }, [](int i){ return i < 3; })));
    }

    SECTION("partition_copy 2")
    {
        const pair<DI, AI1> res{ { 1, 2 }, { 3 } };
        REQUIRE((res == dst_concrete::partition_copy<DI, AI1 >({ 1, 3, 2 }, [](int i){ return i < 3; })));
    }

    SECTION("partition_copy 3")
    {
        const pair<AI2, SI> res{ { 1, 2 }, { 3 } };
        REQUIRE((res == dst_concrete::partition_copy<AI2, SI >({ 1, 3, 2 }, [](int i){ return i < 3; })));
    }

    SECTION("partition_copy 4")
    {
        const pair<AI2, AI1> res{ { 1, 2 }, { 3 } };
        REQUIRE((res == dst_concrete::partition_copy<AI2, AI1>({ 1, 3, 2 }, [](int i){ return i < 3; })));
    }
}
