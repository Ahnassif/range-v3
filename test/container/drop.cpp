// Range v3 library
//
//  Copyright Eric Niebler 2014
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <vector>
#include <range/v3/core.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/algorithm/move.hpp>
#include <range/v3/container/drop.hpp>
#include "../simple_test.hpp"
#include "../test_utils.hpp"

int main()
{
    using namespace ranges;

    std::vector<int> v = view::ints(1,20);
    auto & v2 = cont::drop(v, 3);
    CHECK(&v2 == &v);
    CHECK(v.size() == 17u);
    CHECK(v[0] == 4);

    v = std::move(v) | cont::drop(3);
    CHECK(v.size() == 14u);
    CHECK(v[0] == 7);

    v |= cont::drop(3);
    CHECK(v.size() == 11u);
    CHECK(v[0] == 10);

    v |= cont::drop(100);
    CHECK(v.size() == 0u);

    return ::test_result();
}
