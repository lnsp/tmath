/*
   This test checks the cosine, arccosine and hyperbolic cosine function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::cos;
    using TMath::acos;
    using TMath::cosh;
    using TMath::PI;

	assert(cos(0.0), 1, "cos(0) == 1");
    assert(cos(PI/2.0), 0, "cos(PI/2) == 0");
    assert(cos(PI), -1, "cos(PI) == -1");
    assert(cos(PI * 1.5), 0, "cos(PI * 1.5) == 0");

    assert(acos(0), PI * 0.5, "acos(0) == PI/2");
    assert(acos(0.70711), PI * 0.25, "acos(1/sqrt(2)) == 1/4 PI");
    assert(acos(-0.70711), PI * 0.75, "acos(1/sqrt(2)) == 3/4 PI");

    assert(cosh(0), 1, "cosh(0) == 1");
    assert(cosh(1.31696), 2, "cosh(1.31696) == 2");
    assert(cosh(-1.31696), 2, "cosh(-1.31696) == 2");

	return 0;
}
