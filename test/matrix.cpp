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
	using TMath::Vector;

	Matrix nullMatrix1(1, 1);
	Matrix nullMatrix2{{0}};
	Matrix oneMatrix{{1}};
	Matrix identityMatrix{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	Matrix reverseMatrix{{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
	Matrix valueMatrix{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
	Matrix nullMatrix3(3, 3);
	Vector nullVector1{0};
	Vector nullVector3{0, 0, 0};
	Vector oneVector1{1};
	Vector oneVector2{1, 0, 0};
	Vector oneVector3{1, 1, 1};
	Vector countVector{1, 2, 3};

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
	assert(nullMatrix1.colCount(), 1, "{{0}}.colCount() == 1");
	assert(nullMatrix2.rowCount(), 1, "Matrix(1, 1).rowCount() == 1");
	assert(identityMatrix.colCount(), 3, "Identity.colCount() == 3");
	assert(identityMatrix.rowCount(), 3, "Identity.rowCount() == 3");

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

	// Check for at
	assertError([&](){ nullMatrix1.row(2); }, "Can not access index out of matrix Matrix(1, 1)[2]");
	assertError([&](){ nullMatrix1.col(2); }, "Can not access index out of matrix Matrix(1, 1)[2]");
	assertError([&](){ nullMatrix2.at(2, 2); }, "Can not access index out of matrix {{0}}[2, 2]");
	assert(nullMatrix1.row(0), nullVector1, "Matrix(1, 1)[0] == Vector{0}");
	assert(nullMatrix1.col(0), nullVector1, "Matrix(1, 1)[0] == Vector{0}");
	assert(identityMatrix.row(0), oneVector2, "Identity[0] == Vector{1, 0, 0}");
	assert(identityMatrix.col(0), oneVector2, "Identity[0] == Vector{1, 0, 0}");
	assert(nullMatrix1.at(0, 0), 0, "Matrix(1, 1)[0, 0] == 0");
	assert(identityMatrix.at(2, 2), 1, "Identity[2, 2] == 1");

	// Check for matrix * vector
	assertError([&](){ nullMatrix2 * oneVector2; }, "Can not multiply Matrix(1, 1) with Vector(3)");
	assert(nullMatrix1 * oneVector1, nullVector1, "Matrix(1, 1) * Vector{1} == Vector{0}");
	assert(nullMatrix1 * nullVector1, nullVector1, "Matrix(1, 1) * Vector{0} == Vector{0}");
	assert(identityMatrix * countVector, countVector, "Identity * Vector{1, 2, 3} == Vector{1, 2, 3}");
	assert(reverseMatrix * countVector, -countVector, "ReverseIdentity * Vector{1, 2, 3} == Vector{-1, -2, -3}");

	// Check for matrix * matrix
	assertError([&](){ identityMatrix * nullMatrix1; }, "Can not multiply Matrix(1, 1) with Matrix(3, 3)");
	assertError([&](){ nullMatrix1 * identityMatrix; }, "Can not multiply Matrix(3, 3) with Matrix(1, 1)");
	Matrix valueMatrix1{{3, 2, 1}, {1, 0, 2}};
	Matrix valueMatrix2{{1, 2}, {0, 1}, {4, 0}};
	Matrix valueMatrix3{{1, 2, 3}};
	Matrix valueMatrix4{{1}, {2}, {3}};
	Matrix resultMatrix1{{7, 8}, {9, 2}};
	Matrix resultMatrix2{{14}};
	assert(valueMatrix1 * valueMatrix2, resultMatrix1, "2x3 * 3x2 == 2x2");
	assert(valueMatrix3 * valueMatrix4, resultMatrix2, "1x3 * 3x1 == 1x1");
	assert(valueMatrix3 * identityMatrix, valueMatrix3, "1x3 * Identity == 1x3");
	assert(identityMatrix * valueMatrix4, valueMatrix4, "Identity * 3x1 == 3x1");

	// Check for matrix * scalar and -matrix
	assert(identityMatrix * 2.0, valueMatrix, "Identity * 2 == {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}}");
	assert(nullMatrix1 * 0.0, nullMatrix1, "{{0}} * 0 == {{0}}");
	assert(nullMatrix1 * 1.0, nullMatrix1, "{{0}} * 1 == {{0}}");
	assert(identityMatrix * -1.0, reverseMatrix, "-Identity == Reverse");
	assert(valueMatrix * 0.5, identityMatrix, "0.5 * {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}} == Identity");
	assert(-identityMatrix, reverseMatrix, "-Identity == Reverse");
	assert(-nullMatrix1, nullMatrix1, "-{{0}} == {{0}}");

	// Check for matrix identity
	assert(identityMatrix, Matrix::identity(3), "Identity(3) = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}");
	assert(oneMatrix, Matrix::identity(1), "Identity(1) = {{1}}");

	return 0;
}
