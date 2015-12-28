/*
   This test checks the sine, arcsine and hyperbolic sine function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::sin;
	using TMath::asin;
	using TMath::sinh;
	using TMath::PI;

	assert(sin(0), 0, "sin(0) == 0");
	assert(sin(PI/2.0), 1.0, "sin(PI/2) == 1");
	assert(sin(PI), 0.0, "sin(PI) == 0");
	assert(sin(1.5 * PI), -1.0, "sin(1.5 * PI) == -1");
	assert(sin(2.0 * PI), 0.0, "sin(2 * PI) == 0");

	assert(asin(0), 0, "asin(0) == 0");
	assert(asin(0.5), PI/6.0, "asin(0.5) == PI/6");
	assert(asin(-0.5), -PI/6.0, "asin(-0.5) == -PI/6");

	assert(sinh(0), 0, "sinh(0) == 0");
	assert(sinh(0.88137), 1.0, "sinh(0.88137) == 1");
	assert(sinh(-0.88137), -1.0, "sinh(-0.88137) == -1");

	return 0;
}
