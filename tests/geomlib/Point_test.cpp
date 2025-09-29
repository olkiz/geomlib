#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <limits>

#include "geomlib/Point.h"

namespace
{
    constexpr double EPSILON = std::numeric_limits<double>::epsilon();
} // namespace

TEST_CASE( "Point<double> default constructor initializes to zero", "[Point<double>]" )
{
    const geomlib::Point<double> point;
    REQUIRE( point.x() == Catch::Approx( 0.0 ).epsilon( EPSILON ) );
    REQUIRE( point.y() == Catch::Approx( 0.0 ).epsilon( EPSILON ) );
}

TEST_CASE( "Point<double> parameterized constructor sets values correctly", "[Point<double>]" )
{
    const geomlib::Point<double> point{ 3.5, -2.1 };
    REQUIRE( point.x() == Catch::Approx( 3.5 ).epsilon( EPSILON ) );
    REQUIRE( point.y() == Catch::Approx( -2.1 ).epsilon( EPSILON ) );
}

TEST_CASE( "Point<double> distanceTo returns correct distance", "[Point<double>]" )
{
    const geomlib::Point<double> point1{ 0.0, 0.0 };
    const geomlib::Point<double> point2{ 3.0, 4.0 };

    const double distance = point1.distanceTo( point2 );
    REQUIRE( distance == Catch::Approx( 5.0 ).epsilon( EPSILON ) );
}

TEST_CASE( "Point<double> equality operator works", "[Point<double>]" )
{
    const geomlib::Point<double> point1{ 1.0, 2.0 };
    const geomlib::Point<double> point2{ 1.0, 2.0 };
    const geomlib::Point<double> point3{ 2.0, 3.0 };

    REQUIRE( point1 == point2 );
    REQUIRE_FALSE( point1 == point3 );
}

TEST_CASE( "Point<int> default constructor initializes to zero", "[Point<int>]" )
{
    const geomlib::Point<int> point;
    REQUIRE( point.x() == 0 );
    REQUIRE( point.y() == 0 );
}

TEST_CASE( "Point<int> parameterized constructor sets values correctly", "[Point<int>]" )
{
    const geomlib::Point<int> point{ 3, -2 };
    REQUIRE( point.x() == 3 );
    REQUIRE( point.y() == -2 );
}

TEST_CASE( "Point<int> distanceTo returns correct distance", "[Point<int>]" )
{
    const geomlib::Point<int> point1{ 0, 0 };
    const geomlib::Point<int> point2{ 3, 4 };

    const double distance = point1.distanceTo( point2 );
    REQUIRE( distance == 5 );
}

TEST_CASE( "Point<int> equality operator works", "[Point<int>]" )
{
    const geomlib::Point<int> point1{ 1, 2 };
    const geomlib::Point<int> point2{ 1, 2 };
    const geomlib::Point<int> point3{ 2, 3 };

    REQUIRE( point1 == point2 );
    REQUIRE_FALSE( point1 == point3 );
}
