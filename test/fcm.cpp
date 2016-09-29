/* FLOOR, CEIL AND MODULO NEED TESTS. */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(void) {
	using TMathTest::assert;

	// testing floor
	using TMath::floor;
	assert(floor(0.0), 0, "floor(0.0) == 0");
	assert(floor(0.25), 0, "floor(0.25) == 0");
	assert(floor(1.0), 1, "floor(1.0) == 1");
	assert(floor(-1.0), -1, "floor(-1.0) == -1");
	assert(floor(-1.25), -2, "floor(-1.25) == -2");

	// testing ceil
	using TMath::ceil;
	assert(ceil(0.0), 0, "ceil(0.0) == 0");
	assert(ceil(0.25), 1, "ceil(0.25) == 1");
	assert(ceil(1.0), 1, "ceil(1.0) == 1");
	assert(ceil(-1.0), -1, "ceil(-1.0) == -1");
	assert(ceil(-1.25), -1, "ceil(-1.25) == -1");

	// testing mod
	using TMath::mod;
	assert(mod(3.0, 4.0), 3.0, "mod(3.0, 4.0) == 3.0");
	assert(mod(4.0, 4.0), 0.0, "mod(4.0, 4.0) == 0.0");
	assert(mod(-2.0, 3.0), 1.0, "mod(-2.0, 3.0) == 1.0");
	assert(mod(0.25, 0.75), 0.25, "mod(0.25, 0.75) == 0.25");
	assert(mod(-0.9, -0.6), -0.3, "mod(-0.9, -0.6) == -0.3");

	return 0;
}