//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_DST_DEFAULT_HPP
#define TERSE_DETAIL_DST_DEFAULT_HPP

#include "dst_elem.hpp"
#include "type_conv.hpp"
#include <string>
#include <vector>

namespace terse
{
namespace detail
{
template<class DstElem> struct DstContFromDefaultDstElemImpl          { using type = std::vector<DstElem>; };
template<>              struct DstContFromDefaultDstElemImpl<char>    { using type = std::string; };
template<>              struct DstContFromDefaultDstElemImpl<wchar_t> { using type = std::wstring; };
template<>              struct DstContFromDefaultDstElemImpl<char16_t>{ using type = std::u16string; };
template<>              struct DstContFromDefaultDstElemImpl<char32_t>{ using type = std::u32string; };

template<class DstElem>
class DstContFromDefaultDstElem
{
public:
    using type = typename DstContFromDefaultDstElemImpl<remove_cv_reference_t<DstElem>>::type;
};

template<class DstElem>
    using DstContFromDefaultDstElem_t =
        typename DstContFromDefaultDstElem<DstElem>::type;
template<class SrcRng>
    using DstContFromDefaultSrcRng_t =
        DstContFromDefaultDstElem_t<DstElemFromSrcRng_t<SrcRng>>;
template<class SrcElem>
    using DstContFromDefaultSrcElem_t =
        DstContFromDefaultDstElem_t<SrcElem>;
template<class NullaryOp>
    using DstContFromDefaultNullaryOp_t =
        DstContFromDefaultDstElem_t<DstElemFromNullaryOp_t<NullaryOp>>;
template<class UnaryOp, class SrcRng>
    using DstContFromDefaultUnaryOpSrcRng_t =
        DstContFromDefaultDstElem_t<DstElemFromUnaryOpSrcRng_t<UnaryOp, SrcRng>>;
template<class UnaryOp, class SrcElem>
    using DstContFromDefaultUnaryOpSrcElem_t =
        DstContFromDefaultDstElem_t<DstElemFromUnaryOpSrcElem_t<UnaryOp, SrcElem>>;
template<class BinaryOp, class SrcRng1, class SrcRng2>
    using DstContFromDefaultBinaryOpSrcRng1SrcRng2_t =
        DstContFromDefaultDstElem_t<DstElemFromBinaryOpSrcRng1SrcRng2_t<BinaryOp, SrcRng1, SrcRng2>>;
template<class BinaryOp, class SrcRng1, class SrcElem2>
    using DstContFromDefaultBinaryOpSrcRng1SrcElem2_t =
        DstContFromDefaultDstElem_t<DstElemFromBinaryOpSrcRng1SrcElem2_t<BinaryOp, SrcRng1, SrcElem2>>;
template<class BinaryOp, class SrcElem1, class SrcRng2>
    using DstContFromDefaultBinaryOpSrcElem1SrcRng2_t =
        DstContFromDefaultDstElem_t<DstElemFromBinaryOpSrcElem1SrcRng2_t<BinaryOp, SrcElem1, SrcRng2>>;
template<class BinaryOp, class SrcElem1, class SrcElem2>
    using DstContFromDefaultBinaryOpSrcElem1SrcElem2_t =
        DstContFromDefaultDstElem_t<DstElemFromBinaryOpSrcElem1SrcElem2_t<BinaryOp, SrcElem1, SrcElem2>>;
}//namespace detail
}//namespace terse

#endif
