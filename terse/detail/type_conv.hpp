//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_TYPE_CONV_HPP
#define TERSE_DETAIL_TYPE_CONV_HPP

#include <type_traits>

namespace terse
{
namespace detail
{
template<class T> using remove_cv_reference_t = std::remove_cv_t<std::remove_reference_t<T>>;
template<class T> using arg_type_t = std::add_lvalue_reference_t<remove_cv_reference_t<T>>;
}//namespace detail
}//namespace terse

#endif
