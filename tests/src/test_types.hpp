//  Copyright (C) 2015 Konstantin Berezovsky (kberezovsky@gmail.com)
//
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// We want to prevent the implicit type conversions, hence the special types.

#ifndef TERSE_TESTS_COMMON_HPP
#define TERSE_TESTS_COMMON_HPP

#include <cstddef>
#include <functional>

namespace terse
{
namespace tests
{
namespace test_types
{
struct Elem{};
struct DstElem{};
struct SrcElem{};
struct SrcElem1{};
struct SrcElem2{};

struct Key{};
struct DstKey{};
struct SrcKey{};
struct SrcKey1{};
struct SrcKey2{};

struct Value{};
struct DstValue{};
struct SrcValue{};
struct SrcValue1{};
struct SrcValue2{};
}//namespace test_types
}//namespace tests
}//namespace terse

namespace std
{
template<> struct hash<terse::tests::test_types::Elem    >
    { size_t operator()(const terse::tests::test_types::Elem    &) const { return 0; } };
template<> struct hash<terse::tests::test_types::SrcElem >
    { size_t operator()(const terse::tests::test_types::SrcElem &) const { return 0; } };
template<> struct hash<terse::tests::test_types::SrcElem1>
    { size_t operator()(const terse::tests::test_types::SrcElem1&) const { return 0; } };
template<> struct hash<terse::tests::test_types::SrcElem2>
    { size_t operator()(const terse::tests::test_types::SrcElem2&) const { return 0; } };
template<> struct hash<terse::tests::test_types::Key     >
    { size_t operator()(const terse::tests::test_types::Key     &) const { return 0; } };
template<> struct hash<terse::tests::test_types::SrcKey  >
    { size_t operator()(const terse::tests::test_types::SrcKey  &) const { return 0; } };
template<> struct hash<terse::tests::test_types::SrcKey1 >
    { size_t operator()(const terse::tests::test_types::SrcKey1 &) const { return 0; } };
template<> struct hash<terse::tests::test_types::SrcKey2 >
    { size_t operator()(const terse::tests::test_types::SrcKey2 &) const { return 0; } };
}//namespace std

#endif
