# CurveLib

This program is designed to implement support for a hierarchy of 3D curves. It supports three types of 3D geometric curves - circles, ellipses, and 3D helixes. Each curve is able to return a 3D point and a first derivative (3D vector) per parameter t along the curve.

## Tasks

1. Firstly, populate a container of objects of these types created in a random manner with random parameters.
2. Next, print the coordinates of points and derivatives of all curves in the container at t=PI/4.
3. Then, populate a second container that contains only circles from the first container. Make sure the second container shares circles of the first one, e.g. via pointers.
4. Sort the second container in ascending order of circles' radii.
5. Finally, compute the total sum of radii of all curves in the second container.

### Additional Optional Requirements

1. The implementation can be split into a library of curves (.dll or .so) and an executable that uses the API of this library.
2. The computation of the total sum of radii can be implemented using parallel computations (e.g. OpenMP or Intel TBB library).

## Requirements to the Implementation

1. The implementation must use virtual methods.
2. There should be no explicit memory deallocation or memory leaks.
3. Curves must be physically correct (e.g. radii must be positive).
4. Containers and sorting must be implemented using the STL (C++ Standard Template Library).
5. The implementation may use constructs of C++11 or higher.
6. The code must compile with any compiler of your choice (gcc, Visual C++, etc).

## Curve Definitions

- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- A circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- An ellipse is planar in the plane XoY and is defined by its two radii, along the X and Y axes.
- A helix is spatial and is defined by its radius and step. It takes 2 * PI in parametric space to make a round, i.e. any point on the helix satisfies the condition C(t + 2*PI) = C(t) + {0, 0, step}.

## Dependencies

This project depends on C++14 compatible compiler (GCC (v7+), Clang (v5+)).

## Documentation

In this repository, you can localy generate Doxygen documentation using the provided `Doxyfile`.

1. Make sure Doxygen is installed on your machine. You can download it from [here](https://www.doxygen.nl/download.html) and follow their installation instructions.
2. Run the following command:
   ```bash
   doxygen Doxyfile
   ```
3. Wait for the process to complete. The generated HTML documentation will be placed in the configured output directory`./html/`.
4. You can now open the generated `index.html` file in your web browser to access the generated Doxygen documentation.

_Note: If you encounter any issues during the generation process, make sure to check the content of the `Doxyfile` and verify that all necessary configuration options are properly set._

_For detailed information about configuring Doxygen and customization options, refer to the official [Doxygen documentation](https://www.doxygen.nl/manual/index.html)._

## Building

1. Create a new directory and navigate into it by running the following command in your terminal:
```
mkdir build && cd build
```

2. If your gcc compiler **is C++17 compatible**, simply type the following command to generate necessary build files using CMake:
```
cmake ..
```
3. After configuration, proceed with building the project by typing the following command:
```
cmake --build .
```

4. After successfully completing the previous steps, you will find the `MyApp` executable located in the main project folder.
