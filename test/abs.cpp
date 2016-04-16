/*
   This test checks the abs function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::abs;

	assert(abs(0.0), 0.0, "abs(0) == 0");
    assert(abs(1.0), 1.0, "abs(1) == 1");
    assert(abs(-1.0), 1.0, "abs(-1) == 1");

	return 0;
}
