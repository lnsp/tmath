/*
   This test checks the cotangent, arccotangent and hyperbolic cotangent function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::cot;
	using TMath::acot;
	using TMath::coth;
	using TMath::PI;

	assert(cot(PI / 2.0), 0.0, "cot(PI/2) == 0");
    assert(cot(-PI / 2.0), 0.0, "cot(-PI/2) == 0");

	assert(acot(0), PI * 0.5, "acot(0) == 1/2 PI");
    assert(acot(1.0), PI * 0.25, "acot(1) == 1/4 PI");
    assert(acot(-1.0), PI * 0.75, "acot(-1) == 3/4 PI");

    assert(coth(0.54931), 2.0, "coth(0.54931) == 2.0");
    assert(coth(-0.54931), -2.0, "coth(-0.54931) == -2.0");

	return 0;
}
