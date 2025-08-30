![CI](https://github.com/olkiz/geomlib/actions/workflows/ci.yml/badge.svg)

## geomlib
Modern C++23 library for 2D and 3D computational geometry, designed for mapping, spatial indexing, and geometric algorithms.

### Key features:

* Core types: Point, LineString
* Geometry operations: distance, intersection, containment

## Build
### Clang Linux:
```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/linux-clang.toolchain.cmake ..
cmake --build .
ctest
```

### GCC Linux:
```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/linux-gcc.toolchain.cmake ..
cmake --build .
ctest
```

### Raspberry Pi:
```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/gcc-rpi.toolchain.cmake ..
cmake --build .
ctest
```

### MacOS:
```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/clang-macos.toolchain.cmake ..
cmake --build .
ctest
```

## License

This project is licensed under the [MIT License](LICENSE).
