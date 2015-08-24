//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "dst_elem.hpp"
#include "test_types.hpp"
#include <array>
#include <deque>
#include <forward_list>
#include <functional>
#include <list>
#include <map>
#include <set>
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

namespace testDstElemFromSrcRng
{
template<class SrcRng, class DstElem> void test()
{
    static_assert(is_same<DstElemFromSrcRng_t<SrcRng>, DstElem>::value, "");
}
using namespace test_types;
void testSrcRngType()
{
    test<                   Elem[1]    , Elem>();
    test<set               <Elem>      , Elem>();
    test<list              <Elem>      , Elem>();
    test<array             <Elem, 1>   , Elem>();
    test<deque             <Elem>      , Elem>();
    //queue is not a range
    //stack is not a range
    test<vector            <Elem>      , Elem>();
    test<multiset          <Elem>      , Elem>();
    test<basic_string      <Elem>      , Elem>();
    test<forward_list      <Elem>      , Elem>();
    test<unordered_set     <Elem>      , Elem>();
    //priority_queue is not a range
    test<unordered_multiset<Elem>      , Elem>();
    test<map               <Key, Value>, pair<const Key, Value>>();
    test<multimap          <Key, Value>, pair<const Key, Value>>();
    test<unordered_map     <Key, Value>, pair<const Key, Value>>();
    test<unordered_multimap<Key, Value>, pair<const Key, Value>>();
}
void testDstElemConv()
{
    test<const volatile Elem[1]         , Elem>();
    test<vector<Elem*>                  , Elem*>();
    test<vector<reference_wrapper<Elem>>, reference_wrapper<Elem>>();
}
}//testDstElemFromSrcRng

namespace testDstElemFromNullaryOp
{
template<class NullaryOp, class DstElem> void test()
{
    static_assert(is_same<DstElemFromNullaryOp_t<NullaryOp>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<Elem(*)()       , Elem>();
    test<function<Elem()>, Elem>();
}
void testDstElemConv()
{
    test<const volatile Elem&(*)()   , Elem>();
    test<Elem*(*)()                  , Elem*>();
    test<reference_wrapper<Elem>(*)(), reference_wrapper<Elem>>();
}
}//namespace testDstElemFromNullaryOp

namespace testDstElemFromUnaryOpSrcElem
{
template<class UnaryOp, class SrcElem, class DstElem> void test()
{
    static_assert(is_same<DstElemFromUnaryOpSrcElem_t<UnaryOp, SrcElem>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<DstElem(*)(SrcElem)       , SrcElem, DstElem>();
    test<function<DstElem(SrcElem)>, SrcElem, DstElem>();
}
void testDstElemConv()
{
    test<const volatile DstElem&(*)(SrcElem)   , SrcElem, DstElem>();
    test<DstElem*(*)(SrcElem)                  , SrcElem, DstElem*>();
    test<reference_wrapper<DstElem>(*)(SrcElem), SrcElem, reference_wrapper<DstElem>>();
}
}//namespace testDstElemFromUnaryOpSrcElem

namespace testDstElemFromUnaryOpSrcRng
{
template<class UnaryOp, class SrcRng, class DstElem> void test()
{
    static_assert(is_same<DstElemFromUnaryOpSrcRng_t<UnaryOp, SrcRng>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<DstElem(*)(SrcElem)       , SrcElem[1], DstElem>();
    test<function<DstElem(SrcElem)>, SrcElem[1], DstElem>();
}
void testSrcRngType()
{
    test<DstElem(*)(SrcElem)               ,                    SrcElem[1]       , DstElem>();
    test<DstElem(*)(SrcElem)               , set               <SrcElem>         , DstElem>();
    test<DstElem(*)(SrcElem)               , list              <SrcElem>         , DstElem>();
    test<DstElem(*)(SrcElem)               , array             <SrcElem, 1>      , DstElem>();
    test<DstElem(*)(SrcElem)               , deque             <SrcElem>         , DstElem>();
    //queue is not a range
    //stack is not a range
    test<DstElem(*)(SrcElem)               , vector            <SrcElem>         , DstElem>();
    test<DstElem(*)(SrcElem)               , multiset          <SrcElem>         , DstElem>();
    test<DstElem(*)(SrcElem)               , basic_string      <SrcElem>         , DstElem>();
    test<DstElem(*)(SrcElem)               , forward_list      <SrcElem>         , DstElem>();
    test<DstElem(*)(SrcElem)               , unordered_set     <SrcElem>         , DstElem>();
    //priority_queue is not a range
    test<DstElem(*)(SrcElem)               , unordered_multiset<SrcElem>         , DstElem>();
    test<DstElem(*)(pair<SrcKey, SrcValue>), map               <SrcKey, SrcValue>, DstElem>();
    test<DstElem(*)(pair<SrcKey, SrcValue>), multimap          <SrcKey, SrcValue>, DstElem>();
    test<DstElem(*)(pair<SrcKey, SrcValue>), unordered_map     <SrcKey, SrcValue>, DstElem>();
    test<DstElem(*)(pair<SrcKey, SrcValue>), unordered_multimap<SrcKey, SrcValue>, DstElem>();
}
void testDstElemConv()
{
    test<const volatile DstElem&(*)(SrcElem)   , SrcElem[1], DstElem>();
    test<DstElem*(*)(SrcElem)                  , SrcElem[1], DstElem*>();
    test<reference_wrapper<DstElem>(*)(SrcElem), SrcElem[1], reference_wrapper<DstElem>>();
}
}//namespace testDstElemFromUnaryOpSrcRng

namespace testDstElemFromBinaryOpSrcElem1SrcElem2
{
template<class BinaryOp, class SrcElem1, class SrcElem2, class DstElem> void test()
{
    static_assert(is_same<DstElemFromBinaryOpSrcElem1SrcElem2_t<BinaryOp, SrcElem1, SrcElem2>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<DstElem(*)(SrcElem1, SrcElem2)       , SrcElem1, SrcElem2, DstElem>();
    test<function<DstElem(SrcElem1, SrcElem2)>, SrcElem1, SrcElem2, DstElem>();
}
void testDstElemConv()
{
    test<const volatile DstElem&(*)(SrcElem1, SrcElem2)   , SrcElem1, SrcElem2, DstElem>();
    test<DstElem*(*)(SrcElem1, SrcElem2)                  , SrcElem1, SrcElem2, DstElem*>();
    test<reference_wrapper<DstElem>(*)(SrcElem1, SrcElem2), SrcElem1, SrcElem2, reference_wrapper<DstElem>>();
}
}//namespace testDstElemFromBinaryOpSrcElem1SrcElem2

namespace testDstElemFromBinaryOpSrcElem1SrcRng2
{
template<class BinaryOp, class SrcElem1, class SrcRng2, class DstElem> void test()
{
    static_assert(is_same<DstElemFromBinaryOpSrcElem1SrcRng2_t<BinaryOp, SrcElem1, SrcRng2>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<DstElem(*)(SrcElem1, SrcElem2)       , SrcElem1, SrcElem2[1], DstElem>();
    test<function<DstElem(SrcElem1, SrcElem2)>, SrcElem1, SrcElem2[1], DstElem>();
}
void testSrcRng2Type()
{
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1,                    SrcElem2[1]        , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, set               <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, list              <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, array             <SrcElem2, 1>       , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, deque             <SrcElem2>          , DstElem>();
    //queue is not a range
    //stack is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, vector            <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, multiset          <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, basic_string      <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, forward_list      <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, unordered_set     <SrcElem2>          , DstElem>();
    //priority_queue is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1, unordered_multiset<SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1, map               <SrcKey2, SrcValue2>, DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1, multimap          <SrcKey2, SrcValue2>, DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1, unordered_map     <SrcKey2, SrcValue2>, DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1, unordered_multimap<SrcKey2, SrcValue2>, DstElem>();
}
void testDstElemConv()
{
    test<const volatile DstElem&(*)(SrcElem1, SrcElem2)   , SrcElem1, SrcElem2[1], DstElem>();
    test<DstElem*(*)(SrcElem1, SrcElem2)                  , SrcElem1, SrcElem2[1], DstElem*>();
    test<reference_wrapper<DstElem>(*)(SrcElem1, SrcElem2), SrcElem1, SrcElem2[1], reference_wrapper<DstElem>>();
}
}//namespace testDstElemFromBinaryOpSrcElem1SrcRng2

namespace testDstElemFromBinaryOpSrcRng1SrcElem2
{
template<class BinaryOp, class SrcRng1, class SrcElem2, class DstElem> void test()
{
    static_assert(is_same<DstElemFromBinaryOpSrcRng1SrcElem2_t<BinaryOp, SrcRng1, SrcElem2>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<DstElem(*)(SrcElem1, SrcElem2)       , SrcElem1[1], SrcElem2, DstElem>();
    test<function<DstElem(SrcElem1, SrcElem2)>, SrcElem1[1], SrcElem2, DstElem>();
}
void testSrcRng1Type()
{
    test<DstElem(*)(SrcElem1, SrcElem2)                ,                    SrcElem1[1]        , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , set               <SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , list              <SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , array             <SrcElem1, 1>       , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , deque             <SrcElem1>          , SrcElem2, DstElem>();
    //queue is not a range
    //stack is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , vector            <SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , multiset          <SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , basic_string      <SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , forward_list      <SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , unordered_set     <SrcElem1>          , SrcElem2, DstElem>();
    //priority_queue is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , unordered_multiset<SrcElem1>          , SrcElem2, DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), map               <SrcKey1, SrcValue1>, SrcElem2, DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), multimap          <SrcKey1, SrcValue1>, SrcElem2, DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), unordered_map     <SrcKey1, SrcValue1>, SrcElem2, DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), unordered_multimap<SrcKey1, SrcValue1>, SrcElem2, DstElem>();
}
void testDstElemConv()
{
    test<const volatile DstElem&(*)(SrcElem1, SrcElem2)   , SrcElem1[1], SrcElem2, DstElem>();
    test<DstElem*(*)(SrcElem1, SrcElem2)                  , SrcElem1[1], SrcElem2, DstElem*>();
    test<reference_wrapper<DstElem>(*)(SrcElem1, SrcElem2), SrcElem1[1], SrcElem2, reference_wrapper<DstElem>>();
}
}//namespace testDstElemFromBinaryOpSrcRng1SrcElem2

namespace testDstElemFromBinaryOpSrcRng1SrcRng2
{
template<class BinaryOp, class SrcRng1, class SrcRng2, class DstElem> void test()
{
    static_assert(is_same<DstElemFromBinaryOpSrcRng1SrcRng2_t<BinaryOp, SrcRng1, SrcRng2>, DstElem>::value, "");
}
using namespace test_types;
void testOpType()
{
    test<DstElem(*)(SrcElem1, SrcElem2)       , SrcElem1[1], SrcElem2[1], DstElem>();
    test<function<DstElem(SrcElem1, SrcElem2)>, SrcElem1[1], SrcElem2[1], DstElem>();
}
void testSrcRng1Type()
{
    test<DstElem(*)(SrcElem1, SrcElem2)                ,                    SrcElem1[1]        , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , set               <SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , list              <SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , array             <SrcElem1, 1>       , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , deque             <SrcElem1>          , SrcElem2[1], DstElem>();
    //queue is not a range
    //stack is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , vector            <SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , multiset          <SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , basic_string      <SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , forward_list      <SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , unordered_set     <SrcElem1>          , SrcElem2[1], DstElem>();
    //priority_queue is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , unordered_multiset<SrcElem1>          , SrcElem2[1], DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), map               <SrcKey1, SrcValue1>, SrcElem2[1], DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), multimap          <SrcKey1, SrcValue1>, SrcElem2[1], DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), unordered_map     <SrcKey1, SrcValue1>, SrcElem2[1], DstElem>();
    test<DstElem(*)(pair<SrcKey1, SrcValue1>, SrcElem2), unordered_multimap<SrcKey1, SrcValue1>, SrcElem2[1], DstElem>();
}
void testSrcRng2Type()
{
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1],                    SrcElem2[1]        , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], set               <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], list              <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], array             <SrcElem2, 1>       , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], deque             <SrcElem2>          , DstElem>();
    //queue is not a range
    //stack is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], vector            <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], multiset          <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], basic_string      <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], forward_list      <SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], unordered_set     <SrcElem2>          , DstElem>();
    //priority_queue is not a range
    test<DstElem(*)(SrcElem1, SrcElem2)                , SrcElem1[1], unordered_multiset<SrcElem2>          , DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1[1], map               <SrcKey2, SrcValue2>, DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1[1], multimap          <SrcKey2, SrcValue2>, DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1[1], unordered_map     <SrcKey2, SrcValue2>, DstElem>();
    test<DstElem(*)(SrcElem1, pair<SrcKey2, SrcValue2>), SrcElem1[1], unordered_multimap<SrcKey2, SrcValue2>, DstElem>();
}
void testDstElemConv()
{
    test<const volatile DstElem&(*)(SrcElem1, SrcElem2)   , SrcElem1[1], SrcElem2[1], DstElem>();
    test<DstElem*(*)(SrcElem1, SrcElem2)                  , SrcElem1[1], SrcElem2[1], DstElem*>();
    test<reference_wrapper<DstElem>(*)(SrcElem1, SrcElem2), SrcElem1[1], SrcElem2[1], reference_wrapper<DstElem>>();
}
}//namespace testDstElemFromBinaryOpSrcRng1SrcRng2
}//namespace tests
}//namespace terse
