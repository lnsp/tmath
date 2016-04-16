/*
   This test checks the root functions.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::root;
    using TMath::sqrt;

    assert(root(27.0L, 3.0L), 3.0L, "root(27, 3) == 3");
    assert(root(1.0L, 1.0L), 1.0L, "root(1, 1) == 1");

    assert(sqrt(4.0L), 2.0L, "sqrt(4) == 2");
    assert(sqrt(9.0L), 3.0L, "sqrt(9) == 3");
    assert(sqrt(1.0L), 1.0L, "sqrt(1) == 1");

	return 0;
}
