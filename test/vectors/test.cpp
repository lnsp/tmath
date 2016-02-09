/*
   This test checks the vector functionality.
   */

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assertTrue;
	using TMathTest::assertError;
	using TMath::Vector;

	Vector nullVector1 {0, 0, 0};
	Vector nullVector2(3);
	Vector smallVector(0);

	// check equality operator
	assertTrue(nullVector1 == nullVector2, "Vector{0, 0, 0} == Vector(3)");
	assertError([&](){ nullVector1 == smallVector; }, "!! Vector{0, 0, 0} == Vector(0)");
	
	Vector identityVector1 = {1, 0, 0};
	Vector identityVector2 = {0, 1, 0};
	Vector identityVector3 = {0, 0, 1};

	// check unequality operator
	assertTrue(identityVector1 != identityVector2, "Vector{1, 0, 0} != Vector{0, 1, 0}");
	assertError([&](){ identityVector1 != smallVector; }, "!! Vector{1, 0, 0} != Vector(0)");

	Vector vectorSum1 = identityVector1 + identityVector2;
	Vector vectorSum2 = vectorSum1 + identityVector3;
	Vector vectorSum3 = {1, 1, 1};

	// check add operator
	assertTrue(vectorSum2 == vectorSum3, "Vector{1, 0, 0} + Vector{0, 1, 0} + Vector{0, 0, 1} == Vector{1, 1, 1}");
	assertError([&]() { vectorSum1 + smallVector; }, "!! Vector{1, 0, 0} + Vector(0)");

	Vector vectorSub1 = vectorSum1 - identityVector1;
	Vector vectorSub2 = vectorSub1 - identityVector2;
	
	// check subtraction operator
	assertTrue(vectorSub1 == identityVector2, "Vector{1, 1, 0} - Vector{1, 0, 0} == Vector{0, 1, 0}");
	assertError([&](){ vectorSub1 - smallVector; }, "!! Vector{0, 1, 0} - Vector(0)");

	return 0;
}
