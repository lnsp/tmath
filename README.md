# TMath [![Build status](https://travis-ci.org/mooxmirror/tmath.svg?branch=stable)](https://travis-ci.org/mooxmirror/tmath)
A small math function collection based on the Taylor expansion series.

## Building the project
- Download the source files from the `master`-tree
- To build the project, you need to have `g++` and `make` installed
- And you need to run `export CC=g++`
- If everything is ready, run `make all` and ...
- ... your `libtmath.a` library file is ready in the `build` folder

## How to use
Just build it as described above, include the header files and link the library. The library uses the types `TMath::DOUBLE`(`long double`) and `TMath::LONG`(`long long`) for parameters and return values.

## What is included?

Function                   | Description
:------------------------: | -----------------------------------
`sin(DOUBLE x)`            | sine of x
`asin(DOUBLE x)`           | arcsine of x
`sinh(DOUBLE x)`           | hyperbolic sine of x
`cos(DOUBLE x)`            | cosine of x
`acos(DOUBLE x)`           | arccosine of x
`cosh(DOUBLE x)`           | hyperbolic cosine of x
`tan(DOUBLE x)`            | tangent of x
`atan(DOUBLE x)`           | arctangent of x
`cot(DOUBLE x)`            | cotangent of x
`acot(DOUBLE x)`           | arccotangent of x
`coth(DOUBLE x)`           | hyperbolic cotangent of x
`sec(DOUBLE x)`            | secant of x
`asec(DOUBLE x)`           | arcsecant of x
`sech(DOUBLE x)`           | hyperbolic secant of x
`cosec(DOUBLE x)`          | cosecant of x
`acsc(DOUBLE x)`           | arccosecant of x
`csch(DOUBLE x)`           | hyperbolic cosecant of x
`floor(DOUBLE x)`          | next lower integer of x
`ceil(DOUBLE x)`           | next higher integer of x
`mod(LONG x, LONG y)`      | the remainder of the division x / y
`exp(DOUBLE x)`            | natural exponential function
`sqrt(DOUBLE x)`           | squareroot of x
`root(DOUBLE x, DOUBLE n)` | n-th root of x
`ln(DOUBLE x)`             | natural logarithm of x
`lg(DOUBLE x)`             | common logarithm of x
`lb(DOUBLE x)`             | binary logarithm of x
`log(DOUBLE x, DOUBLE n)`  | logarithm with base n of x
`pow(DOUBLE x, DOUBLE n)`  | x to the power of n
`pow(LONG x, LONG n)`      | x to the power of n
`pow(DOUBLE x, LONG n)`    | x to the power of n
`fac(LONG n)`              | factorial of n
`rad(DOUBLE x)`            | degrees to radiant
`deg(DOUBLE x)`            | radiant to degrees

## What is planned?
- Statistics (planned for v0.3)
- Vectors (planned for v0.2)
- Matrices (planned for v0.2)
- Vector operations (planned for v0.2)
- Matrix operations (planned for v0.2)
