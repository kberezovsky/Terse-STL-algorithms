//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "numeric_dst_default.hpp"
#include "catch.hpp"

TEST_CASE("numeric, dst is a default container")
{
    using namespace terse;
    using namespace std;
    using VI = vector<int>;

    REQUIRE((VI{ 1, 2, 3 }  == dst_default::adjacent_difference(VI{ 1, 3, 6 })));
    REQUIRE((VI{ 1, 2, 3 }  == dst_default::adjacent_difference(  { 1, 3, 6 })));
    REQUIRE((VI{ 1, 4, 9 }  == dst_default::adjacent_difference(VI{ 1, 3, 6 }, plus<int>())));
    REQUIRE((VI{ 1, 4, 9 }  == dst_default::adjacent_difference(  { 1, 3, 6 }, plus<int>())));
    REQUIRE((VI{ 1, 2, 3 }  == dst_default::partial_sum        (VI{ 1, 1, 1 })));
    REQUIRE((VI{ 1, 2, 3 }  == dst_default::partial_sum        (  { 1, 1, 1 })));
    REQUIRE((VI{ 1, 0, -1 } == dst_default::partial_sum        (VI{ 1, 1, 1 }, minus<int>())));
    REQUIRE((VI{ 1, 0, -1 } == dst_default::partial_sum        (  { 1, 1, 1 }, minus<int>())));
}
