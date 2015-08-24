//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "numeric_dst_template.hpp"
#include "catch.hpp"
#include <deque>

TEST_CASE("numeric, dst is based on the template template parameter")
{
    using namespace terse;
    using namespace std;
    using DI = deque<int>;

    REQUIRE((DI{ 1, 2, 3 }  == dst_template::adjacent_difference<deque>(DI{ 1, 3, 6 })));
    REQUIRE((DI{ 1, 2, 3 }  == dst_template::adjacent_difference<deque>(  { 1, 3, 6 })));
    REQUIRE((DI{ 1, 4, 9 }  == dst_template::adjacent_difference<deque>(DI{ 1, 3, 6 }, plus<int>())));
    REQUIRE((DI{ 1, 4, 9 }  == dst_template::adjacent_difference<deque>(  { 1, 3, 6 }, plus<int>())));
    REQUIRE((DI{ 1, 2, 3 }  == dst_template::partial_sum        <deque>(DI{ 1, 1, 1 })));
    REQUIRE((DI{ 1, 2, 3 }  == dst_template::partial_sum        <deque>(  { 1, 1, 1 })));
    REQUIRE((DI{ 1, 0, -1 } == dst_template::partial_sum        <deque>(DI{ 1, 1, 1 }, minus<int>())));
    REQUIRE((DI{ 1, 0, -1 } == dst_template::partial_sum        <deque>(  { 1, 1, 1 }, minus<int>())));
}
