# TMath [![Build status](https://travis-ci.org/lnsp/tmath.svg?branch=stable)](https://travis-ci.org/lnsp/tmath)
A small math function collection based on the Taylor expansion series.

## Building the project
- Download the source files from the `master`-tree
- To build the project, you need to have `g++` and `make` installed
- And you need to run `export CC=g++`
- If everything is ready, run `make` and ...
- ... your `libtmath.a` library file is ready in the `lib` folder

## How to use
Just build it as described above, include the header files and link the library. The library uses the types `TMath::DOUBLE`(`long double`) and `TMath::LONG`(`long long`) for parameters and return values.

## What is included?
### Mathematical functions

Function                                | Description
:-------------------------------------: | ---------------------------------------------------------
`sin(DOUBLE x)`                         | sine of x
`asin(DOUBLE x)`                        | arcsine of x
`sinh(DOUBLE x)`                        | hyperbolic sine of x
`cos(DOUBLE x)`                         | cosine of x
`acos(DOUBLE x)`                        | arccosine of x
`cosh(DOUBLE x)`                        | hyperbolic cosine of x
`tan(DOUBLE x)`                         | tangent of x
`atan(DOUBLE x)`                        | arctangent of x
`cot(DOUBLE x)`                         | cotangent of x
`acot(DOUBLE x)`                        | arccotangent of x
`coth(DOUBLE x)`                        | hyperbolic cotangent of x
`sec(DOUBLE x)`                         | secant of x
`asec(DOUBLE x)`                        | arcsecant of x
`sech(DOUBLE x)`                        | hyperbolic secant of x
`cosec(DOUBLE x)`                       | cosecant of x
`acsc(DOUBLE x)`                        | arccosecant of x
`csch(DOUBLE x)`                        | hyperbolic cosecant of x
`floor(DOUBLE x)`                       | next lower integer of x
`ceil(DOUBLE x)`                        | next higher integer of x
`mod(LONG x, LONG y)`                   | the remainder of the division x / y
`exp(DOUBLE x)`                         | natural exponential function
`sqrt(DOUBLE x)`                        | squareroot of x
`root(DOUBLE x, DOUBLE n)`              | n-th root of x
`ln(DOUBLE x)`                          | natural logarithm of x
`lg(DOUBLE x)`                          | common logarithm of x
`lb(DOUBLE x)`                          | binary logarithm of x
`log(DOUBLE x, DOUBLE n)`               | logarithm with base n of x
`pow(DOUBLE x, DOUBLE n)`               | x to the power of n
`pow(LONG x, LONG n)`                   | x to the power of n
`pow(DOUBLE x, LONG n)`                 | x to the power of n
`fac(LONG n)`                           | factorial of n
`facd(LONG n)`                          | factorial of n using floating point
`oddfac(LONG n)`                        | odd-factorial of n
`oddfacd(LONG n)`                       | odd-factorial of n using floating point
`rad(DOUBLE x)`                         | degrees to radiant
`deg(DOUBLE x)`                         | radiant to degrees
`abs(DOUBLE x)`                         | absolute value of x
`equal(DOUBLE x, DOUBLE y)`             | floating-point number equality
`equal(DOUBLE x, DOUBLE y, DOUBLE eps)` | floating-point number equality with a variance of epsilon

### Vector class
To initialize a new vector just use initializer lists (like `Vector {1, 2, 3}`) or create a null-vector using `Vector(n)` (where n is the number of dimensions).

Operation       | Description
--------------- | -------------------------------------------------------------
`a[n]`          | Access the n-th element of the vector `a`
`a + b`         | Adds vector `a` and `b`
`a - b`         | Subtracts vector `a` from `b`
`a * s`         | Scales the vector by the factor `s`
`a / s`         | Scales the vector by the factor `1 / s`
`a == b`        | Tests if vector `a` is equal to `b`
`a != b`        | Tests if vector `a` is not equal to `b`
`a.equal(b, e)` | Tests if the vector `a` is equal to `b` with the accuracy `e`
`a.dot(b)`      | Dot product of `a` and `b`.
`a.cross(b)`    | Cross product of `a` and `b`
`a.norm()`      | Normalized copy of the vector `a`
`a.length()`    | Length of vector `a`
`a.dim()`       | Dimensions of vector `a`
`a.to_string()` | Generates a string representation of the vector `a`

### Matrix class
To initialize a new matrix you can use initializer lists (like `Matrix{{1, 0}, {0, 1}}`) or create a null-matrix using `Matrix(x, y)` (where x is the number of cols and y the number of rows).

Operation       | Description
--------------- | -------------------------------------------------------------
`m[n]`          | Access the n-th row of the matrix
`m[n][x]`       | Access the element at row n and col x
`a + b`         | Add the matrices
`a - b`         | Subtract the matrices
`a.equal(b, e)` | Tests if the matrix `a` is equal to `b` with the accuary `e`
`a == b`        | Tests if the matrix `a` is equal to `b`
`a != b`        | Tests if the matrix `a` is not equal to `b`
`a.width()`     | Get the number of matrix cols
`a.height()`    | Get the number of matrix rows
`a.to_string()` | Generate a string representation of the matrix

## What is planned?
- Statistics
