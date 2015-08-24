//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "algorithm_dst_concrete.hpp"
#include "catch.hpp"
#include <deque>
#include <memory>
#include <set>

TEST_CASE("algorithms, dst is a concrete type")
{
    using namespace terse;
    using namespace std;
    using DI = deque<int>;

    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::copy                    <DI>(DI{ 1, 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::copy                    <DI>(  { 1, 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::copy_if                 <DI>(DI{ 4, 1, 2, 3 }, [](int i){ return i < 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::copy_if                 <DI>(  { 4, 1, 2, 3 }, [](int i){ return i < 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::copy_n                  <DI>(DI{ 1, 2, 3, 4 }, 3)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::copy_n                  <DI>(  { 1, 2, 3, 4 }, 3)));
    REQUIRE((DI{ 4, 4, 4 } == dst_concrete::fill_n                  <DI>(3, 4)));
    REQUIRE((DI{ 4, 4, 4 } == dst_concrete::generate_n              <DI>(3, []{ return 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::merge                   <DI>(DI{ 1, 3 }, DI{ 2 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::merge                   <DI>(DI{ 1, 3 },   { 2 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::merge                   <DI>(  { 1, 3 }, DI{ 2 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::merge                   <DI>(  { 1, 3 },   { 2 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::merge                   <DI>(DI{ 3, 1 }, DI{ 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::merge                   <DI>(DI{ 3, 1 },   { 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::merge                   <DI>(  { 3, 1 }, DI{ 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::merge                   <DI>(  { 3, 1 },   { 2 }, greater<int>())));

    SECTION("move")
    {
        using DUPI = deque<unique_ptr<int>>;
        DUPI dupi;
        dupi.push_back(make_unique<int>(1));
        REQUIRE((1         == *dst_concrete::move                   <DUPI>(dupi).front().get()));
        dupi[0] = make_unique<int>(1);
        REQUIRE((1         == *dst_concrete::move                   <DUPI>(std::move(dupi)).front().get()));
    }

    SECTION("partition_copy")
    {
        using SI = set<int>;
        const pair<DI, SI> res{ { 1, 2 }, { 3 } };
        REQUIRE((res       == dst_concrete::partition_copy          <DI, SI>(DI{ 1, 3, 2 }, [](int i){ return i < 3; })));
        REQUIRE((res       == dst_concrete::partition_copy          <DI, SI>(  { 1, 3, 2 }, [](int i){ return i < 3; })));
    }

    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::remove_copy             <DI>(DI{ 4, 1, 2, 3 }, 4)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::remove_copy             <DI>(  { 4, 1, 2, 3 }, 4)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::remove_copy_if          <DI>(DI{ 4, 1, 2, 3 }, [](int i){ return i >= 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::remove_copy_if          <DI>(  { 4, 1, 2, 3 }, [](int i){ return i >= 4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::replace_copy            <DI>(DI{ 0, 2, 3 }, 0, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::replace_copy            <DI>(  { 0, 2, 3 }, 0, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::replace_copy_if         <DI>(DI{ 0, 2, 3 }, [](int i){ return i == 0; }, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::replace_copy_if         <DI>(  { 0, 2, 3 }, [](int i){ return i == 0; }, 1)));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::reverse_copy            <DI>(DI{ 3, 2, 1 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::reverse_copy            <DI>(  { 3, 2, 1 })));

    SECTION("rotate_copy")
    {
        const DI di_312{ 3, 1, 2 };
        const auto iter_to_1 = find(di_312.begin(), di_312.end(), 1);
        const DI di_123{ 1, 2, 3 };
        REQUIRE((di_123    == dst_concrete::rotate_copy             <DI>(di_312, iter_to_1)));
    }

    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_difference          <DI>(DI{ 1, 2, 3, 4 }, DI{ 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_difference          <DI>(DI{ 1, 2, 3, 4 },   { 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_difference          <DI>(  { 1, 2, 3, 4 }, DI{ 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_difference          <DI>(  { 1, 2, 3, 4 },   { 4 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_difference          <DI>(DI{ 3, 2, 1, 0 }, DI{ 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_difference          <DI>(DI{ 3, 2, 1, 0 },   { 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_difference          <DI>(  { 3, 2, 1, 0 }, DI{ 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_difference          <DI>(  { 3, 2, 1, 0 },   { 0 }, greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_intersection        <DI>(DI{ 0, 1, 2, 3, 4 }, DI{ -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_intersection        <DI>(DI{ 0, 1, 2, 3, 4 },   { -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_intersection        <DI>(  { 0, 1, 2, 3, 4 }, DI{ -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_intersection        <DI>(  { 0, 1, 2, 3, 4 },   { -1, 1, 2, 3, 5 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_intersection        <DI>(DI{ 4, 3, 2, 1, 0 }, DI{ 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_intersection        <DI>(DI{ 4, 3, 2, 1, 0 },   { 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_intersection        <DI>(  { 4, 3, 2, 1, 0 }, DI{ 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_intersection        <DI>(  { 4, 3, 2, 1, 0 },   { 5, 3, 2, 1, -1 },
        greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_symmetric_difference<DI>(DI{ 1, 3, 4 }, DI{ 2, 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_symmetric_difference<DI>(DI{ 1, 3, 4 },   { 2, 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_symmetric_difference<DI>(  { 1, 3, 4 }, DI{ 2, 4 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_symmetric_difference<DI>(  { 1, 3, 4 },   { 2, 4 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_symmetric_difference<DI>(DI{ 3, 1, 0 }, DI{ 2, 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_symmetric_difference<DI>(DI{ 3, 1, 0 },   { 2, 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_symmetric_difference<DI>(  { 3, 1, 0 }, DI{ 2, 0 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_symmetric_difference<DI>(  { 3, 1, 0 },   { 2, 0 }, greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_union               <DI>(DI{ 1, 2 }, DI{ 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_union               <DI>(DI{ 1, 2 },   { 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_union               <DI>(  { 1, 2 }, DI{ 2, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::set_union               <DI>(  { 1, 2 },   { 2, 3 })));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_union               <DI>(DI{ 2, 1 }, DI{ 3, 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_union               <DI>(DI{ 2, 1 },   { 3, 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_union               <DI>(  { 2, 1 }, DI{ 3, 2 }, greater<int>())));
    REQUIRE((DI{ 3, 2, 1 } == dst_concrete::set_union               <DI>(  { 2, 1 },   { 3, 2 }, greater<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::transform               <DI>(DI{ 0, 1, 2 }, [](int& i){ return i + 1; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::transform               <DI>(  { 0, 1, 2 }, [](int i){ return i + 1; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::transform               <DI>(DI{ 3, 7, 3 }, DI{ 2, 5, 0 },
        [](int& a, int& b){ return a-b; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::transform               <DI>(DI{ 3, 7, 3 },   { 2, 5, 0 },
        [](int& a, int b){ return a-b; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::transform               <DI>(  { 3, 7, 3 }, DI{ 2, 5, 0 },
        [](int a, int& b){ return a-b; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::transform               <DI>(  { 3, 7, 3 },   { 2, 5, 0 }, minus<int>())));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::unique_copy             <DI>(DI{ 1, 2, 3, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::unique_copy             <DI>(  { 1, 2, 3, 3 })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::unique_copy             <DI>(DI{ 1, 2, 3, 4 },
        [](int a, int b){ return a==3 && b==4; })));
    REQUIRE((DI{ 1, 2, 3 } == dst_concrete::unique_copy             <DI>(  { 1, 2, 3, 4 },
        [](int a, int b){ return a==3 && b==4; })));
}
