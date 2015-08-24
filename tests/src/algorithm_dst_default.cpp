//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "algorithm_dst_default.hpp"
#include "catch.hpp"
#include <memory>

TEST_CASE("algorithms, dst is a default container")
{
    using namespace terse;
    using namespace std;
    using VI = vector<int>;

    REQUIRE((VI{ 1, 2, 3 } == dst_default::copy                    (VI{ 1, 2, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::copy                    (  { 1, 2, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::copy_if                 (VI{ 4, 1, 2, 3 }, [](int i){ return i < 4; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::copy_if                 (  { 4, 1, 2, 3 }, [](int i){ return i < 4; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::copy_n                  (VI{ 1, 2, 3, 4 }, 3)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::copy_n                  (  { 1, 2, 3, 4 }, 3)));
    REQUIRE((VI{ 4, 4, 4 } == dst_default::fill_n                  (3, 4)));
    REQUIRE((VI{ 4, 4, 4 } == dst_default::generate_n              (3, []{ return 4; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::merge                   (VI{ 1, 3 }, VI{ 2 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::merge                   (VI{ 1, 3 },   { 2 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::merge                   (  { 1, 3 }, VI{ 2 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::merge                   (  { 1, 3 },   { 2 })));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::merge                   (VI{ 3, 1 }, VI{ 2 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::merge                   (VI{ 3, 1 },   { 2 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::merge                   (  { 3, 1 }, VI{ 2 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::merge                   (  { 3, 1 },   { 2 }, greater<int>())));

    SECTION("move")
    {
        using VUPI = vector<unique_ptr<int>>;
        VUPI vupi;
        vupi.push_back(make_unique<int>(1));
        REQUIRE((1         == *dst_default::move                   (vupi).front().get()));
        vupi[0] = make_unique<int>(1);
        REQUIRE((1         == *dst_default::move                   (std::move(vupi)).front().get()));
    }

    SECTION("partition_copy")
    {
        const pair<VI, VI> res{ { 1, 2 }, { 3 } };
        REQUIRE((res       == dst_default::partition_copy          (VI{ 1, 3, 2 }, [](int i){ return i < 3; })));
        REQUIRE((res       == dst_default::partition_copy          (  { 1, 3, 2 }, [](int i){ return i < 3; })));
    }

    REQUIRE((VI{ 1, 2, 3 } == dst_default::remove_copy             (VI{ 4, 1, 2, 3 }, 4)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::remove_copy             (  { 4, 1, 2, 3 }, 4)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::remove_copy_if          (VI{ 4, 1, 2, 3 }, [](int i){ return i >= 4; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::remove_copy_if          (  { 4, 1, 2, 3 }, [](int i){ return i >= 4; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::replace_copy            (VI{ 0, 2, 3 }, 0, 1)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::replace_copy            (  { 0, 2, 3 }, 0, 1)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::replace_copy_if         (VI{ 0, 2, 3 }, [](int i){ return i == 0; }, 1)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::replace_copy_if         (  { 0, 2, 3 }, [](int i){ return i == 0; }, 1)));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::reverse_copy            (VI{ 3, 2, 1 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::reverse_copy            (  { 3, 2, 1 })));

    SECTION("rotate_copy")
    {
        const VI vi_312{ 3, 1, 2 };
        const auto iter_to_1 = find(vi_312.begin(), vi_312.end(), 1);
        const VI vi_123{ 1, 2, 3 };
        REQUIRE((vi_123    == dst_default::rotate_copy             (vi_312, iter_to_1)));
    }

    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_difference          (VI{ 1, 2, 3, 4 }, VI{ 4 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_difference          (VI{ 1, 2, 3, 4 },   { 4 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_difference          (  { 1, 2, 3, 4 }, VI{ 4 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_difference          (  { 1, 2, 3, 4 },   { 4 })));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_difference          (VI{ 3, 2, 1, 0 }, VI{ 0 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_difference          (VI{ 3, 2, 1, 0 },   { 0 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_difference          (  { 3, 2, 1, 0 }, VI{ 0 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_difference          (  { 3, 2, 1, 0 },   { 0 }, greater<int>())));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_intersection        (VI{ 0, 1, 2, 3, 4 }, VI{ -1, 1, 2, 3, 5 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_intersection        (VI{ 0, 1, 2, 3, 4 },   { -1, 1, 2, 3, 5 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_intersection        (  { 0, 1, 2, 3, 4 }, VI{ -1, 1, 2, 3, 5 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_intersection        (  { 0, 1, 2, 3, 4 },   { -1, 1, 2, 3, 5 })));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_intersection        (VI{ 4, 3, 2, 1, 0 }, VI{ 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_intersection        (VI{ 4, 3, 2, 1, 0 },   { 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_intersection        (  { 4, 3, 2, 1, 0 }, VI{ 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_intersection        (  { 4, 3, 2, 1, 0 },   { 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_symmetric_difference(VI{ 1, 3, 4 }, VI{ 2, 4 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_symmetric_difference(VI{ 1, 3, 4 },   { 2, 4 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_symmetric_difference(  { 1, 3, 4 }, VI{ 2, 4 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_symmetric_difference(  { 1, 3, 4 },   { 2, 4 })));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_symmetric_difference(VI{ 3, 1, 0 }, VI{ 2, 0 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_symmetric_difference(VI{ 3, 1, 0 },   { 2, 0 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_symmetric_difference(  { 3, 1, 0 }, VI{ 2, 0 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_symmetric_difference(  { 3, 1, 0 },   { 2, 0 }, greater<int>())));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_union               (VI{ 1, 2 }, VI{ 2, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_union               (VI{ 1, 2 },   { 2, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_union               (  { 1, 2 }, VI{ 2, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::set_union               (  { 1, 2 },   { 2, 3 })));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_union               (VI{ 2, 1 }, VI{ 3, 2 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_union               (VI{ 2, 1 },   { 3, 2 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_union               (  { 2, 1 }, VI{ 3, 2 }, greater<int>())));
    REQUIRE((VI{ 3, 2, 1 } == dst_default::set_union               (  { 2, 1 },   { 3, 2 }, greater<int>())));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::transform               (VI{ 0, 1, 2 }, [](int& i){ return i + 1; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::transform               (  { 0, 1, 2 }, [](int i){ return i + 1; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::transform               (VI{ 3, 7, 3 }, VI{ 2, 5, 0 },
        [](int& a, int& b){ return a-b; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::transform               (VI{ 3, 7, 3 },   { 2, 5, 0 },
        [](int& a, int b){ return a-b; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::transform               (  { 3, 7, 3 }, VI{ 2, 5, 0 },
        [](int a, int& b){ return a-b; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::transform               (  { 3, 7, 3 },   { 2, 5, 0 }, minus<int>())));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::unique_copy             (VI{ 1, 2, 3, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::unique_copy             (  { 1, 2, 3, 3 })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::unique_copy             (VI{ 1, 2, 3, 4 },
        [](int a, int b){ return a==3 && b==4; })));
    REQUIRE((VI{ 1, 2, 3 } == dst_default::unique_copy             (  { 1, 2, 3, 4 },
        [](int a, int b){ return a==3 && b==4; })));
}
