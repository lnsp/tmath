/*
This test checks the matrix functionality.
*/

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assertTrue;
	using TMathTest::assertError;
	using TMath::DOUBLE;
	using TMath::Matrix;

	Matrix nullMatrix1(1, 1);
	Matrix nullMatrix2{{0}};
	
	assertError([&](){ Matrix(0, 0); }, "Empty matrix constructor using dimensions");
	assertError([&](){ Matrix{}; }, "Empty matrix constructor using initializer list");
}
