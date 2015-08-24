//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_METHODS_HPP
#define TERSE_DETAIL_METHODS_HPP

#include <cstddef>
#include <type_traits>

namespace terse
{
namespace detail
{
class Methods
{
    template<class Cont, class = decltype(std::declval<Cont>().reserve(0))> static std::true_type testReserve(int);
    template<class Cont> static std::false_type testReserve(...);
    template<class Cont> static void callReserve(Cont& cont, std::size_t capacity, std::true_type){ cont.reserve(capacity); }
    template<class Cont> static void callReserve(Cont& cont, std::size_t capacity, std::false_type){}
    template<class Cont, class = decltype(std::declval<Cont>().size())> static std::true_type testSize(int);
    template<class Cont> static std::false_type testSize(...);
    template<class Cont> static std::size_t callSize(const Cont& cont, std::true_type){ return cont.size(); }
    template<class Cont> static std::size_t callSize(const Cont& cont, std::false_type){ return 0; }

public:
    template<class Cont> static void reserve(Cont& cont, std::size_t capacity){ callReserve<Cont>(cont, capacity,
        decltype(testReserve<Cont>(0))()); }
    template<class Cont> static std::size_t size(const Cont& cont){ return callSize<Cont>(cont,
        decltype(testSize<Cont>(0))()); }
    template<class T, int SIZE> static std::size_t size(const T(&)[SIZE]){ return SIZE; }
};
}//namespace detail
}//namespace terse

#endif
