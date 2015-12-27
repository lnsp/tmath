/*
   This test checks the sine, arcsine and hyperbolic sine function.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using namespace TMath;

	assert(sin(0), 0, "sin(0) == 0");
	assert(sin(PI/2.0), 1.0, "sin(PI/2) == 1");
	assert(sin(PI), 0.0, "sin(PI) == 0");
	assert(sin(1.5 * PI), -1.0, "sin(1.5 * PI) == -1");
	assert(sin(2.0 * PI), 0.0, "sin(2 * PI) == 0");

	assert(asin(0), 0, "asin(0) == 0");
	assert(asin(1.0), PI/2.0, "asin(1) == PI/2");
	assert(asin(-1.0), 1.5 * PI, "asin(-1) == 1.5 * PI");

	assert(sinh(0), 0, "sinh(0) == 0");
	assert(sinh(0.88137), 1.0, "sinh(0.88137) == 1");
	assert(sinh(-0.88137), -1.0, "sinh(-0.88137) == -1");

	return 0;
}
