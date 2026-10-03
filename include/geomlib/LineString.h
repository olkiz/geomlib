#pragma once

// STL libs
#include <vector>

// geomlib
#include "GeometryObject.h"
#include "Point.h"
#include "Arithmetic.h"

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

        bool operator==( const LineString<T>& other ) const
        {
            return m_Points.size() == other.m_Points.size() &&
                   std::equal( m_Points.begin(), m_Points.end(), other.m_Points.begin() );
        }

        [[nodiscard]] T length() const
        {
            T result = 0;
            if ( m_Points.size() < 2 )
            {
                return result;
            }

            for ( size_t i = 0; i < m_Points.size() - 1; ++i )
            {
                result += m_Points[ i ].distanceTo( m_Points[ i + 1 ] );
            }
            return result;
        }

       private:
        std::vector<Point<T>> m_Points;
    };
} // namespace geomlib
