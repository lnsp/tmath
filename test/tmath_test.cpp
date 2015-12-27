#include "tmath_test.hpp"
#include <iostream>
#include <cstdlib>

bool TMathTest::equal(TMath::DOUBLE x, TMath::DOUBLE y, TMath::DOUBLE tolerance) {
	if (x - tolerance <= y && x + tolerance >= y) return true;
	else return false;
}

bool TMathTest::equal(TMath::DOUBLE x, TMath::DOUBLE y) {
    return equal(x, y, 0.001);
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression) {
    if (!equal(value, correct)) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
		std::cout << value << " is not nearly equal " << correct << std::endl;
        exit(1);
    }
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression, TMath::DOUBLE tolerance) {
    if (!equal(value, correct, tolerance)) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
		std::cout << value << " is not nearly equal " << correct << std::endl;
        exit(1);
    }
}
