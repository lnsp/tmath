#ifndef _TMATH_HPP
#define _TMATH_HPP

#include <vector>
#include <initializer_list>
#include <string>
#include <utility>

namespace TMath {
// Shortform for long long
typedef long long LONG;
// Shortform for long double
typedef long double DOUBLE;
// A estimation of Pi
const DOUBLE PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
// A estimation of e
const DOUBLE E =  2.718281828459045235360287471352662497757247093699959574966967627724076630354;
// Constant for equality comparison for floating point numbers
const DOUBLE EQUAL_EPSILON = 1e-7;
// Mismatched dimensions error for vectors and matrices
const std::string DIMENSION_ERROR = "Mismatched dimensions";
const std::string EMPTY_MATRIX_ERROR = "Empty matrix";
const std::string OUT_OF_BOUNDS = "Index out of bounds";
// Error if the operation is not applicable
const std::string BAD_OPERATION = "Operation is not applicable";
// Vector length is equal to zero
const std::string ZERO_LENGTH = "Vector has length 0";

LONG floor(const DOUBLE&);
LONG ceil(const DOUBLE&);
DOUBLE mod(const DOUBLE&, const DOUBLE&);

DOUBLE sin(const DOUBLE&);  // sine
DOUBLE asin(const DOUBLE&);  // arcsine
DOUBLE sinh(const DOUBLE&);  // hyperbolic sine

DOUBLE cos(const DOUBLE&);  // cosine
DOUBLE acos(const DOUBLE&);  // arccosine
DOUBLE cosh(const DOUBLE&);  //hyperbolic cosine

DOUBLE tan(const DOUBLE&);  // tangent
DOUBLE atan(const DOUBLE&);  // arctangent
DOUBLE tanh(const DOUBLE&);  // hyperbolic tangent

DOUBLE cot(const DOUBLE&);  // cotangent
DOUBLE acot(const DOUBLE&);  // arccotangent
DOUBLE coth(const DOUBLE&);  // hyperbolic cotangent

DOUBLE sec(const DOUBLE&);  // secant
DOUBLE asec(const DOUBLE&);  // arcsecant
DOUBLE sech(const DOUBLE&);  // hyperbolic secant

DOUBLE csc(const DOUBLE&);  // cosecant
DOUBLE acsc(const DOUBLE&);  // arccosecant
DOUBLE csch(const DOUBLE&);  // hyperbolic cosecant

DOUBLE rad(const DOUBLE&);  // degrees to radians
DOUBLE deg(const DOUBLE&);  // radians to degrees

DOUBLE exp(const DOUBLE&);
DOUBLE sqrt(const DOUBLE&);
DOUBLE root(const DOUBLE&, const DOUBLE&);
DOUBLE ln(const DOUBLE&);
DOUBLE lg(const DOUBLE&);
DOUBLE lb(const DOUBLE&);
DOUBLE log(const DOUBLE&, const DOUBLE&);

DOUBLE pow(const DOUBLE&, const DOUBLE&);
DOUBLE pow(const DOUBLE&, const LONG&);
LONG pow(const LONG&, const LONG&);

LONG fac(const LONG&);
DOUBLE facd(const LONG&);
LONG oddfac(const LONG&);
DOUBLE oddfacd(const LONG&);

DOUBLE abs(const DOUBLE&);
DOUBLE equal(const DOUBLE&, const DOUBLE&);
DOUBLE equal(const DOUBLE&, const DOUBLE&, const DOUBLE&);

class Vector {
private:
	std::vector<DOUBLE> elements;
	int checkDimensions(const Vector&) const;
public:
	Vector() {}
	Vector(std::initializer_list<DOUBLE> list) : elements(list) {}
	Vector(const int& d) : elements(d) {}
	Vector(const Vector& v) : elements(v.elements) {};
	DOUBLE& operator[](const int&);
	DOUBLE at(const int&) const;
	Vector operator+(const Vector&) const;
	Vector operator-() const;
	Vector operator-(const Vector&) const;
	Vector operator*(const DOUBLE&) const;
	Vector operator/(const DOUBLE&) const;
	bool equal(const Vector&, const DOUBLE&) const;
	bool operator==(const Vector&) const;
	bool operator!=(const Vector&) const;
	DOUBLE dot(const Vector&) const;
	Vector cross(const Vector&) const;
	DOUBLE sum() const;
	Vector norm() const;
	DOUBLE length() const;
	int dim() const;
	std::string to_string() const;
};

class Matrix {
private:
	std::vector<Vector> elements;
	std::pair<int, int> validate(const Matrix&) const;
public:
	Matrix(std::initializer_list<std::initializer_list<DOUBLE>>);
	Matrix(const int& width, const int& height);
	Matrix(const Matrix& m);
	Vector& operator[](const int&);
	Vector col(const int&) const;
	Vector row(const int&) const;
	DOUBLE at(const int&, const int&) const;
	bool equal(const Matrix&, const DOUBLE&) const;
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;
	Matrix operator+(const Matrix&) const;
	Matrix operator-(const Matrix&) const;
	Vector operator*(const Vector&) const;
	Matrix operator*(const Matrix&) const;
	int width() const;
	int height() const;
	std::string to_string() const;
};
}

#endif
