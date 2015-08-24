//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_DST_TEMPLATE_HPP
#define TERSE_DETAIL_DST_TEMPLATE_HPP

#include "dst_elem.hpp"
#include "type_conv.hpp"
#include <map>
#include <unordered_map>

namespace terse
{
namespace detail
{
template<template<class...> class DstTempl, class DstElem>
class DstContFromDstTemplDstElem
{
    template<template<class...> class DstTempl_, class DstElem_>
        struct Impl
            { using type = DstTempl_<DstElem_>; };
    template<class DK, class DV>
        struct Impl<std::map, std::pair<DK, DV>>
            { using type = std::map<DK, DV>; };
    template<class DK, class DV>
        struct Impl<std::multimap, std::pair<DK, DV>>
            { using type = std::multimap<DK, DV>; };
    template<class DK, class DV>
        struct Impl<std::unordered_map, std::pair<DK, DV>>
            { using type = std::unordered_map<DK, DV>; };
    template<class DK, class DV>
        struct Impl<std::unordered_multimap, std::pair<DK, DV>>
            { using type = std::unordered_multimap<DK, DV>; };
#ifdef BOOST_CONTAINER_MAP_HPP
    template<class DK, class DV>
        struct Impl<boost::container::map, std::pair<DK, DV>>
            { using type = boost::container::map<DK, DV>; };
    template<class DK, class DV>
        struct Impl<boost::container::multimap, std::pair<DK, DV>>
            { using type = boost::container::multimap<DK, DV>; };
#endif
#ifdef BOOST_CONTAINER_FLAT_MAP_HPP
    template<class DK, class DV>
        struct Impl<boost::container::flat_map, std::pair<DK, DV>>
            { using type = boost::container::flat_map<DK, DV>; };
    template<class DK, class DV>
        struct Impl<boost::container::flat_multimap, std::pair<DK, DV>>
            { using type = boost::container::flat_multimap<DK, DV>; };
#endif
#ifdef BOOST_UNORDERED_UNORDERED_MAP_HPP_INCLUDED
    template<class DK, class DV>
        struct Impl<boost::unordered::unordered_map, std::pair<DK, DV>>
            { using type = boost::unordered::unordered_map<DK, DV>; };
    template<class DK, class DV>
        struct Impl<boost::unordered::unordered_multimap, std::pair<DK, DV>>
            { using type = boost::unordered::unordered_multimap<DK, DV>; };
#endif
#ifdef _DENSE_HASH_MAP_H_
    template<class DK, class DV>
        struct Impl<google::dense_hash_map, std::pair<DK, DV>>
            { using type = google::dense_hash_map<DK, DV>; };
#endif
#ifdef _SPARSE_HASH_MAP_H_
    template<class DK, class DV>
        struct Impl<google::sparse_hash_map, std::pair<DK, DV>>
            { using type = google::sparse_hash_map<DK, DV>; };
#endif

public:
    using type = typename Impl<DstTempl, remove_cv_reference_t<DstElem>>::type;
};

template<template<class...> class DstTempl, class DstElem>
    using DstContFromDstTemplDstElem_t =
        typename DstContFromDstTemplDstElem<DstTempl, DstElem>::type;
template<template<class...> class DstTempl, class SrcRng>
    using DstContFromDstTemplSrcRng_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromSrcRng_t<SrcRng>>;
template<template<class...> class DstTempl, class SrcElem>
    using DstContFromDstTemplSrcElem_t =
        DstContFromDstTemplDstElem_t<DstTempl, SrcElem>;
template<template<class...> class DstTempl, class NullaryOp>
    using DstContFromDstTemplNullaryOp_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromNullaryOp_t<NullaryOp>>;
template<template<class...> class DstTempl, class UnaryOp, class SrcRng>
    using DstContFromDstTemplUnaryOpSrcRng_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromUnaryOpSrcRng_t<UnaryOp, SrcRng>>;
template<template<class...> class DstTempl, class UnaryOp, class SrcElem>
    using DstContFromDstTemplUnaryOpSrcElem_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromUnaryOpSrcElem_t<UnaryOp, SrcElem>>;
template<template<class...> class DstTempl, class BinaryOp, class SrcRng1, class SrcRng2>
    using DstContFromDstTemplBinaryOpSrcRng1SrcRng2_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromBinaryOpSrcRng1SrcRng2_t<BinaryOp, SrcRng1, SrcRng2>>;
template<template<class...> class DstTempl, class BinaryOp, class SrcRng1, class SrcElem2>
    using DstContFromDstTemplBinaryOpSrcRng1SrcElem2_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromBinaryOpSrcRng1SrcElem2_t<BinaryOp, SrcRng1, SrcElem2>>;
template<template<class...> class DstTempl, class BinaryOp, class SrcElem1, class SrcRng2>
    using DstContFromDstTemplBinaryOpSrcElem1SrcRng2_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromBinaryOpSrcElem1SrcRng2_t<BinaryOp, SrcElem1, SrcRng2>>;
template<template<class...> class DstTempl, class BinaryOp, class SrcElem1, class SrcElem2>
    using DstContFromDstTemplBinaryOpSrcElem1SrcElem2_t =
        DstContFromDstTemplDstElem_t<DstTempl, DstElemFromBinaryOpSrcElem1SrcElem2_t<BinaryOp, SrcElem1, SrcElem2>>;
}//namespace detail
}//namespace terse

#endif
