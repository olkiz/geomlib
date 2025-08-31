#ifndef GEOMLIB_ARITHMETIC_H
#define GEOMLIB_ARITHMETIC_H

#include <type_traits>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

#endif // GEOMLIB_ARITHMETIC_H