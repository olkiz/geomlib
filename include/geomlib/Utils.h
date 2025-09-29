#pragma once
#include <cmath>
#include <limits>
#include <type_traits>

namespace geomlib
{
    template<class A, class B>
    bool is_equal(A first, B second) noexcept
    {
        return first == second;
    }

    template<class A, class B>
    requires std::is_floating_point_v<A> && std::is_floating_point_v<B>
    bool is_equal(A first, B second) noexcept
    {
        return std::abs(first - second) < std::numeric_limits<std::common_type_t<A,B>>::epsilon();
    }
} // namespace geomlib
