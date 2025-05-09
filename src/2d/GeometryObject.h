#ifndef SHAPE_H
#define SHAPE_H

namespace geomlib
{
    class GeometryObject
    {
       public:
        virtual ~GeometryObject() = default;

        virtual std::string type() const = 0;
    };
} // namespace geomlib

#endif // SHAPE_H
