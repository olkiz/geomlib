#include "Circle.h"

// STL libs
#include <format>

namespace geomlib
{
    Circle::Circle( Point2D center, double radius ) :
        m_Radius{ radius },
        m_Center{ std::move( center ) }
    {
    }

    double Circle::area() const
    {
        return std::numbers::pi * m_Radius * m_Radius;
    }
    double Circle::perimeter() const
    {
        return 2 * std::numbers::pi * m_Radius;
    }
    std::string Circle::type() const
    {
        return std::format( "Circle(radius={})", m_Radius );
    }
} // namespace geomlib
