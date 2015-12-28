/*
   This test checks the rad-deg conversion functions.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::rad;
    using TMath::deg;
    using TMath::PI;

	assert(rad(0), 0.0, "rad(0) == 0");
    assert(rad(45), PI * 0.25, "rad(45) == 1/4 PI");
    assert(rad(90), PI * 0.5, "rad(90) == 1/2 PI");
    assert(rad(135), PI * 0.75, "rad(135) == 3/4 PI");
    assert(rad(180), PI, "rad(180) == PI");
    assert(rad(270), PI * 1.5, "rad(270) == 3/2 PI");
    assert(rad(360), PI * 2.0, "rad(360) == 2 PI");

    assert(deg(0), 0, "deg(0) == 0");
    assert(deg(PI * 0.25), 45, "deg(1/4 PI) == 45");
    assert(deg(PI * 0.5), 90, "deg(1/2 PI) == 90");
    assert(deg(PI * 0.75), 135, "deg(3/4 PI) == 135");
    assert(deg(PI), 180, "deg(PI) == 180");
    assert(deg(PI * 1.5), 270, "deg(3/2 PI) == 270");
    assert(deg(PI * 2.0), 360, "deg(2 * PI) == 360");

	return 0;
}
