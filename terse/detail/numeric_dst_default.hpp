//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_NUMERIC_DST_DEFAULT_HPP
#define TERSE_DETAIL_NUMERIC_DST_DEFAULT_HPP

#include "dst_default.hpp"
#include "numeric_dst_concrete.hpp"

namespace terse
{
namespace dst_default
{
template<class SrcRng>
    auto adjacent_difference(const SrcRng& srcRng)
        { return dst_concrete::adjacent_difference<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng); }
template<class SrcElem>
    auto adjacent_difference(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::adjacent_difference<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng); }
template<class SrcRng, class BinaryOp>
    auto adjacent_difference(const SrcRng& srcRng, BinaryOp binaryOp)
        { return dst_concrete::adjacent_difference<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, binaryOp); }
template<class SrcElem, class BinaryOp>
    auto adjacent_difference(const std::initializer_list<SrcElem>& srcRng, BinaryOp binaryOp)
        { return dst_concrete::adjacent_difference<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, binaryOp); }
template<class SrcRng>
    auto partial_sum(const SrcRng& srcRng)
        { return dst_concrete::partial_sum<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng); }
template<class SrcElem>
    auto partial_sum(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::partial_sum<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng); }
template<class SrcRng, class BinaryOp>
    auto partial_sum(const SrcRng& srcRng, BinaryOp binaryOp)
        { return dst_concrete::partial_sum<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, binaryOp); }
template<class SrcElem, class BinaryOp>
    auto partial_sum(const std::initializer_list<SrcElem>& srcRng, BinaryOp binaryOp)
        { return dst_concrete::partial_sum<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, binaryOp); }
}//namespace dst_default
}//namespace terse

#endif
