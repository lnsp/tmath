/*
   This test checks the cosecant, arccosecant and hyperbolic cosecant function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::csc;
	using TMath::acsc;
	using TMath::csch;
	using TMath::PI;

	assert(csc(PI / 2.0), 1.0, "csc(PI/2) == 1");
    assert(csc(-PI / 2.0), -1.0, "csc(-PI/2) == -1");

	assert(acsc(1.1884), 1.0, "acsc(1.1884) == 1");
    assert(acsc(-1.1884), -1.0, "acsc(-1.1884) == -1");

	assert(csch(0.88137), 1.0, "csch(0.88137) == 1.0");
    assert(csch(-0.88137), -1.0, "csch(-0.88137) == -1.0");

	return 0;
}
