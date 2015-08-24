//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_ALGORITHM_DST_CONCRETE_HPP
#define TERSE_DETAIL_ALGORITHM_DST_CONCRETE_HPP

#include "alg_caller.hpp"
#include "methods.hpp"
#include <algorithm>

namespace terse
{
namespace dst_concrete
{
template<class DstCont, class SrcRng>
    DstCont copy(const SrcRng& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::copy(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcElem>
    DstCont copy(const std::initializer_list<SrcElem>& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::copy(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcRng, class UnaryPred>
    DstCont copy_if(const SrcRng& srcRng, UnaryPred unaryPred)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::copy_if(std::begin(srcRng), std::end(srcRng), ins, unaryPred); }); }
template<class DstCont, class SrcElem, class UnaryPred>
    DstCont copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::copy_if(std::begin(srcRng), std::end(srcRng), ins, unaryPred); }); }
template<class DstCont, class SrcRng, class Size>
    DstCont copy_n(const SrcRng& srcRng, Size n)
        { return detail::Alg<DstCont>::call(
            n,
            [&](auto ins)
                { std::copy_n(std::begin(srcRng), n, ins); }); }
template<class DstCont, class SrcElem, class Size>
    DstCont copy_n(const std::initializer_list<SrcElem>& srcRng, Size n)
        { return detail::Alg<DstCont>::call(
            n,
            [&](auto ins)
                { std::copy_n(std::begin(srcRng), n, ins); }); }
template<class DstCont, class Size, class Value>
    DstCont fill_n(Size n, const Value& val)
        { return detail::Alg<DstCont>::call(
            n,
            [&](auto ins)
                { std::fill_n(ins, n, val); }); }
template<class DstCont, class Size, class NullaryOp>
    DstCont generate_n(Size n, NullaryOp nullaryOp)
        { return detail::Alg<DstCont>::call(
            n,
            [&](auto ins)
                { std::generate_n(ins, n, nullaryOp); }); }
template<class DstCont, class SrcRng1, class SrcRng2>
    DstCont merge(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcElem2>
    DstCont merge(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcRng2>
    DstCont merge(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcElem2>
    DstCont merge(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcRng2, class IsLessThan>
    DstCont merge(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1),
                            std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcElem2, class IsLessThan>
    DstCont merge(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1),
                            std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcRng2, class IsLessThan>
    DstCont merge(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1),
                            std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcElem2, class IsLessThan>
    DstCont merge(const std::initializer_list<SrcElem1>& srcRng1,
                  const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1)+detail::Methods::size(srcRng2),
            [&](auto ins)
                { std::merge(std::begin(srcRng1), std::end(srcRng1),
                            std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng>
    DstCont move(SrcRng&& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::move(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont1, class DstCont2, class SrcRng, class UnaryPred>
    std::pair<DstCont1, DstCont2> partition_copy(const SrcRng& srcRng, UnaryPred unaryPred)
        { return detail::Alg2<DstCont1, DstCont2>::call(
            0, 0,
            [&](auto ins1, auto ins2)
                { std::partition_copy(std::begin(srcRng), std::end(srcRng), ins1, ins2, unaryPred); }); }
template<class DstCont1, class DstCont2, class SrcElem, class UnaryPred>
    std::pair<DstCont1, DstCont2> partition_copy(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return detail::Alg2<DstCont1, DstCont2>::call(
            0, 0,
            [&](auto ins1, auto ins2)
                { std::partition_copy(std::begin(srcRng), std::end(srcRng), ins1, ins2, unaryPred); }); }
template<class DstCont, class SrcRng, class Value>
    DstCont remove_copy(const SrcRng& srcRng, const Value& val)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::remove_copy(std::begin(srcRng), std::end(srcRng), ins, val); }); }
template<class DstCont, class SrcElem, class Value>
    DstCont remove_copy(const std::initializer_list<SrcElem>& srcRng, const Value& val)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::remove_copy(std::begin(srcRng), std::end(srcRng), ins, val); }); }
template<class DstCont, class SrcRng, class UnaryPred>
    DstCont remove_copy_if(const SrcRng& srcRng, UnaryPred unaryPred)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::remove_copy_if(std::begin(srcRng), std::end(srcRng), ins, unaryPred); }); }
template<class DstCont, class SrcElem, class UnaryPred>
    DstCont remove_copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::remove_copy_if(std::begin(srcRng), std::end(srcRng), ins, unaryPred); }); }
template<class DstCont, class SrcRng, class Value>
    DstCont replace_copy(const SrcRng& srcRng, const Value& oldVal, const Value& newVal)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::replace_copy(std::begin(srcRng), std::end(srcRng), ins, oldVal, newVal); }); }
template<class DstCont, class SrcElem, class Value>
    DstCont replace_copy(const std::initializer_list<SrcElem>& srcRng, const Value& oldVal, const Value& newVal)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::replace_copy(std::begin(srcRng), std::end(srcRng), ins, oldVal, newVal); }); }
template<class DstCont, class SrcRng, class UnaryPred, class Value>
    DstCont replace_copy_if(const SrcRng& srcRng, UnaryPred unaryPred, const Value& newVal)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::replace_copy_if(std::begin(srcRng), std::end(srcRng), ins, unaryPred, newVal); }); }
template<class DstCont, class SrcElem, class UnaryPred, class Value>
    DstCont replace_copy_if(const std::initializer_list<SrcElem>& srcRng, UnaryPred unaryPred, const Value& newVal)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::replace_copy_if(std::begin(srcRng), std::end(srcRng), ins, unaryPred, newVal); }); }
template<class DstCont, class SrcRng>
    DstCont reverse_copy(const SrcRng& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::reverse_copy(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcElem>
    DstCont reverse_copy(const std::initializer_list<SrcElem>& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::reverse_copy(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcRng, class SrcRngIter>
    DstCont rotate_copy(const SrcRng& srcRng, SrcRngIter middle)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::rotate_copy(std::begin(srcRng), middle, std::end(srcRng), ins); }); }
template<class DstCont, class SrcRng1, class SrcRng2>
    DstCont set_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcElem2>
    DstCont set_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                        std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcRng2>
    DstCont set_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcElem2>
    DstCont set_difference(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcRng2, class IsLessThan>
    DstCont set_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcElem2, class IsLessThan>
    DstCont set_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcRng2, class IsLessThan>
    DstCont set_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcElem2, class IsLessThan>
    DstCont set_difference(const std::initializer_list<SrcElem1>& srcRng1,
                            const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_difference(std::begin(srcRng1), std::end(srcRng1),
                                     std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcRng2>
    DstCont set_intersection(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcElem2>
    DstCont set_intersection(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcRng2>
    DstCont set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcElem2>
    DstCont set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcRng2, class IsLessThan>
    DstCont set_intersection(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcElem2, class IsLessThan>
    DstCont set_intersection(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcRng2, class IsLessThan>
    DstCont set_intersection(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcElem2, class IsLessThan>
    DstCont set_intersection(const std::initializer_list<SrcElem1>& srcRng1,
                             const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_intersection(std::begin(srcRng1), std::end(srcRng1),
                                       std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcRng2>
    DstCont set_symmetric_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcElem2>
    DstCont set_symmetric_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcRng2>
    DstCont set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcElem2>
    DstCont set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1,
                                      const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcRng2, class IsLessThan>
    DstCont set_symmetric_difference(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcElem2, class IsLessThan>
    DstCont set_symmetric_difference(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2,
                                      IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcRng2, class IsLessThan>
    DstCont set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2,
                                      IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcElem2, class IsLessThan>
    DstCont set_symmetric_difference(const std::initializer_list<SrcElem1>& srcRng1,
                                      const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::set_symmetric_difference(std::begin(srcRng1), std::end(srcRng1),
                                               std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcRng2>
    DstCont set_union(const SrcRng1& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcElem2>
    DstCont set_union(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcRng2>
    DstCont set_union(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcElem1, class SrcElem2>
    DstCont set_union(const std::initializer_list<SrcElem1>& srcRng1, const std::initializer_list<SrcElem2>& srcRng2)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), std::end(srcRng2), ins); }); }
template<class DstCont, class SrcRng1, class SrcRng2, class IsLessThan>
    DstCont set_union(const SrcRng1& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1),
                                std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng1, class SrcElem2, class IsLessThan>
    DstCont set_union(const SrcRng1& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1),
                                std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcRng2, class IsLessThan>
    DstCont set_union(const std::initializer_list<SrcElem1>& srcRng1, const SrcRng2& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1),
                                std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcElem1, class SrcElem2, class IsLessThan>
    DstCont set_union(const std::initializer_list<SrcElem1>& srcRng1,
                       const std::initializer_list<SrcElem2>& srcRng2, IsLessThan isLessThan)
        { return detail::Alg<DstCont>::call(
            std::max(detail::Methods::size(srcRng1), detail::Methods::size(srcRng2)),
            [&](auto ins)
                { std::set_union(std::begin(srcRng1), std::end(srcRng1),
                                std::begin(srcRng2), std::end(srcRng2), ins, isLessThan); }); }
template<class DstCont, class SrcRng, class UnaryOp>
    DstCont transform(SrcRng&& srcRng, UnaryOp unaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::transform(std::begin(srcRng), std::end(srcRng), ins, unaryOp); }); }
template<class DstCont, class SrcElem, class UnaryOp>
    DstCont transform(const std::initializer_list<SrcElem>& srcRng, UnaryOp unaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::transform(std::begin(srcRng), std::end(srcRng), ins, unaryOp); }); }
template<class DstCont, class SrcRng1, class SrcRng2, class BinaryOp>
    DstCont transform(SrcRng1&& srcRng1, SrcRng2&& srcRng2, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1),
            [&](auto ins)
                { std::transform(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), ins, binaryOp); }); }
template<class DstCont, class SrcRng1, class SrcElem2, class BinaryOp>
    DstCont transform(SrcRng1&& srcRng1, const std::initializer_list<SrcElem2>& srcRng2, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1),
            [&](auto ins)
                { std::transform(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), ins, binaryOp); }); }
template<class DstCont, class SrcElem1, class SrcRng2, class BinaryOp>
    DstCont transform(const std::initializer_list<SrcElem1>& srcRng1, SrcRng2&& srcRng2, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1),
            [&](auto ins)
                { std::transform(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), ins, binaryOp); }); }
template<class DstCont, class SrcElem1, class SrcElem2, class BinaryOp>
    DstCont transform(const std::initializer_list<SrcElem1>& srcRng1,
                       const std::initializer_list<SrcElem2>& srcRng2, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng1),
            [&](auto ins)
                { std::transform(std::begin(srcRng1), std::end(srcRng1), std::begin(srcRng2), ins, binaryOp); }); }
template<class DstCont, class SrcRng>
    DstCont unique_copy(const SrcRng& srcRng)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::unique_copy(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcElem>
    DstCont unique_copy(const std::initializer_list<SrcElem>& srcRng)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::unique_copy(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcRng, class IsEqualTo>
    DstCont unique_copy(const SrcRng& srcRng, IsEqualTo isEqualTo)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::unique_copy(std::begin(srcRng), std::end(srcRng), ins, isEqualTo); }); }
template<class DstCont, class SrcElem, class IsEqualTo>
    DstCont unique_copy(const std::initializer_list<SrcElem>& srcRng, IsEqualTo isEqualTo)
        { return detail::Alg<DstCont>::call(
            0,
            [&](auto ins)
                { std::unique_copy(std::begin(srcRng), std::end(srcRng), ins, isEqualTo); }); }
}//dst_concrete
}//namespace terse

#endif
