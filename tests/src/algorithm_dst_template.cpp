//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "algorithm_dst_template.hpp"
#include "catch.hpp"
#include <deque>
#include <memory>
#include <set>

TEST_CASE("algorithms, dst is based on the template template parameter")
{
    using namespace terse;
    using namespace std;
    using DI = deque<int>;

    REQUIRE((DI{ 1, 2, 3 } == dst_template::copy                    <deque>(DI{ 1, 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::copy                    <deque>(  { 1, 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::copy_if                 <deque>(DI{ 4, 1, 2, 3 }, [](int i){ return i < 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::copy_if                 <deque>(  { 4, 1, 2, 3 }, [](int i){ return i < 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::copy_n                  <deque>(DI{ 1, 2, 3, 4 }, 3)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::copy_n                  <deque>(  { 1, 2, 3, 4 }, 3)));
    REQUIRE((DI{ 4, 4, 4 } == dst_template::fill_n                  <deque>(3, 4)));
    REQUIRE((DI{ 4, 4, 4 } == dst_template::generate_n              <deque>(3, []{ return 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::merge                   <deque>(DI{ 1, 3 }, DI{ 2 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::merge                   <deque>(DI{ 1, 3 },   { 2 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::merge                   <deque>(  { 1, 3 }, DI{ 2 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::merge                   <deque>(  { 1, 3 },   { 2 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::merge                   <deque>(DI{ 3, 1 }, DI{ 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::merge                   <deque>(DI{ 3, 1 },   { 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::merge                   <deque>(  { 3, 1 }, DI{ 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::merge                   <deque>(  { 3, 1 },   { 2 }, greater<int>())));

    SECTION("move")
    {
        using DUPI = deque<unique_ptr<int>>;
        DUPI dupi;
        dupi.push_back(make_unique<int>(1));
        REQUIRE((1         == *dst_template::move                   <deque>(dupi).front().get()));
        dupi[0] = make_unique<int>(1);
        REQUIRE((1         == *dst_template::move                   <deque>(std::move(dupi)).front().get()));
    }

    SECTION("partition_copy")
    {
        using SI = set<int>;
        const pair<DI, SI> res{ { 1, 2 }, { 3 } };
        REQUIRE((res       == dst_template::partition_copy          <deque, set>(DI{ 1, 3, 2 },
            [](int i){ return i < 3; })));
        REQUIRE((res       == dst_template::partition_copy          <deque, set>(  { 1, 3, 2 },
            [](int i){ return i < 3; })));
    }

    REQUIRE((DI{ 1, 2, 3 } == dst_template::remove_copy             <deque>(DI{ 4, 1, 2, 3 }, 4)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::remove_copy             <deque>(  { 4, 1, 2, 3 }, 4)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::remove_copy_if          <deque>(DI{ 4, 1, 2, 3 },
        [](int i){ return i >= 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::remove_copy_if          <deque>(  { 4, 1, 2, 3 },
        [](int i){ return i >= 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::replace_copy            <deque>(DI{ 0, 2, 3 }, 0, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::replace_copy            <deque>(  { 0, 2, 3 }, 0, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::replace_copy_if         <deque>(DI{ 0, 2, 3 },
        [](int i){ return i == 0; }, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::replace_copy_if         <deque>(  { 0, 2, 3 },
        [](int i){ return i == 0; }, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::reverse_copy            <deque>(DI{ 3, 2, 1 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::reverse_copy            <deque>(  { 3, 2, 1 })));

    SECTION("rotate_copy")
    {
        const DI vi_312{ 3, 1, 2 };
        const auto iter_to_1 = find(vi_312.begin(), vi_312.end(), 1);
        const DI vi_123{ 1, 2, 3 };
        REQUIRE((vi_123    == dst_template::rotate_copy             <deque>(vi_312, iter_to_1)));
    }

    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_difference          <deque>(DI{ 1, 2, 3, 4 }, DI{ 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_difference          <deque>(DI{ 1, 2, 3, 4 },   { 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_difference          <deque>(  { 1, 2, 3, 4 }, DI{ 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_difference          <deque>(  { 1, 2, 3, 4 },   { 4 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_difference          <deque>(DI{ 3, 2, 1, 0 }, DI{ 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_difference          <deque>(DI{ 3, 2, 1, 0 },   { 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_difference          <deque>(  { 3, 2, 1, 0 }, DI{ 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_difference          <deque>(  { 3, 2, 1, 0 },   { 0 }, greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_intersection        <deque>(DI{ 0, 1, 2, 3, 4 }, DI{ -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_intersection        <deque>(DI{ 0, 1, 2, 3, 4 },   { -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_intersection        <deque>(  { 0, 1, 2, 3, 4 }, DI{ -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_intersection        <deque>(  { 0, 1, 2, 3, 4 },   { -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_intersection        <deque>(DI{ 4, 3, 2, 1, 0 }, DI{ 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_intersection        <deque>(DI{ 4, 3, 2, 1, 0 },   { 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_intersection        <deque>(  { 4, 3, 2, 1, 0 }, DI{ 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_intersection        <deque>(  { 4, 3, 2, 1, 0 },   { 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_symmetric_difference<deque>(DI{ 1, 3, 4 }, DI{ 2, 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_symmetric_difference<deque>(DI{ 1, 3, 4 },   { 2, 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_symmetric_difference<deque>(  { 1, 3, 4 }, DI{ 2, 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_symmetric_difference<deque>(  { 1, 3, 4 },   { 2, 4 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_symmetric_difference<deque>(DI{ 3, 1, 0 }, DI{ 2, 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_symmetric_difference<deque>(DI{ 3, 1, 0 },   { 2, 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_symmetric_difference<deque>(  { 3, 1, 0 }, DI{ 2, 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_symmetric_difference<deque>(  { 3, 1, 0 },   { 2, 0 }, greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_union               <deque>(DI{ 1, 2 }, DI{ 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_union               <deque>(DI{ 1, 2 },   { 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_union               <deque>(  { 1, 2 }, DI{ 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::set_union               <deque>(  { 1, 2 },   { 2, 3 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_union               <deque>(DI{ 2, 1 }, DI{ 3, 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_union               <deque>(DI{ 2, 1 },   { 3, 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_union               <deque>(  { 2, 1 }, DI{ 3, 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_template::set_union               <deque>(  { 2, 1 },   { 3, 2 }, greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::transform               <deque>(DI{ 0, 1, 2 }, [](int& i){ return i + 1; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::transform               <deque>(  { 0, 1, 2 }, [](int i){ return i + 1; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::transform               <deque>(DI{ 3, 7, 3 }, DI{ 2, 5, 0 },
        [](int& a, int& b){ return a-b; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::transform               <deque>(DI{ 3, 7, 3 },   { 2, 5, 0 },
        [](int& a, int b){ return a-b; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::transform               <deque>(  { 3, 7, 3 }, DI{ 2, 5, 0 },
        [](int a, int& b){ return a-b; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::transform               <deque>(  { 3, 7, 3 },   { 2, 5, 0 }, minus<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::unique_copy             <deque>(DI{ 1, 2, 3, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::unique_copy             <deque>(  { 1, 2, 3, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::unique_copy             <deque>(DI{ 1, 2, 3, 4 },
        [](int a, int b){ return a==3 && b==4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_template::unique_copy             <deque>(  { 1, 2, 3, 4 },
        [](int a, int b){ return a==3 && b==4; })));
}
