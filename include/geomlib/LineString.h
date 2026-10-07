#pragma once

// STL libs
#include <algorithm>
#include <cstddef>
#include <functional>
#include <ranges>
#include <vector>

// geomlib
#include "Arithmetic.h"
#include "GeometryObject.h"
#include "Point.h"

namespace geomlib
{
    template <Arithmetic T>
    class LineString : public GeometryObject
    {
       public:
        // NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-identifier-length)
        explicit LineString( std::vector<Point<T>> points ) :
            m_Points{ std::move( points ) }
        {
        }

        auto operator==( const LineString<T>& other ) const
        {
            return m_Points.size() == other.m_Points.size() &&
                   std::equal( m_Points.begin(), m_Points.end(), other.m_Points.begin() );
        }

        [[nodiscard]] auto length() const
        {
            auto segmentLengths = m_Points | std::views::pairwise_transform( []( const auto& first, const auto& second )
                                                 { return first.distanceTo( second ); } );

            using Result = std::ranges::range_value_t<decltype( segmentLengths )>;
            return std::ranges::fold_left( segmentLengths, Result{}, std::plus{} );
        }

       private:
        std::vector<Point<T>> m_Points;
    };
} // namespace geomlib
