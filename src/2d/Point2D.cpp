#include "Point2D.h"

// STL libs
#include <cmath>
#include <format>

namespace geomlib
{

    Point2D::Point2D( double x, double y ) :
        m_X{ x },
        m_Y{ y }
    {
    }

    double Point2D::distanceTo( const Point2D &other ) const
    {
        double dx = m_X - other.m_X;
        double dy = m_Y - other.m_Y;
        return std::sqrt( dx * dx + dy * dy );
    }

    bool Point2D::operator==( const Point2D &other ) const
    {
        return m_X == other.m_X && m_Y == other.m_Y;
    }

    double Point2D::x() const
    {
        return m_X;
    };
    double Point2D::y() const
    {
        return m_Y;
    };

    std::string Point2D::type() const
    {
        return std::format( "Point2D({}, {})", m_X, m_Y );
    }
} // namespace geomlib
