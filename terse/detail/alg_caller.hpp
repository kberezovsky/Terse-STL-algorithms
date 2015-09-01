//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef TERSE_DETAIL_ALG_CALLER_HPP
#define TERSE_DETAIL_ALG_CALLER_HPP

#include "methods.hpp"
#include <array>
#include <functional>

namespace terse
{
namespace detail
{
template<class DstElem, std::size_t DstCapacity>
class InsertableArray
{
public:
    using Arr = std::array<DstElem, DstCapacity>;
    using const_iterator = typename Arr::const_iterator;
    using iterator = typename Arr::iterator;
    using size_type = typename Arr::size_type;
    using value_type = typename Arr::value_type;

    InsertableArray(Arr& inArr):arr(inArr), ins(arr.begin()) {}

    iterator insert(const_iterator, const value_type& v)
    {
        *ins = v;
        return ins++;
    }

    iterator insert(const_iterator, value_type&& v)
    {
        *ins = std::move(v);
        return ins++;
    }

    iterator end(){ return arr.end(); }

private:
    Arr& arr;
    iterator ins;
};

template<class DstCont>
struct Alg
{
    template<typename F>
    static auto call(std::size_t capacity, F alg)
    {
        DstCont dst;
        Methods::reserve(dst, capacity);
        alg(std::insert_iterator<DstCont>{ dst, dst.end() });
        return dst;
    }
};

template<class DstElem, std::size_t DstCapacity>
struct Alg<std::array<DstElem, DstCapacity>>
{
    template<typename F>
    static auto call(std::size_t, F alg)
    {
        std::array<DstElem, DstCapacity> dst;
        InsertableArray<DstElem, DstCapacity> insertableDst(dst);
        alg(std::insert_iterator<InsertableArray<DstElem, DstCapacity>>{ insertableDst, insertableDst.end() });
        return dst;
    }
};

template<class DstCont1, class DstCont2>
struct Alg2
{
    template<typename F>
    static auto call(std::size_t capacity1, std::size_t capacity2, F alg)
    {
        std::pair<DstCont1, DstCont2> dst;
        Methods::reserve(dst.first, capacity1);
        Methods::reserve(dst.second, capacity2);
        alg(std::insert_iterator<DstCont1>{ dst.first, dst.first.end() },
            std::insert_iterator<DstCont2>{ dst.second, dst.second.end() });
        return dst;
    }
};

template<class DstElem, std::size_t DstCapacity1, std::size_t DstCapacity2>
struct Alg2<std::array<DstElem, DstCapacity1>, std::array<DstElem, DstCapacity2>>
{
    template<typename F>
    static auto call(std::size_t, std::size_t, F alg)
    {
        std::pair<std::array<DstElem, DstCapacity1>, std::array<DstElem, DstCapacity2>> dst;
        InsertableArray<DstElem, DstCapacity1> insertableDst1(dst.first);
        InsertableArray<DstElem, DstCapacity2> insertableDst2(dst.second);
        alg(std::insert_iterator<InsertableArray<DstElem, DstCapacity1>>{ insertableDst1, insertableDst1.end() },
            std::insert_iterator<InsertableArray<DstElem, DstCapacity2>>{ insertableDst2, insertableDst2.end() });
        return dst;
    }
};

template<class DstCont1, class DstElem, std::size_t DstCapacity2>
struct Alg2<DstCont1, std::array<DstElem, DstCapacity2>>
{
    template<typename F>
    static auto call(std::size_t capacity1, std::size_t, F alg)
    {
        std::pair<DstCont1, std::array<DstElem, DstCapacity2>> dst;
        Methods::reserve(dst.first, capacity1);
        InsertableArray<DstElem, DstCapacity2> insertableDst2(dst.second);
        alg(std::insert_iterator<DstCont1>{ dst.first, dst.first.end() },
            std::insert_iterator<InsertableArray<DstElem, DstCapacity2>>{ insertableDst2, insertableDst2.end() });
        return dst;
    }
};

template<class DstElem, std::size_t DstCapacity1, class DstCont2>
struct Alg2<std::array<DstElem, DstCapacity1>, DstCont2>
{
    template<typename F>
    static auto call(std::size_t, std::size_t capacity2, F alg)
    {
        std::pair<std::array<DstElem, DstCapacity1>, DstCont2> dst;
        InsertableArray<DstElem, DstCapacity1> insertableDst1(dst.first);
        Methods::reserve(dst.second, capacity2);
        alg(std::insert_iterator<InsertableArray<DstElem, DstCapacity1>>{ insertableDst1, insertableDst1.end() },
            std::insert_iterator<DstCont2>{ dst.second, dst.second.end() });
        return dst;
    }
};
}//namespace detail
}//namespace terse

#endif
