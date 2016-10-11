/*
This test checks the matrix functionality.
*/

#include "tmath.hpp"
#include "tmath_test.hpp"

int main(int argc, char const *argv[]) {
	using TMathTest::assert;
	using TMathTest::assertTrue;
	using TMathTest::assertError;
	using TMath::DOUBLE;
	using TMath::Matrix;

	Matrix nullMatrix1(1, 1);
	Matrix nullMatrix2{{0}};
	Matrix identityMatrix{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix reverseMatrix{{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
	Matrix valueMatrix{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
	Matrix nullMatrix3(3, 3);

	// Check for constructor errors
	assert(nullMatrix1, nullMatrix2, "{{0}} == Matrix(1, 1)");
	assertTrue(!(nullMatrix1 != nullMatrix2), "!{{0}} != Matrix(1, 1)");
	assertError([&](){ nullMatrix1 == identityMatrix; }, "Dimension mismatch by 1x1 == 3x3");
	assertError([&](){ nullMatrix1 != identityMatrix; }, "Dimension mismatch by 1x1 == 3x3");
	assertError([&](){ Matrix(0, 0); }, "Empty matrix constructor using dimensions");
	assertError([&](){ Matrix{}; }, "Empty matrix constructor using initializer list");

	// Check for copy constructor
	assert(identityMatrix, Matrix(identityMatrix), "m == Matrix(m)");
	assert(nullMatrix1, Matrix(nullMatrix2), "{{0}} == Matrix({{0}})");

	// Check for access operator
	assertTrue(nullMatrix1[0][0] == 0, "{{0}}[0][0] == 0");
	assertTrue(identityMatrix[0][0] == 1, "Identity[0][0] == 1");
	assertTrue(identityMatrix[1][0] == 0, "Identity[1][0] == 0");
	assertTrue(identityMatrix[1][1] == 1, "Identity[1][1] == 1");

	// Check for width and heiht
	assert(nullMatrix1.width(), 1, "{{0}}.width() == 1");
	assert(nullMatrix2.height(), 1, "Matrix(1, 1).height() == 1");
	assert(identityMatrix.width(), 3, "Identity.width() == 3");
	assert(identityMatrix.height(), 3, "Identity.height() == 3");

	// Check for to_string
	assertTrue(nullMatrix1.to_string() == "{[0]}", "str({{0}}) == '{[0]}'");
	assertTrue(identityMatrix.to_string() == "{[1, 0, 0], [0, 1, 0], [0, 0, 1]}", "str(Identity) == '{[1, 0, 0], [0, 1, 0], [0, 0, 1]}'");

	// Check for matrix + matrix
	assertError([&](){ nullMatrix1 + identityMatrix; }, "Dimension mismatch by 1x1 + 3x3");
	assert(nullMatrix1 + nullMatrix2, nullMatrix1, "{{0}} + Matrix(1, 1) == {{0}}");
	assert(identityMatrix + identityMatrix, valueMatrix, "Identity + Identity = 2*Identity");
	assert(reverseMatrix + identityMatrix, nullMatrix3, "Identity + (-Identity) = Matrix(3, 3)");

	// Check for matrix - matrix
	assertError([&](){ nullMatrix1 - identityMatrix; }, "Dimension mismatch by 1x1 - 3x3");
	assert(nullMatrix1 - nullMatrix2, nullMatrix1, "{{0}} - Matrix(1, 1) == {{0}}");
	assert(identityMatrix - identityMatrix, nullMatrix3, "Identity - Identity = Matrix(3, 3)");
	assert(identityMatrix - reverseMatrix, valueMatrix, "Identity - (-Identity) = 2*Identity");

	return 0;
}
