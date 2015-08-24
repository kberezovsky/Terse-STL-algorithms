//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//#include <boost/container/map.hpp>
//#include <boost/container/flat_map.hpp>
//#include <boost/unordered/unordered_map.hpp>
//#include <sparsehash/dense_hash_map>
//#include <sparsehash/sparse_hash_map>

#include "dst_template.hpp"

#include "test_types.hpp"
#include <deque>
#include <forward_list>
#include <functional>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace terse
{
namespace tests
{
using namespace std;
using namespace detail;

namespace testDstContFromDstTemplDstElem
{
template<template<class...> class DstTempl, class DstElem, class DstCont> void test()
{
    static_assert(is_same<DstContFromDstTemplDstElem_t<DstTempl, DstElem>, DstCont>::value, "");
}
using namespace test_types;
void testDstTemplType()
{
    //T[] can't be returned
    test<set               , Elem            , set               <Elem>>();
    test<list              , Elem            , list              <Elem>>();
    //std::array can be used in dst_concrete only
    test<deque             , Elem            , deque             <Elem>>();
    test<queue             , Elem            , queue             <Elem>>();
    test<stack             , Elem            , stack             <Elem>>();
    test<vector            , Elem            , vector            <Elem>>();
    test<multiset          , Elem            , multiset          <Elem>>();
    test<basic_string      , Elem            , basic_string      <Elem>>();
    test<forward_list      , Elem            , forward_list      <Elem>>();
    test<unordered_set     , Elem            , unordered_set     <Elem>>();
    test<priority_queue    , Elem            , priority_queue    <Elem>>();
    test<unordered_multiset, Elem            , unordered_multiset<Elem>>();
    test<map               , pair<Key, Value>, map               <Key, Value>>();
    test<multimap          , pair<Key, Value>, multimap          <Key, Value>>();
    test<unordered_map     , pair<Key, Value>, unordered_map     <Key, Value>>();
    test<unordered_multimap, pair<Key, Value>, unordered_multimap<Key, Value>>();
#ifdef BOOST_CONTAINER_MAP_HPP
    test<boost::container::map     , pair<Key, Value>, boost::container::map     <Key, Value>>();
    test<boost::container::multimap, pair<Key, Value>, boost::container::multimap<Key, Value>>();
#endif
#ifdef BOOST_CONTAINER_FLAT_MAP_HPP
    test<boost::container::flat_map     , pair<Key, Value>, boost::container::flat_map     <Key, Value>>();
    test<boost::container::flat_multimap, pair<Key, Value>, boost::container::flat_multimap<Key, Value>>();
#endif
#ifdef BOOST_UNORDERED_UNORDERED_MAP_HPP_INCLUDED
    test<boost::unordered::unordered_map     , pair<Key, Value>, boost::unordered::unordered_map     <Key, Value>>();
    test<boost::unordered::unordered_multimap, pair<Key, Value>, boost::unordered::unordered_multimap<Key, Value>>();
#endif
#ifdef _DENSE_HASH_MAP_H_
    test<google::dense_hash_map, pair<Key, Value>, google::dense_hash_map<Key, Value>>();
#endif
#ifdef _SPARSE_HASH_MAP_H_
    test<google::sparse_hash_map, pair<Key, Value>, google::sparse_hash_map<Key, Value>>();
#endif
}
void testDstElemConv()
{
    test<set, const volatile Elem&   , set<Elem>>();
    test<set, Elem*                  , set<Elem*>>();
    test<set, reference_wrapper<Elem>, set<reference_wrapper<Elem>>>();
}
void testUsings()
{
    static_assert(is_same<DstContFromDstTemplDstElem_t<set, Elem>, set<Elem>>::value, "");
    static_assert(is_same<DstContFromDstTemplSrcRng_t<set, vector<Elem>>, set<Elem>>::value, "");
    static_assert(is_same<DstContFromDstTemplSrcElem_t<set, Elem>, set<Elem>>::value, "");
    static_assert(is_same<DstContFromDstTemplNullaryOp_t<set, Elem(*)()>, set<Elem>>::value, "");
    static_assert(is_same<DstContFromDstTemplUnaryOpSrcRng_t<set,
        DstElem(*)(SrcElem), vector<SrcElem>>, set<DstElem>>::value, "");
    static_assert(is_same<DstContFromDstTemplUnaryOpSrcElem_t<set,
        DstElem(*)(SrcElem), SrcElem>, set<DstElem>>::value, "");
    static_assert(is_same<DstContFromDstTemplBinaryOpSrcRng1SrcRng2_t<set,
        DstElem(*)(SrcElem1, SrcElem2), vector<SrcElem1>, deque<SrcElem2>>, set<DstElem>>::value, "");
    static_assert(is_same<DstContFromDstTemplBinaryOpSrcRng1SrcElem2_t<set,
        DstElem(*)(SrcElem1, SrcElem2), vector<SrcElem1>, SrcElem2>, set<DstElem>>::value, "");
    static_assert(is_same<DstContFromDstTemplBinaryOpSrcElem1SrcRng2_t<set,
        DstElem(*)(SrcElem1, SrcElem2), SrcElem1, deque<SrcElem2>>, set<DstElem>>::value, "");
    static_assert(is_same<DstContFromDstTemplBinaryOpSrcElem1SrcElem2_t<set,
        DstElem(*)(SrcElem1, SrcElem2), SrcElem1, SrcElem2>, set<DstElem>>::value, "");
}
}//namespace testDstContFromDstTemplDstElem
}//namespace tests
}//namespace terse
