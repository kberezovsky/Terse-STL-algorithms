//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "src_elem.hpp"
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

namespace testSrcElemFromSrcRng
{
template<class SrcRng, class SrcElem> void test()
{
    static_assert(is_same<SrcElemFromSrcRng_t<SrcRng>, SrcElem>::value, "");
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
void testSrcRngConv()
{
    test<const volatile Elem[1]         , Elem>();
    test<vector<Elem*>                  , Elem*>();
    test<vector<reference_wrapper<Elem>>, reference_wrapper<Elem>>();
}
}//namespace testSrcElemFromSrcRng
}//namespace tests
}//namespace terse
