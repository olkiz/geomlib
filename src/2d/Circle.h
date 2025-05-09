#ifndef CIRCLE_H
#define CIRCLE_H

// STL libs
#include <string>

// geomlib
#include "GeometryObject.h"
#include "Point2D.h"

namespace geomlib
{
    class Circle : public GeometryObject
    {
       public:
        Circle( Point2D center = {}, double radius = 0.0 );

        [[nodiscard]] double area() const;
        [[nodiscard]] double perimeter() const;
        [[nodiscard]] std::string type() const override;

       private:
        Point2D m_Center;
        double m_Radius;
    };
} // namespace geomlib

#endif // CIRCLE_H
