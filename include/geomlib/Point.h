#ifndef POINT2D_H
#define POINT2D_H

// STL libs
#include <cmath>
#include <format>
#include <string>

// geomlib
#include "Arithmetic.h"
#include "GeometryObject.h"

namespace geomlib
{
    template<Arithmetic T>
    class Point : public GeometryObject
    {
    public:
        Point()
        : m_X{},
        m_Y{}
        {
        }
        // NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-identifier-length)
        explicit Point( T x, T y )
        : m_X{ x },
        m_Y{ y }
        {
        }

        [[nodiscard]] double distanceTo( const Point &other ) const
        {
            const double DELTA_X = m_X - other.m_X;
            const double DELTA_Y = m_Y - other.m_Y;
            return std::sqrt( ( DELTA_X * DELTA_X ) + ( DELTA_Y * DELTA_Y ) );
        }

        [[nodiscard]] bool operator==( const Point &other ) const
        {
            return m_X == other.m_X && m_Y == other.m_Y;
        }

        [[nodiscard]] T x() const
        {
            return m_X;
        }

        [[nodiscard]] T y() const
        {
            return m_Y;
        }

        [[nodiscard]] std::string type() const
        {
            return std::format( "Point({}, {})", m_X, m_Y );
        }

    private:
        T m_X;
        T m_Y;
    };
} // namespace geomlib

#endif // POINT2D_H
