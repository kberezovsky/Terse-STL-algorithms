//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "methods.hpp"
#include "catch.hpp"
#include <list>
#include <vector>

TEST_CASE("methods")
{
    using namespace terse::detail;
    using namespace std;

    SECTION("reserve")
    {
        list<int> a;
        vector<int> b;
        Methods::reserve(a, 1);
        Methods::reserve(b, 1);
        REQUIRE((1==b.capacity()));
    }

    SECTION("size")
    {
        int a;
        int b[1];
        vector<int> c{ 1 };
        REQUIRE((0==Methods::size(a)));
        REQUIRE((1==Methods::size(b)));
        REQUIRE((1==Methods::size(c)));
    }
}
