#include <chrono>
#include <iostream>

#include <terse/algorithm.hpp>

#include "catch.hpp"

TEST_CASE("performance", "[hide]")
{
    using namespace std::chrono;
    using namespace terse::dst_default;

    size_t const count = 100000000;

    auto const start = high_resolution_clock::now();

    auto const v1 = generate_n(count, [](){ return 1; });
    auto const v2 = transform(v1, [](auto x) { return x * 2; });

    auto const dur = high_resolution_clock::now() - start;
    WARN("Duration: " << duration_cast<microseconds>(dur).count() << " microseconds");
}
