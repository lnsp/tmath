/*
   This test checks the sine, arcsine and hyperbolic cosine function.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::cos;
    using TMath::acos;
    using TMath::cosh;
    using TMath::PI;
    using TMath::E;

	assert(cos(0.0), 1, "cos(0) == 1");
    assert(cos(PI/2.0), 0, "cos(PI/2) == 0");
    assert(cos(PI), -1, "cos(PI) == -1");
    assert(cos(PI * 1.5), 0, "cos(PI * 1.5) == 0");

    assert(acos(0), PI/2.0, "acos(0) == PI/2");
    assert(acos(1), 0, "acos(1) == 0");
    assert(acos(-1), PI, "acos(-1) == PI");

    assert(cosh(0), 1, "cosh(0) == 1");
    assert(cosh(1.675), E, "cosh(1.675) == e");
    assert(cosh(-1.675), E, "cosh(-1.675) == e");

	return 0;
}
