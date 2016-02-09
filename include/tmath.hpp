#ifndef _TMATH_HPP
#define _TMATH_HPP

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cmath>

namespace TMath {
typedef long long LONG;
typedef long double DOUBLE;
const DOUBLE PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
const DOUBLE E =  2.718281828459045235360287471352662497757247093699959574966967627724076630354;
const DOUBLE EQUAL_EPSILON = 1e-7;
const char MISM_DIM_ERR[] = "Mismatched dimensions";

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
	std::vector<DOUBLE> elements {0};
	int checkDimensions(Vector a);
public:
	Vector(std::initializer_list<TMath::DOUBLE> list) : elements(list) {}
	Vector(int d) : elements(d) {}
	DOUBLE& operator[](int i);
	Vector operator+(Vector);
	Vector operator-(Vector);
	Vector operator*(DOUBLE);
	Vector operator/(DOUBLE);
	bool equal(Vector, DOUBLE eps);
	bool operator==(Vector);
	DOUBLE dot(Vector);
	Vector cross(Vector);
	DOUBLE sum();
	Vector norm();
	DOUBLE length();
	int dim();
};
}

#endif
