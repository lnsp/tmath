/*
   This test checks the secant, arcsecant and hyperbolic secant function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::sec;
	using TMath::asec;
	using TMath::sech;
	using TMath::PI;

	assert(sec(0), 1.0, "sec(0) == 1");
    assert(sec(-PI), -1.0, "sec(-PI) == -1");
    assert(sec(PI), -1.0, "sec(PI) == -1");

    assert(asec(1.41421356237L), PI * 0.25, "asec(sqrt(2)) == 1/4 PI");
    assert(asec(-1.41421356237L), PI * 0.75, "asec(-sqrt(2)) == 3/4 PI");

    assert(sech(0), 1.0, "sech(0) == 1");
    assert(sech(1.31696), 0.5, "sech(1.31696) == 0.5");
    assert(sech(-1.31696), 0.5, "sech(-1.31696) == 0.5");

	return 0;
}
