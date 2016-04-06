#ifndef _TMATH_HPP
#define _TMATH_HPP

#include <vector>
#include <initializer_list>
#include <string>

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
// Error if the operation is not applicable
const std::string BAD_OPERATION = "Operation is not applicable";
// Vector length is equal to zero
const std::string ZERO_LENGTH = "Vector has length 0";

LONG floor(DOUBLE x);
LONG ceil(DOUBLE x);
DOUBLE mod(DOUBLE x, DOUBLE y);

DOUBLE sin(DOUBLE x);  // sine
DOUBLE asin(DOUBLE x);  // arcsine
DOUBLE sinh(DOUBLE x);  // hyperbolic sine

DOUBLE cos(DOUBLE x);  // cosine
DOUBLE acos(DOUBLE x);  // arccosine
DOUBLE cosh(DOUBLE x);  //hyperbolic cosine

DOUBLE tan(DOUBLE x);  // tangent
DOUBLE atan(DOUBLE x);  // arctangent
DOUBLE tanh(DOUBLE x);  // hyperbolic tangent

DOUBLE cot(DOUBLE x);  // cotangent
DOUBLE acot(DOUBLE x);  // arccotangent
DOUBLE coth(DOUBLE x);  // hyperbolic cotangent

DOUBLE sec(DOUBLE x);  // secant
DOUBLE asec(DOUBLE x);  // arcsecant
DOUBLE sech(DOUBLE x);  // hyperbolic secant

DOUBLE csc(DOUBLE x);  // cosecant
DOUBLE acsc(DOUBLE x);  // arccosecant
DOUBLE csch(DOUBLE x);  // hyperbolic cosecant

DOUBLE rad(DOUBLE deg);  // degrees to radians
DOUBLE deg(DOUBLE rad);  // radians to degrees

DOUBLE exp(DOUBLE x);
DOUBLE sqrt(DOUBLE x);
DOUBLE root(DOUBLE x, DOUBLE n);
DOUBLE ln(DOUBLE x);
DOUBLE lg(DOUBLE x);
DOUBLE lb(DOUBLE x);
DOUBLE log(DOUBLE x, DOUBLE n);

DOUBLE pow(DOUBLE x, DOUBLE n);
DOUBLE pow(DOUBLE x, LONG n);
LONG pow(LONG x, LONG n);

LONG fac(LONG n);
DOUBLE facd(LONG n);
LONG oddfac(LONG n);
DOUBLE oddfacd(LONG n);

DOUBLE abs(DOUBLE x);
DOUBLE equal(DOUBLE x, DOUBLE y);
DOUBLE equal(DOUBLE x, DOUBLE y, DOUBLE eps);

class Vector {
private:
	std::vector<DOUBLE> elements;
	int checkDimensions(const Vector&) const;
public:
	Vector(std::initializer_list<DOUBLE> list) : elements(list) {}
	Vector(const int& d) : elements(d) {}
	Vector(const Vector& v) : elements(v.elements) {};
	DOUBLE& operator[](const int&);
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
}

#endif
