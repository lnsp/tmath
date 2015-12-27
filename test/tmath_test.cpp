#include "tmath_test.hpp"
#include <iostream>
#include <cstdlib>

bool TMathTest::equal(TMath::DOUBLE x, TMath::DOUBLE y, TMath::DOUBLE tolerance) {
	if (x - tolerance <= y && x + tolerance >= y) return true;
	else return false;
}

bool TMathTest::equal(TMath::DOUBLE x, TMath::DOUBLE y) {
    return equal(x, y, 0.000001);
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression) {
    if (!equal(value, correct)) {
        std::cout << expression << "failed" << std::endl;
        exit(1);
    }
}
