//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_DST_ELEM_HPP
#define TERSE_DETAIL_DST_ELEM_HPP

#include "src_elem.hpp"
#include "type_conv.hpp"

namespace terse
{
namespace detail
{
template<class SrcRng>
    using DstElemFromSrcRng_t =
        remove_cv_reference_t<SrcElemFromSrcRng_t<SrcRng>>;
template<class NullaryOp>
    using DstElemFromNullaryOp_t =
        remove_cv_reference_t<decltype(std::declval<NullaryOp>()())>;
template<class UnaryOp, class SrcElem>
    using DstElemFromUnaryOpSrcElem_t =
        remove_cv_reference_t<decltype(std::declval<UnaryOp>()(std::declval<arg_type_t<SrcElem>>()))>;
template<class UnaryOp, class SrcRng>
    using DstElemFromUnaryOpSrcRng_t =
        DstElemFromUnaryOpSrcElem_t<UnaryOp, SrcElemFromSrcRng_t<SrcRng>>;
template<class BinaryOp, class SrcElem1, class SrcElem2>
    using DstElemFromBinaryOpSrcElem1SrcElem2_t =
        remove_cv_reference_t<decltype(std::declval<BinaryOp>()(std::declval<arg_type_t<SrcElem1>>(),
                                                                std::declval<arg_type_t<SrcElem2>>()))>;
template<class BinaryOp, class SrcElem1, class SrcRng2>
    using DstElemFromBinaryOpSrcElem1SrcRng2_t =
        DstElemFromBinaryOpSrcElem1SrcElem2_t<BinaryOp, SrcElem1, SrcElemFromSrcRng_t<SrcRng2>>;
template<class BinaryOp, class SrcRng1, class SrcElem2>
    using DstElemFromBinaryOpSrcRng1SrcElem2_t =
        DstElemFromBinaryOpSrcElem1SrcElem2_t<BinaryOp, SrcElemFromSrcRng_t<SrcRng1>, SrcElem2>;
template<class BinaryOp, class SrcRng1, class SrcRng2>
    using DstElemFromBinaryOpSrcRng1SrcRng2_t =
        DstElemFromBinaryOpSrcRng1SrcElem2_t<BinaryOp, SrcRng1, SrcElemFromSrcRng_t<SrcRng2>>;
}//namespace detail
}//namespace terse

#endif
