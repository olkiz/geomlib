#ifndef POINT2D_H
#define POINT2D_H

// STL libs
#include <string>

// geomlib
#include "GeometryObject.h"

namespace geomlib
{
    class Point2D : public GeometryObject
    {
       public:
        Point2D( double x = 0.0, double y = 0.0 );

        double distanceTo( const Point2D &other ) const;

        bool operator==( const Point2D &other ) const;

        double x() const;
        double y() const;

        std::string type() const override;

       private:
        double m_X, m_Y;
    };
} // namespace geomlib

#endif // POINT2D_H
