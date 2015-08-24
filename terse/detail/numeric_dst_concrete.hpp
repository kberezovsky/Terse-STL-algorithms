//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_NUMERIC_DST_CONCRETE_HPP
#define TERSE_DETAIL_NUMERIC_DST_CONCRETE_HPP

#include "alg_caller.hpp"
#include "methods.hpp"
#include <numeric>

namespace terse
{
namespace dst_concrete
{
template<class DstCont, class SrcRng>
    DstCont adjacent_difference(const SrcRng& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::adjacent_difference(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcElem>
    DstCont adjacent_difference(const std::initializer_list<SrcElem>& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::adjacent_difference(std::begin(srcRng), std::end(srcRng), ins); }); }
template<class DstCont, class SrcRng, class BinaryOp>
    DstCont adjacent_difference(const SrcRng& srcRng, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::adjacent_difference(std::begin(srcRng), std::end(srcRng), ins, binaryOp); }); }
template<class DstCont, class SrcElem, class BinaryOp>
    DstCont adjacent_difference(const std::initializer_list<SrcElem>& srcRng, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::adjacent_difference(std::begin(srcRng), std::end(srcRng), ins, binaryOp); }); }
template< class DstCont, class SrcRng>
    DstCont partial_sum(const SrcRng& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::partial_sum(std::begin(srcRng), std::end(srcRng), ins); }); }
template< class DstCont, class SrcElem>
    DstCont partial_sum(const std::initializer_list<SrcElem>& srcRng)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::partial_sum(std::begin(srcRng), std::end(srcRng), ins); }); }
template< class DstCont, class SrcRng, class BinaryOp>
    DstCont partial_sum(const SrcRng& srcRng, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::partial_sum(std::begin(srcRng), std::end(srcRng), ins, binaryOp); }); }
template< class DstCont, class SrcElem, class BinaryOp>
    DstCont partial_sum(const std::initializer_list<SrcElem>& srcRng, BinaryOp binaryOp)
        { return detail::Alg<DstCont>::call(
            detail::Methods::size(srcRng),
            [&](auto ins)
                { std::partial_sum(std::begin(srcRng), std::end(srcRng), ins, binaryOp); }); }
}//namespace dst_concrete
}//namespace terse

#endif
