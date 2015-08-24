//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_ALGORITHM_DST_TEMPLATE_HPP
#define TERSE_DETAIL_ALGORITHM_DST_TEMPLATE_HPP

#include "algorithm_dst_concrete.hpp"
#include "dst_template.hpp"

namespace terse
{
namespace dst_template
{
template<template<class...> class DstTempl, class SrcRng>
    auto copy(const SrcRng& srcRng)
        { return dst_concrete::copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng); }
template<template<class...> class DstTempl, class SrcElem>
    auto copy(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::copy<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng); }
template<template<class...> class DstTempl, class SrcRng, class UnaryPred>
    auto copy_if(const SrcRng& srcRng, UnaryPred unaryPred)
        { return dst_concrete::copy_if<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, unaryPred); }
template<template<class...> class DstTempl, class SrcElem, class UnaryPred>
    auto copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return dst_concrete::copy_if<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng, unaryPred); }
template<template<class...> class DstTempl, class SrcRng, class Size>
    auto copy_n(const SrcRng& srcRng, Size n)
        { return dst_concrete::copy_n<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, n); }
template<template<class...> class DstTempl, class SrcElem, class Size>
    auto copy_n(const std::initializer_list<SrcElem>& srcRng, Size n)
        { return dst_concrete::copy_n<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng, n); }
template<template<class...> class DstTempl, class Size, class Value>
    auto fill_n(Size n, const Value& val)
        { return dst_concrete::fill_n<detail::DstContFromDstTemplDstElem_t<DstTempl, Value>>(n, val); }
template<template<class...> class DstTempl, class Size, class NullaryOp>
    auto generate_n(Size n, NullaryOp nullaryOp)
        { return dst_concrete::generate_n<detail::DstContFromDstTemplNullaryOp_t<DstTempl, NullaryOp>>(n, nullaryOp); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2>
    auto merge(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2>
    auto merge(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2, class IsLessThan>
    auto merge(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2,
                                                                                             isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2, class IsLessThan>
    auto merge(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2,
                                                                                             isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2, class IsLessThan>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2, class IsLessThan>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1,
               const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng>
    auto move(SrcRng&& srcRng)
        { return dst_concrete::move<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(std::forward<SrcRng>(srcRng));}
template<template<class...> class DstTempl1, template<class...> class DstTempl2, class SrcRng, class UnaryPred>
    auto partition_copy(const SrcRng& srcRng, UnaryPred unaryPred)
    {
        using DstCont1 = detail::DstContFromDstTemplSrcRng_t<DstTempl1, SrcRng>;
        using DstCont2 = detail::DstContFromDstTemplSrcRng_t<DstTempl2, SrcRng>;
        return dst_concrete::partition_copy<DstCont1, DstCont2>(srcRng, unaryPred);
    }
template<template<class...> class DstTempl1, template<class...> class DstTempl2, class SrcElem, class UnaryPred>
    auto partition_copy(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
    {
        using DstCont1 = detail::DstContFromDstTemplSrcElem_t<DstTempl1, SrcElem>;
        using DstCont2 = detail::DstContFromDstTemplSrcElem_t<DstTempl2, SrcElem>;
        return dst_concrete::partition_copy<DstCont1, DstCont2>(srcRng, unaryPred);
    }
template<template<class...> class DstTempl, class SrcRng, class Value>
    auto remove_copy(const SrcRng& srcRng, const Value& val)
        { return dst_concrete::remove_copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, val); }
template<template<class...> class DstTempl, class SrcElem, class Value>
    auto remove_copy(const std::initializer_list<SrcElem>& srcRng, const Value& val)
        { return dst_concrete::remove_copy<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng, val); }
template<template<class...> class DstTempl, class SrcRng, class UnaryPred>
    auto remove_copy_if(const SrcRng& srcRng, UnaryPred unaryPred)
        { return dst_concrete::remove_copy_if<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, unaryPred); }
template<template<class...> class DstTempl, class SrcElem, class UnaryPred>
    auto remove_copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return dst_concrete::remove_copy_if<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng,
                                                                                                       unaryPred); }
template<template<class...> class DstTempl, class SrcRng, class Value>
    auto replace_copy(const SrcRng& srcRng, const Value& oldVal, const Value& newVal)
        { return dst_concrete::replace_copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, oldVal,
                                                                                                   newVal); }
template<template<class...> class DstTempl, class SrcElem, class Value>
    auto replace_copy(const std::initializer_list<SrcElem>& srcRng, const Value& oldVal, const Value& newVal)
        { return dst_concrete::replace_copy<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>
            (srcRng, oldVal, newVal); }
template<template<class...> class DstTempl, class SrcRng, class UnaryPred, class Value>
    auto replace_copy_if(const SrcRng& srcRng, UnaryPred unaryPred, const Value& newVal)
        { return dst_concrete::replace_copy_if<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>
            (srcRng, unaryPred, newVal); }
template<template<class...> class DstTempl, class SrcElem, class UnaryPred, class Value>
    auto replace_copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred, const Value& newVal)
        { return dst_concrete::replace_copy_if<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>
            (srcRng, unaryPred, newVal); }
template<template<class...> class DstTempl, class SrcRng>
    auto reverse_copy(const SrcRng& srcRng)
        { return dst_concrete::reverse_copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng); }
template<template<class...> class DstTempl, class SrcElem>
    auto reverse_copy(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::reverse_copy<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng); }
template<template<class...> class DstTempl, class SrcRng, class SrcRngIter>
    auto rotate_copy(const SrcRng& srcRng, SrcRngIter middle)
        { return dst_concrete::rotate_copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, middle); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2>
    auto set_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2>
    auto set_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>(srcRng1,
                                                                                                        srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>(srcRng1,
                                                                                                        srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1,
                        const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2>
    auto set_intersection(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1,
                                                                                                        srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2>
    auto set_intersection(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1,
                                                                                                        srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_intersection(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_intersection(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1,
                          const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1,
                                  const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2,
                                  IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2,
                                  IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1,
                                  const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2>
    auto set_union(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2>
    auto set_union(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>(srcRng1, srcRng2); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_union(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_union(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1,
                   const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<template<class...> class DstTempl, class SrcRng, class UnaryOp>
    auto transform(SrcRng&& srcRng, UnaryOp unaryOp)
        { return dst_concrete::transform<detail::DstContFromDstTemplUnaryOpSrcRng_t<DstTempl, UnaryOp, SrcRng>>
            (std::forward<SrcRng>(srcRng), unaryOp); }
template<template<class...> class DstTempl, class SrcElem, class UnaryOp>
    auto transform(const std::initializer_list<SrcElem>& srcRng, UnaryOp unaryOp)
        { return dst_concrete::transform<detail::DstContFromDstTemplUnaryOpSrcElem_t<DstTempl, UnaryOp, SrcElem>>
            (srcRng, unaryOp); }
template<template<class...> class DstTempl, class SrcRng1, class SrcRng2, class BinaryOp>
    auto transform(SrcRng1&& srcRng1, SrcRng2&& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDstTemplBinaryOpSrcRng1SrcRng2_t
            <DstTempl, BinaryOp, SrcRng1, SrcRng2>>
            (std::forward<SrcRng1>(srcRng1), std::forward<SrcRng2>(srcRng2), binaryOp); }
template<template<class...> class DstTempl, class SrcRng1, class SrcElem2, class BinaryOp>
    auto transform(SrcRng1&& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDstTemplBinaryOpSrcRng1SrcElem2_t
            <DstTempl, BinaryOp, SrcRng1, SrcElem2>>(std::forward<SrcRng1>(srcRng1), srcRng2, binaryOp); }
template<template<class...> class DstTempl, class SrcElem1, class SrcRng2, class BinaryOp>
    auto transform(const std::initializer_list<SrcElem1>& srcRng1, SrcRng2&& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDstTemplBinaryOpSrcElem1SrcRng2_t
            <DstTempl, BinaryOp, SrcElem1, SrcRng2>>(srcRng1, std::forward<SrcRng2>(srcRng2), binaryOp); }
template<template<class...> class DstTempl, class SrcElem1, class SrcElem2, class BinaryOp>
    auto transform(const std::initializer_list<SrcElem1>& srcRng1,
                   const std::initializer_list<SrcElem2>& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDstTemplBinaryOpSrcElem1SrcElem2_t
            <DstTempl, BinaryOp, SrcElem1, SrcElem2>>(srcRng1, srcRng2, binaryOp); }
template<template<class...> class DstTempl, class SrcRng>
    auto unique_copy(const SrcRng& srcRng)
        { return dst_concrete::unique_copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng); }
template<template<class...> class DstTempl, class SrcElem>
    auto unique_copy(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::unique_copy<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng); }
template<template<class...> class DstTempl, class SrcRng, class IsEqualTo>
    auto unique_copy(const SrcRng& srcRng, IsEqualTo isEqualTo)
        { return dst_concrete::unique_copy<detail::DstContFromDstTemplSrcRng_t<DstTempl, SrcRng>>(srcRng, isEqualTo); }
template<template<class...> class DstTempl, class SrcElem, class IsEqualTo>
    auto unique_copy(const std::initializer_list<SrcElem>& srcRng, IsEqualTo isEqualTo)
        { return dst_concrete::unique_copy<detail::DstContFromDstTemplSrcElem_t<DstTempl, SrcElem>>(srcRng, isEqualTo); }
}//namespace dst_template
}//namespace terse

#endif
