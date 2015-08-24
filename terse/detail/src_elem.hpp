//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_SRC_ELEM_HPP
#define TERSE_DETAIL_SRC_ELEM_HPP

#include "type_conv.hpp"
#include <iterator>
#include <utility>

namespace terse
{
namespace detail
{
template<class SrcRng>
class SrcElemFromSrcRng
{
    using SrcElem = decltype(*std::begin(std::declval<arg_type_t<SrcRng>>()));

public:
    using type = remove_cv_reference_t<SrcElem>;
};

template<class SrcRng>
    using SrcElemFromSrcRng_t =
        typename SrcElemFromSrcRng<SrcRng>::type;
}//namespace detail
}//namespace terse

#endif
