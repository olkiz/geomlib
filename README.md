![CI](https://github.com/olkiz/geomlib/actions/workflows/ci.yml/badge.svg)

## geomlib
Modern C++23 library for 2D and 3D computational geometry, designed for mapping, spatial indexing, and geometric algorithms.

### Key features:

* Core types: Point2D, Point3D, Line, Polygon, BoundingBox
* Geometry operations: distance, intersection, containment
* Spatial indexing structures (R-Tree, QuadTree — optional)
* Extensible for GIS, robotics, and embedded applications

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

This project is licensed under the **Kyiv Shield License (KSL)**.

- It permits free use, modification, and distribution of the software.
- It **forbids use by citizens, companies, organizations, and governments of aggressor countries against Ukraine** — currently including but not limited to **Russia, Belarus, and Iran**.
- It also forbids use by entities or individuals who do not recognize Ukraine's internationally established borders.

> By using this software, you agree to abide by these conditions.

See the full [LICENSE](./LICENSE) file for details.

![Kyiv Shield License](https://img.shields.io/badge/license-Kyiv%20Shield%20License-blueviolet?style=for-the-badge)
