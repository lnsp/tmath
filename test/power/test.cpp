/*
   This test checks the power functions.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::pow;

    assert(pow(2.0L, 2.0L), 4.0L, "pow(2, 2) == 4");
    assert(pow(2.0L, 0.5L), 1.41421356237L, "pow(2, 0.5) == 1.414");
    assert(pow(2.0L, -1.0L), 0.5L, "pow(2, -1) == 0.5");
    assert(pow(2.0L, 0.0L), 1.0L, "pow(2, 0) == 1");

    assert(pow(2LL, 2LL), 4LL, "pow(2, 2) == 4");
    assert(pow(1LL, -1LL), 1LL, "pow(1, -1) == 1");
    assert(pow(2LL, 0LL), 1LL, "pow(2, 0) == 1");

    assert(pow(0.5L, 2LL), 0.25L, "pow(0.5, 2) == 0.25");
    assert(pow(0.5L, -1LL), 2.0L, "pow(0.5, -1) == 2");
    assert(pow(0.5L, 0LL), 1.0L, "pow(0.5, 0) == 1");

	return 0;
}
