//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "numeric_dst_concrete.hpp"
#include "catch.hpp"
#include <deque>

TEST_CASE("numeric, dst is a concrete type")
{
    using namespace terse;
    using namespace std;
    using DI = deque<int>;

    REQUIRE((DI{ 1, 2, 3 }  == dst_concrete::adjacent_difference<DI>(DI{ 1, 3, 6 })));
    REQUIRE((DI{ 1, 2, 3 }  == dst_concrete::adjacent_difference<DI>(  { 1, 3, 6 })));
    REQUIRE((DI{ 1, 4, 9 }  == dst_concrete::adjacent_difference<DI>(DI{ 1, 3, 6 }, plus<int>())));
    REQUIRE((DI{ 1, 4, 9 }  == dst_concrete::adjacent_difference<DI>(  { 1, 3, 6 }, plus<int>())));
    REQUIRE((DI{ 1, 2, 3 }  == dst_concrete::partial_sum        <DI>(DI{ 1, 1, 1 })));
    REQUIRE((DI{ 1, 2, 3 }  == dst_concrete::partial_sum        <DI>(  { 1, 1, 1 })));
    REQUIRE((DI{ 1, 0, -1 } == dst_concrete::partial_sum        <DI>(DI{ 1, 1, 1 }, minus<int>())));
    REQUIRE((DI{ 1, 0, -1 } == dst_concrete::partial_sum        <DI>(  { 1, 1, 1 }, minus<int>())));
}
