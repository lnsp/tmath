/*
   This test checks the tangent, arctangent and hyperbolic tangent function.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::tan;
	using TMath::atan;
	using TMath::tanh;
	using TMath::PI;

	assert(tan(0), 0, "tan(0) == 0");
	assert(tan(PI/4.0), 1.0, "tan(PI/4) == 1");
	assert(tan(-PI/4.0), -1.0, "tan(-PI/4) == -1");

	assert(atan(0), 0, "atan(0) == 0");
	assert(atan(1), PI/4.0, "atan(1) == PI/4");
	assert(atan(-1), -PI/4.0, "atan(-1) == -PI/4");

	assert(tanh(0), 0, "tanh(0) == 0");
	assert(tanh(0.549306), 0.5, "tanh(0.549306) == 0.5");
	assert(tanh(-0.549306), -0.5, "tanh(-0.549306) == -0.5");

	return 0;
}
