//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include "dst_default.hpp"
#include "test_types.hpp"
#include <deque>
#include <set>

namespace terse
{
namespace tests
{
using namespace std;
using namespace detail;

namespace testDstContFromDefaultDstElem
{
template<class DstElem, class DstCont> void test()
{
    static_assert(is_same<DstContFromDefaultDstElem_t<DstElem>, DstCont>::value, "");
}
using namespace test_types;
void testDefaultType()
{
    test<Elem    , vector<Elem>>();
    test<char    , string>();
    test<wchar_t , wstring>();
    test<char16_t, u16string>();
    test<char32_t, u32string>();
}
void testDstElemConv()
{
    test<const volatile Elem&   , vector<Elem>>();
    test<Elem*                  , vector<Elem*>>();
    test<reference_wrapper<Elem>, vector<reference_wrapper<Elem>>>();
}
void testUsings()
{
    static_assert(is_same<DstContFromDefaultDstElem_t<Elem>, vector<Elem>>::value, "");
    static_assert(is_same<DstContFromDefaultSrcRng_t<set<Elem>>, vector<Elem>>::value, "");
    static_assert(is_same<DstContFromDefaultSrcElem_t<Elem>, vector<Elem>>::value, "");
    static_assert(is_same<DstContFromDefaultNullaryOp_t<Elem(*)()>, vector<Elem>>::value, "");
    static_assert(is_same<DstContFromDefaultUnaryOpSrcRng_t<
        DstElem(*)(SrcElem), set<SrcElem>>, vector<DstElem>>::value, "");
    static_assert(is_same<DstContFromDefaultUnaryOpSrcElem_t<
        DstElem(*)(SrcElem), SrcElem>, vector<DstElem>>::value, "");
    static_assert(is_same<DstContFromDefaultBinaryOpSrcRng1SrcRng2_t<
        DstElem(*)(SrcElem1, SrcElem2), set<SrcElem1>, deque<SrcElem2>>, vector<DstElem>>::value, "");
    static_assert(is_same<DstContFromDefaultBinaryOpSrcRng1SrcElem2_t<
        DstElem(*)(SrcElem1, SrcElem2), set<SrcElem1>, SrcElem2>, vector<DstElem>>::value, "");
    static_assert(is_same<DstContFromDefaultBinaryOpSrcElem1SrcRng2_t<
        DstElem(*)(SrcElem1, SrcElem2), SrcElem1, deque<SrcElem2>>, vector<DstElem>>::value, "");
    static_assert(is_same<DstContFromDefaultBinaryOpSrcElem1SrcElem2_t<
        DstElem(*)(SrcElem1, SrcElem2), SrcElem1, SrcElem2>, vector<DstElem>>::value, "");
}
}//namespace testDstContFromDefaultDstElem
}//namespace tests
}//namespace terse
