#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <vector>

#include "geomlib/LineString.h"

namespace
{
    using PointD = geomlib::Point<double>;
    using PointI = geomlib::Point<int>;
    using LineD  = geomlib::LineString<double>;
    using LineI  = geomlib::LineString<int>;

    constexpr double MARGIN = 1e-9;
} // namespace

TEST_CASE( "LineString<double> equality operator returns true for identical lines", "[LineString<double>]" )
{
    const LineD line1{ { PointD{ 0.0, 0.0 }, PointD{ 1.5, 2.5 }, PointD{ -3.0, 4.0 } } };
    const LineD line2{ { PointD{ 0.0, 0.0 }, PointD{ 1.5, 2.5 }, PointD{ -3.0, 4.0 } } };

    REQUIRE( line1 == line2 );
}

TEST_CASE( "LineString<double> equality operator returns false for different points", "[LineString<double>]" )
{
    const LineD line1{ { PointD{ 0.0, 0.0 }, PointD{ 1.0, 1.0 } } };
    const LineD line2{ { PointD{ 0.0, 0.0 }, PointD{ 2.0, 2.0 } } };

    REQUIRE_FALSE( line1 == line2 );
}

TEST_CASE( "LineString<double> equality operator returns false for different point order", "[LineString<double>]" )
{
    const LineD line1{ { PointD{ 0.0, 0.0 }, PointD{ 1.0, 1.0 } } };
    const LineD line2{ { PointD{ 1.0, 1.0 }, PointD{ 0.0, 0.0 } } };

    REQUIRE_FALSE( line1 == line2 );
}

TEST_CASE( "LineString<double> equality operator returns false for different lengths", "[LineString<double>]" )
{
    const LineD shorter{ { PointD{ 0.0, 0.0 }, PointD{ 1.0, 1.0 } } };
    const LineD longer{ { PointD{ 0.0, 0.0 }, PointD{ 1.0, 1.0 }, PointD{ 2.0, 2.0 } } };

    REQUIRE_FALSE( shorter == longer );
    REQUIRE_FALSE( longer == shorter );
}

TEST_CASE( "LineString<double> empty lines are equal", "[LineString<double>]" )
{
    const LineD line1{ std::vector<PointD>{} };
    const LineD line2{ std::vector<PointD>{} };

    REQUIRE( line1 == line2 );
}

TEST_CASE( "LineString<double> copy is equal to original", "[LineString<double>]" )
{
    const LineD original{ { PointD{ 0.0, 0.0 }, PointD{ 1.0, 1.0 } } };
    const LineD copy = original; // NOLINT(performance-unnecessary-copy-initialization)

    REQUIRE( copy == original );
}

TEST_CASE( "LineString<int> equality operator returns true for identical lines", "[LineString<int>]" )
{
    const LineI line1{ { PointI{ 0, 0 }, PointI{ 1, 2 }, PointI{ -3, 4 } } };
    const LineI line2{ { PointI{ 0, 0 }, PointI{ 1, 2 }, PointI{ -3, 4 } } };

    REQUIRE( line1 == line2 );
}

TEST_CASE( "LineString<int> equality operator returns false for different points", "[LineString<int>]" )
{
    const LineI line1{ { PointI{ 0, 0 }, PointI{ 1, 1 } } };
    const LineI line2{ { PointI{ 0, 0 }, PointI{ 2, 2 } } };

    REQUIRE_FALSE( line1 == line2 );
}

TEST_CASE( "LineString<int> equality operator returns false for different lengths", "[LineString<int>]" )
{
    const LineI shorter{ { PointI{ 0, 0 }, PointI{ 1, 1 } } };
    const LineI longer{ { PointI{ 0, 0 }, PointI{ 1, 1 }, PointI{ 2, 2 } } };

    REQUIRE_FALSE( shorter == longer );
    REQUIRE_FALSE( longer == shorter );
}

TEST_CASE( "LineString<double> length of empty line is zero", "[LineString<double>][length]" )
{
    const LineD line{ std::vector<PointD>{} };
    REQUIRE( line.length() == Catch::Approx( 0.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length of single point is zero", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ 3.0, 4.0 } } };
    REQUIRE( line.length() == Catch::Approx( 0.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length of one segment", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ 0.0, 0.0 }, PointD{ 3.0, 4.0 } } };
    REQUIRE( line.length() == Catch::Approx( 5.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length sums all segments", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ 0.0, 0.0 }, PointD{ 3.0, 4.0 }, PointD{ 3.0, 10.0 } } };
    REQUIRE( line.length() == Catch::Approx( 11.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length of closed square", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ 0.0, 0.0 }, PointD{ 1.0, 0.0 }, PointD{ 1.0, 1.0 }, PointD{ 0.0, 1.0 },
        PointD{ 0.0, 0.0 } } };
    REQUIRE( line.length() == Catch::Approx( 4.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length ignores repeated points", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ 0.0, 0.0 }, PointD{ 0.0, 0.0 }, PointD{ 3.0, 4.0 }, PointD{ 3.0, 4.0 } } };
    REQUIRE( line.length() == Catch::Approx( 5.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length with negative coordinates", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ -1.0, -1.0 }, PointD{ 2.0, 3.0 } } };
    REQUIRE( line.length() == Catch::Approx( 5.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length does not depend on direction", "[LineString<double>][length]" )
{
    const LineD forward{ { PointD{ 0.0, 0.0 }, PointD{ 3.0, 4.0 }, PointD{ 3.0, 10.0 } } };
    const LineD backward{ { PointD{ 3.0, 10.0 }, PointD{ 3.0, 4.0 }, PointD{ 0.0, 0.0 } } };
    REQUIRE( forward.length() == Catch::Approx( backward.length() ).margin( MARGIN ) );
}

TEST_CASE( "LineString<double> length with large coordinates", "[LineString<double>][length]" )
{
    const LineD line{ { PointD{ 1e6, 1e6 }, PointD{ 1e6 + 3.0, 1e6 + 4.0 } } };
    REQUIRE( line.length() == Catch::Approx( 5.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<int> length of one segment", "[LineString<int>][length]" )
{
    const LineI line{ { PointI{ 0, 0 }, PointI{ 3, 4 } } };
    REQUIRE( line.length() == Catch::Approx( 5.0 ).margin( MARGIN ) );
}

TEST_CASE( "LineString<int> length sums all segments", "[LineString<int>][length]" )
{
    const LineI line{ { PointI{ 0, 0 }, PointI{ 3, 4 }, PointI{ 3, 10 } } };
    REQUIRE( line.length() == Catch::Approx( 11.0 ).margin( MARGIN ) );
}
