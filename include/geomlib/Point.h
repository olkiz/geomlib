#ifndef POINT2D_H
#define POINT2D_H

// STL libs
#include <cmath>
#include <string>

// geomlib
#include "Arithmetic.h"
#include "GeometryObject.h"

namespace geomlib
{
    template <Arithmetic T>
    class Point : public GeometryObject
    {
       public:
        Point() :
            m_X{},
            m_Y{}
        {
        }

        // NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-identifier-length)
        explicit Point( T x, T y ) :
            m_X{ x },
            m_Y{ y }
        {
        }

        [[nodiscard]] auto distanceTo( const Point& other ) const
        {
            const T DELTA_X = m_X - other.m_X;
            const T DELTA_Y = m_Y - other.m_Y;
            return std::sqrt( ( DELTA_X * DELTA_X ) + ( DELTA_Y * DELTA_Y ) );
        }

        [[nodiscard]] auto operator==( const Point& other ) const
        {
            return m_X == other.m_X && m_Y == other.m_Y;
        }

        [[nodiscard]] auto x() const
        {
            return m_X;
        }

        [[nodiscard]] auto y() const
        {
            return m_Y;
        }

        [[nodiscard]] std::string type() const override
        {
            return "Point";
        }

       private:
        T m_X;
        T m_Y;
    };
} // namespace geomlib

#endif // POINT2D_H