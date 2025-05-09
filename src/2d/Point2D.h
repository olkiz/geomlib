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
        // NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-identifier-length)
        Point2D( double x = 0.0, double y = 0.0 );

        [[nodiscard]] double distanceTo( const Point2D &other ) const;

        bool operator==( const Point2D &other ) const;

        [[nodiscard]] double x() const;
        [[nodiscard]] double y() const;

        [[nodiscard]] std::string type() const override;

       private:
        double m_X, m_Y;
    };
} // namespace geomlib

#endif // POINT2D_H
