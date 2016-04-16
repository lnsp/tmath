/*
   This test checks the factorial functions;
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::fac;
    using TMath::facd;
    using TMath::oddfac;
    using TMath::oddfacd;

	assert(fac(1), 1, "fac(1) == 1");
    assert(fac(2), 2, "fac(2) == 2");
    assert(fac(3), 6, "fac(3) == 6");
    assert(fac(4), 24, "fac(4) == 24");

    assert(facd(1), 1.0, "facd(1) == 1.0");
    assert(facd(2), 2.0, "facd(2) == 2.0");
    assert(facd(3), 6.0, "facd(3) == 6.0");
    assert(facd(4), 24.0, "facd(4) == 24.0");

    assert(oddfac(1), 1, "oddfac(1) == 1");
    assert(oddfac(2), 1, "oddfac(2) == 1");
    assert(oddfac(3), 3, "oddfac(3) == 3");
    assert(oddfac(4), 3, "oddfac(4) == 3");
    assert(oddfac(5), 15, "oddfac(5) == 15");

    assert(oddfacd(1), 1.0, "oddfacd(1) == 1.0");
    assert(oddfacd(2), 1.0, "oddfacd(2) == 1.0");
    assert(oddfacd(3), 3.0, "oddfacd(3) == 3.0");
    assert(oddfacd(4), 3.0, "oddfacd(4) == 3.0");
    assert(oddfacd(5), 15.0, "oddfacd(5) == 15.0");

	return 0;
}
