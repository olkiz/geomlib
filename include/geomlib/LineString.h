#ifndef GEOMLIB_LINE_H
#define GEOMLIB_LINE_H

// STL libs
#include <string>
#include <vector>

// geomlib
#include "GeometryObject.h"
#include "Point.h"
#include "Arithmetic.h"

namespace geomlib
{
    template<Arithmetic T>
    class LineString : public GeometryObject
    {
    public:
        // NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-identifier-length)
        explicit LineString( std::vector<Point<T>> points )
            : m_Points{ std::move( points ) }
        {

        }

        bool operator==( const LineString<T> &other ) const
        {
            return false;
        }

        [[nodiscard]] std::string type() const override
        {
            return "LineString";
        }

    private:
        std::vector<Point<T>> m_Points;
    };
} // geomlib

#endif //GEOMLIB_LINE_H