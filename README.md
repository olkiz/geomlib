![CI](https://github.com/olkiz/geomlib/actions/workflows/ci.yml/badge.svg)

# geomlib

Modern C++23 library for 2D and 3D computational geometry, designed for mapping, spatial indexing, and geometric algorithms.

## Status

Early development; the API will change.

## Planned Features

- Core types: Point, LineString
- Geometry operations: distance, intersection, containment

## Build

### Requirements

CMake ≥ 3.23 and a C++23 compiler (GCC 13+ / Clang 18+).

### Clang Linux

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/linux-clang.toolchain.cmake ..
cmake --build .
ctest
```

### GCC Linux

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/linux-gcc.toolchain.cmake ..
cmake --build .
ctest
```

### Raspberry Pi

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/gcc-rpi.toolchain.cmake ..
cmake --build .
ctest
```

### macOS

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/clang-macos.toolchain.cmake ..
cmake --build .
ctest
```

## License

This project is licensed under the [MIT License](LICENSE).

## AI Attribution

Library code is written by hand. Tests and documentation may be written with AI assistance (Claude),
and are reviewed by the author before commit.
