cmake_minimum_required(VERSION 3.23)
project(geomlib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTING "Build tests" ON)

if(BUILD_TESTING)
    # Fetch Catch2
    include(FetchContent)
    FetchContent_Declare(
            catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v3.5.3
    )
    FetchContent_MakeAvailable(catch2)
endif()

# Sources for the library
set(GEOMLIB_SOURCES
        src/2d/GeometryObject.h
        src/2d/Point2D.h
        src/2d/Circle.h
        src/2d/Circle.cpp
        src/2d/Point2D.cpp
)

# Create library target
add_library(geomlib STATIC ${GEOMLIB_SOURCES})
set_target_properties(geomlib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(geomlib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

# Tests
if(BUILD_TESTING)
    enable_testing()
    set(GEOMLIB_TESTS
            tests/2d/Point2D_test.cpp
    )

    add_executable(geomlib_tests ${GEOMLIB_TESTS})
    target_link_libraries(geomlib_tests PRIVATE geomlib Catch2::Catch2WithMain)

    include(CTest)
    include(Catch)
    catch_discover_tests(geomlib_tests)
endif()