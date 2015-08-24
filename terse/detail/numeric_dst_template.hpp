//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_NUMERIC_DST_TEMPLATE_HPP
#define TERSE_DETAIL_NUMERIC_DST_TEMPLATE_HPP

#include "dst_template.hpp"
#include "numeric_dst_concrete.hpp"

namespace terse
{
namespace dst_template
{
template<template<class...> class DstTempl, class SrcRng>
    auto adjacent_difference(const SrcRng& srcRng)
        { return dst_concrete::adjacent_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng); }
template<template<class...> class DstTempl, class SrcElem>
    auto adjacent_difference(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::adjacent_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng); }
template<template<class...> class DstTempl, class SrcRng, class BinaryOp>
    auto adjacent_difference(const SrcRng& srcRng, BinaryOp binaryOp)
        { return dst_concrete::adjacent_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>
            (srcRng, binaryOp); }
template<template<class...> class DstTempl, class SrcElem, class BinaryOp>
    auto adjacent_difference(const std::initializer_list<SrcElem>& srcRng, BinaryOp binaryOp)
        { return dst_concrete::adjacent_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>
            (srcRng, binaryOp); }
template<template<class...> class DstTempl, class SrcRng>
    auto partial_sum(const SrcRng& srcRng)
        { return dst_concrete::partial_sum<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng); }
template<template<class...> class DstTempl, class SrcElem>
    auto partial_sum(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::partial_sum<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng); }
template<template<class...> class DstTempl, class SrcRng, class BinaryOp>
    auto partial_sum(const SrcRng& srcRng, BinaryOp binaryOp)
        { return dst_concrete::partial_sum<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, binaryOp); }
template<template<class...> class DstTempl, class SrcElem, class BinaryOp>
    auto partial_sum(const std::initializer_list<SrcElem>& srcRng, BinaryOp binaryOp)
        { return dst_concrete::partial_sum<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng, binaryOp); }
}//namespace dst_template
}//namespace terse

#endif
