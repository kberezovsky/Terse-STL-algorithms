//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_ALGORITHM_DST_DEFAULT_HPP
#define TERSE_DETAIL_ALGORITHM_DST_DEFAULT_HPP

#include "algorithm_dst_concrete.hpp"
#include "dst_default.hpp"

namespace terse
{
namespace dst_default
{
template<class SrcRng>
    auto copy(const SrcRng& srcRng)
        { return dst_concrete::copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng); }
template<class SrcElem>
    auto copy(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::copy<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng); }
template<class SrcRng, class UnaryPred>
    auto copy_if(const SrcRng& srcRng, UnaryPred unaryPred)
        { return dst_concrete::copy_if<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, unaryPred); }
template<class SrcElem, class UnaryPred>
    auto copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return dst_concrete::copy_if<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, unaryPred); }
template<class SrcRng, class Size>
    auto copy_n(const SrcRng& srcRng, Size n)
        { return dst_concrete::copy_n<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, n); }
template<class SrcElem, class Size>
    auto copy_n(const std::initializer_list<SrcElem>& srcRng, Size n)
        { return dst_concrete::copy_n<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, n); }
template<class Size, class Value>
    auto fill_n(Size n, const Value& val)
        { return dst_concrete::fill_n<detail::DstContFromDefaultDstElem_t<Value>>(n, val); }
template<class Size, class NullaryOp>
    auto generate_n(Size n, NullaryOp nullaryOp)
        { return dst_concrete::generate_n<detail::DstContFromDefaultNullaryOp_t<NullaryOp>>(n, nullaryOp); }
template<class SrcRng1, class SrcRng2>
    auto merge(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcElem2>
    auto merge(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcRng2>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcElem2>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcRng2, class IsLessThan>
    auto merge(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcRng1, class SrcElem2, class IsLessThan>
    auto merge(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcRng2, class IsLessThan>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcElem2, class IsLessThan>
    auto merge(const std::initializer_list<SrcElem1>& srcRng1,
               const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::merge<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcRng>
    auto move(SrcRng&& srcRng)
        { return dst_concrete::move<detail::DstContFromDefaultSrcRng_t<SrcRng>>(std::forward<SrcRng>(srcRng)); }
template<class SrcRng, class UnaryPred>
    auto partition_copy(const SrcRng& srcRng, UnaryPred unaryPred)
    {
        using DstCont = detail::DstContFromDefaultSrcRng_t<SrcRng>;
        return dst_concrete::partition_copy<DstCont, DstCont>(srcRng, unaryPred);
    }
template<class SrcElem, class UnaryPred>
    auto partition_copy(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
    {
        using DstCont = detail::DstContFromDefaultSrcElem_t<SrcElem>;
        return dst_concrete::partition_copy<DstCont, DstCont>(srcRng, unaryPred);
    }
template<class SrcRng, class Value>
    auto remove_copy(const SrcRng& srcRng, const Value& val)
        { return dst_concrete::remove_copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, val); }
template<class SrcElem, class Value>
    auto remove_copy(const std::initializer_list<SrcElem>& srcRng, const Value& val)
        { return dst_concrete::remove_copy<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, val); }
template<class SrcRng, class UnaryPred>
    auto remove_copy_if(const SrcRng& srcRng, UnaryPred unaryPred)
        { return dst_concrete::remove_copy_if<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, unaryPred); }
template<class SrcElem, class UnaryPred>
    auto remove_copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return dst_concrete::remove_copy_if<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, unaryPred); }
template<class SrcRng, class Value>
    auto replace_copy(const SrcRng& srcRng, const Value& oldVal, const Value& newVal)
        { return dst_concrete::replace_copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, oldVal, newVal); }
template<class SrcElem, class Value>
    auto replace_copy(const std::initializer_list<SrcElem>& srcRng, const Value& oldVal, const Value& newVal)
        { return dst_concrete::replace_copy<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, oldVal, newVal); }
template<class SrcRng, class UnaryPred, class Value>
    auto replace_copy_if(const SrcRng& srcRng, UnaryPred unaryPred, const Value& newVal)
        { return dst_concrete::replace_copy_if<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, unaryPred, newVal); }
template<class SrcElem, class UnaryPred, class Value>
    auto replace_copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred, const Value& newVal)
        { return dst_concrete::replace_copy_if<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, unaryPred, newVal); }
template<class SrcRng>
    auto reverse_copy(const SrcRng& srcRng)
        { return dst_concrete::reverse_copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng); }
template<class SrcElem>
    auto reverse_copy(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::reverse_copy<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng); }
template<class SrcRng, class SrcRngIter>
    auto rotate_copy(const SrcRng& srcRng, SrcRngIter middle)
        { return dst_concrete::rotate_copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, middle); }
template<class SrcRng1, class SrcRng2>
    auto set_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcElem2>
    auto set_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcRng2>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcElem2>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2, isLessThan);}
template<class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2, isLessThan);}
template<class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2,
                                                                                             isLessThan); }
template<class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_difference(const std::initializer_list<SrcElem1>& srcRng1,
                        const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2,
                                                                                             isLessThan); }
template<class SrcRng1, class SrcRng2>
    auto set_intersection(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcElem2>
    auto set_intersection(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcRng2>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcElem2>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_intersection(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2,
                                                                                             isLessThan); }
template<class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_intersection(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2,
                                                                                             isLessThan); }
template<class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcElem_t<SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_intersection(const std::initializer_list<SrcElem1>& srcRng1,
                          const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_intersection<detail::DstContFromDefaultSrcElem_t<SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<class SrcRng1, class SrcRng2>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcElem2>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcRng2>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2);}
template<class SrcElem1, class SrcElem2>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1,
                                  const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2);}
template<class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_symmetric_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2,
                                  IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcRng_t<SrcRng1>>
            (srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2,
                                  IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1,
                                  const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_symmetric_difference<detail::DstContFromDefaultSrcElem_t<SrcElem1>>
            (srcRng1, srcRng2, isLessThan); }
template<class SrcRng1, class SrcRng2>
    auto set_union(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcElem2>
    auto set_union(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcRng2>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcElem1, class SrcElem2>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2); }
template<class SrcRng1, class SrcRng2, class IsLessThan>
    auto set_union(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcRng1, class SrcElem2, class IsLessThan>
    auto set_union(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcRng_t<SrcRng1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcRng2, class IsLessThan>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcElem1, class SrcElem2, class IsLessThan>
    auto set_union(const std::initializer_list<SrcElem1>& srcRng1,
                   const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return dst_concrete::set_union<detail::DstContFromDefaultSrcElem_t<SrcElem1>>(srcRng1, srcRng2, isLessThan); }
template<class SrcRng, class UnaryOp>
    auto transform(SrcRng&& srcRng, UnaryOp unaryOp)
        { return dst_concrete::transform<detail::DstContFromDefaultUnaryOpSrcRng_t<UnaryOp, SrcRng>>
            (std::forward<SrcRng>(srcRng), unaryOp); }
template<class SrcElem, class UnaryOp>
    auto transform(const std::initializer_list<SrcElem>& srcRng, UnaryOp unaryOp)
        { return dst_concrete::transform<detail::DstContFromDefaultUnaryOpSrcElem_t<UnaryOp, SrcElem>>(srcRng, unaryOp); }
template<class SrcRng1, class SrcRng2, class BinaryOp>
    auto transform(SrcRng1&& srcRng1, SrcRng2&& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDefaultBinaryOpSrcRng1SrcRng2_t<BinaryOp, SrcRng1, SrcRng2>>
            (std::forward<SrcRng1>(srcRng1), std::forward<SrcRng2>(srcRng2), binaryOp); }
template<class SrcRng1, class SrcElem2, class BinaryOp>
    auto transform(SrcRng1&& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDefaultBinaryOpSrcRng1SrcElem2_t<BinaryOp, SrcRng1, SrcElem2>>
            (std::forward<SrcRng1>(srcRng1), srcRng2, binaryOp); }
template<class SrcElem1, class SrcRng2, class BinaryOp>
    auto transform(const std::initializer_list<SrcElem1>& srcRng1, SrcRng2&& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDefaultBinaryOpSrcElem1SrcRng2_t<BinaryOp, SrcElem1, SrcRng2>>
            (srcRng1, std::forward<SrcRng2>(srcRng2), binaryOp); }
template<class SrcElem1, class SrcElem2, class BinaryOp>
    auto transform(const std::initializer_list<SrcElem1>& srcRng1,
                   const std::initializer_list<SrcElem2>& srcRng2, BinaryOp binaryOp)
        { return dst_concrete::transform<detail::DstContFromDefaultBinaryOpSrcElem1SrcElem2_t<BinaryOp, SrcElem1,
                                                                                              SrcElem2>>
            (srcRng1, srcRng2, binaryOp); }
template<class SrcRng>
    auto unique_copy(const SrcRng& srcRng)
        { return dst_concrete::unique_copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng); }
template<class SrcElem>
    auto unique_copy(const std::initializer_list<SrcElem>& srcRng)
        { return dst_concrete::unique_copy<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng); }
template<class SrcRng, class IsEqualTo>
    auto unique_copy(const SrcRng& srcRng, IsEqualTo isEqualTo)
        { return dst_concrete::unique_copy<detail::DstContFromDefaultSrcRng_t<SrcRng>>(srcRng, isEqualTo); }
template<class SrcElem, class IsEqualTo>
    auto unique_copy(const std::initializer_list<SrcElem>& srcRng, IsEqualTo isEqualTo)
        { return dst_concrete::unique_copy<detail::DstContFromDefaultSrcElem_t<SrcElem>>(srcRng, isEqualTo); }
}//namespace dst_default
}//namespace terse

#endif
