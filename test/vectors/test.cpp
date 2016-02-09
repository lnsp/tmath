/*
   This test checks the vector functionality.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
    using TMathTest::assertTrue;
    using TMath::Vector;

    assertTrue(TMath::Vector<3>{0, 0, 0} == TMath::Vector<3>(), "Vector{0, 0, 0} == Vector()");
	return 0;
}
