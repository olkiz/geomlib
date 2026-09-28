#pragma once
#include <string>

namespace geomlib
{
    class GeometryObject
    {
       public:
        GeometryObject() = default;

        virtual ~GeometryObject() = default;

        GeometryObject( const GeometryObject& other ) = default;
        GeometryObject( GeometryObject&& other )      = default;

        GeometryObject& operator=( const GeometryObject& other ) = default;
        GeometryObject& operator=( GeometryObject&& other )      = default;
    };
} // namespace geomlib
