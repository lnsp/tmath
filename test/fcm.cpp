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

	return 0;
}