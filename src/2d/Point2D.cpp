#include "Point2D.h"

// STL libs
#include <cmath>
#include <format>
#include <string>

namespace geomlib
{
    // NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-identifier-length)
    Point2D::Point2D( double x, double y ) :
        m_X{ x },
        m_Y{ y }
    {
    }

    double Point2D::distanceTo( const Point2D &other ) const
    {
        const double DELTA_X = m_X - other.m_X;
        const double DELTA_Y = m_Y - other.m_Y;
        return std::sqrt( ( DELTA_X * DELTA_X ) + ( DELTA_Y * DELTA_Y ) );
    }

    bool Point2D::operator==( const Point2D &other ) const
    {
        return m_X == other.m_X && m_Y == other.m_Y;
    }

    double Point2D::x() const
    {
        return m_X;
    }

    double Point2D::y() const
    {
        return m_Y;
    }

    std::string Point2D::type() const
    {
        return std::format( "Point2D({}, {})", m_X, m_Y );
    }
} // namespace geomlib
