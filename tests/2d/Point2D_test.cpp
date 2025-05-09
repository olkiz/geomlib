#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "2d/Point2D.h"

namespace
{
    constexpr double EPSILON = 0.0001;
} // namespace

TEST_CASE( "Point2D default constructor initializes to zero", "[Point2D]" )
{
    geomlib::Point2D p;
    REQUIRE( p.x() == 0.0 );
    REQUIRE( p.y() == 0.0 );
}

TEST_CASE( "Point2D parameterized constructor sets values correctly", "[Point2D]" )
{
    geomlib::Point2D p( 3.5, -2.1 );
    REQUIRE( p.x() == 3.5 );
    REQUIRE( p.y() == -2.1 );
}

TEST_CASE( "Point2D distanceTo returns correct distance", "[Point2D]" )
{
    geomlib::Point2D p1( 0.0, 0.0 );
    geomlib::Point2D p2( 3.0, 4.0 );

    double distance = p1.distanceTo( p2 );
    REQUIRE( distance == Catch::Approx( 5.0 ).epsilon( EPSILON ) );
}

TEST_CASE( "Point2D equality operator works", "[Point2D]" )
{
    geomlib::Point2D p1( 1.0, 2.0 );
    geomlib::Point2D p2( 1.0, 2.0 );
    geomlib::Point2D p3( 2.0, 3.0 );

    REQUIRE( p1 == p2 );
    REQUIRE_FALSE( p1 == p3 );
}
