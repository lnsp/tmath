#include "tmath_test.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <functional>

bool TMathTest::equal(TMath::DOUBLE x, TMath::DOUBLE y, TMath::DOUBLE tolerance) {
	if (x - tolerance <= y && x + tolerance >= y) return true;
	else return false;
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression) {
    assert(value, correct, expression, TMathTest::DEFAULT_TOLERANCE);
}

void TMathTest::assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression, TMath::DOUBLE tolerance) {
    if (!equal(value, correct, tolerance)) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
		std::cout << value << " is not nearly equal " << correct << std::endl;
        exit(1);
    } else {
		double deviation = value - correct;
		deviation = deviation < 0 ? -deviation : deviation;
		std::cout << "Test (" << expression << ") passed with deviation of " << deviation << std::endl;
	}
}

void TMathTest::assert(TMath::Matrix a, TMath::Matrix b, std::string expression) {
	assert(a, b, expression, TMathTest::DEFAULT_TOLERANCE);
}

void TMathTest::assert(TMath::Matrix a, TMath::Matrix b, std::string expression, TMath::DOUBLE tolerance) {
	if (!a.equal(b, tolerance)) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
		std::cout << a.to_string() << " is not equal to " << b.to_string() << std::endl;
        exit(1);
    } else {
		std::cout << "Test (" << expression << ") passed" << std::endl;
	}
}

void TMathTest::assert(TMath::Vector a, TMath::Vector b, std::string expression) {
	assert(a, b, expression, TMathTest::DEFAULT_TOLERANCE);
}

void TMathTest::assert(TMath::Vector a, TMath::Vector b, std::string expression, TMath::DOUBLE tolerance) {
	if (!a.equal(b, tolerance)) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
		std::cout << a.to_string() << " is not equal to " << b.to_string() << std::endl;
        exit(1);
    } else {
		std::cout << "Test (" << expression << ") passed" << std::endl;
	}
}

void TMathTest::assertTrue(bool b, std::string expression) {
	if (!b) {
        std::cout << "Assert: " << expression << " failed" << std::endl;
        exit(1);
    } else {
		std::cout << "Test (" << expression << ") passed" << std::endl;
	}
}

void TMathTest::assertError(std::function<void ()> func, std::string expression) {
	try {
		func();
		std::cout << "Assert: " << expression << " failed" << std::endl;
		exit(1);
	} catch (std::string err) {
		std::cout << "Error test (" << expression << ") passed with message '" << err << "'" << std::endl;
	}
};
