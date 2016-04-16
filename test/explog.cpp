/*
   This test checks the exp, ln, lg, lb and log function.
 */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMath::exp;
    using TMath::E;
    using TMath::ln;
    using TMath::lb;
    using TMath::lg;
    using TMath::log;

	assert(exp(0.0), 1.0, "exp(0) == 1");
    assert(exp(1.0), E, "exp(1) == e");
    assert(exp(2.0), E * E, "exp(2) == e*e");
    assert(exp(-1.0), 1.0 / E, "exp(-1) == 1/e");

    assert(ln(1), 0.0, "ln(1) == 0");
    assert(ln(E), 1.0, "ln(e) == 1");
    assert(ln(1.0 / E), -1.0, "ln(1/e) == -1");

    assert(lb(2), 1.0, "lb(2) == 1");
    assert(lb(4), 2.0, "lb(4) == 2");
    assert(lb(16), 4.0, "lb(128) == 4");

    assert(lg(10), 1.0, "lg(10) == 1");
    assert(lg(1), 0.0, "lg(1) == 0");
    assert(lg(100), 2.0, "lg(100) == 2", 0.01);

    assert(log(E, E), 1.0, "log_e(e) == 1");
    assert(log(1, E), 0.0, "log_e(1) == 0");
    assert(log(27, 3), 3.0, "log_3(27) == 3");

	return 0;
}
