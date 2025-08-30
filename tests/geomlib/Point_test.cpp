#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "geomlib/Point.h"

namespace
{
    constexpr double EPSILON = 0.0001;
} // namespace

TEST_CASE( "Point<double> default constructor initializes to zero", "[Point<double>]" )
{
    geomlib::Point<double> p;
    REQUIRE( p.x() == 0.0 );
    REQUIRE( p.y() == 0.0 );
}

TEST_CASE( "Point<double> parameterized constructor sets values correctly", "[Point<double>]" )
{
    geomlib::Point<double> p( 3.5, -2.1 );
    REQUIRE( p.x() == 3.5 );
    REQUIRE( p.y() == -2.1 );
}

TEST_CASE( "Point<double> distanceTo returns correct distance", "[Point<double>]" )
{
    geomlib::Point<double> p1( 0.0, 0.0 );
    geomlib::Point<double> p2( 3.0, 4.0 );

    double distance = p1.distanceTo( p2 );
    REQUIRE( distance == Catch::Approx( 5.0 ).epsilon( EPSILON ) );
}

TEST_CASE( "Point<double> equality operator works", "[Point<double>]" )
{
    geomlib::Point<double> p1( 1.0, 2.0 );
    geomlib::Point<double> p2( 1.0, 2.0 );
    geomlib::Point<double> p3( 2.0, 3.0 );

    REQUIRE( p1 == p2 );
    REQUIRE_FALSE( p1 == p3 );
}
