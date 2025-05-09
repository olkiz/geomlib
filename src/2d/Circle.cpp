#include "Circle.h"

// geomlib
#include "Point2D.h"

// STL libs
#include <format>
#include <utility>
#include <numbers>
#include <string>

namespace geomlib
{
    Circle::Circle( Point2D center, double radius ) :
        m_Center{ std::move( center ) },
        m_Radius{ radius }
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
