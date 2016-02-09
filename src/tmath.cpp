#include "tmath.hpp"
#include <cmath>

/* ================================ SINE ======================================== */
TMath::DOUBLE TMath::sin(DOUBLE x)
{
	x = mod(x + PI, 2 * PI) - PI;
	DOUBLE r = 0;
	for (LONG n = 0; n <= 8L; n++) {
		r += pow(DOUBLE(-1), n) * pow(x, 2 * n + 1) / fac(2 * n + 1);
	}
	return r;
}
TMath::DOUBLE TMath::asin(DOUBLE x)
{
	DOUBLE r = 0;
	DOUBLE delta = 1;
	for (LONG n = 1; delta > 1e-6; n++)
	{
		LONG odd = 2 * n - 1;
		DOUBLE oddf = oddfacd(odd - 2);
		DOUBLE f = facd(odd);
		DOUBLE p = pow(x, odd);
		DOUBLE d = p / f * oddf * oddf;
		delta = abs(d);
		r += p / f * oddf * oddf;
	}
	return r;
}
TMath::DOUBLE TMath::sinh(DOUBLE x)
{
	return 0.5 * (exp(x) - exp(-x));
}
/* ================================ COSINE ======================================== */
TMath::DOUBLE TMath::cos(DOUBLE x)
{
	x = mod(x + PI, 2 * PI) - PI;
	DOUBLE r = 0;
	for (LONG n = 0; n <= 8L; n++) {
		r += pow(DOUBLE(-1.0), n) * pow(x, 2 * n) / fac(2 * n);
	}
	return r;
}
TMath::DOUBLE TMath::acos(DOUBLE x)
{
	return PI / 2 - asin(x);
}
TMath::DOUBLE TMath::cosh(DOUBLE x)
{
	return 0.5 * (exp(x) + exp(-x));
}
/* ================================ TANGENT ======================================== */
TMath::DOUBLE TMath::tan(DOUBLE x)
{
	return sin(x) / cos(x);
}
TMath::DOUBLE TMath::atan(DOUBLE x)
{
	DOUBLE r = 0;
	DOUBLE delta = 1;
	for (LONG n = 0; delta > 1e-4; n++)
	{
		LONG odd = 2 * n + 1;
		DOUBLE d = DOUBLE(pow(-1LL, n)) * pow(x, odd) / DOUBLE(odd);
		delta = abs(d);
		r += d;
	}
	return r;
}
TMath::DOUBLE TMath::tanh(DOUBLE x)
{
	return sinh(x) / cosh(x);
}
/* ================================ COTANGENT ======================================== */
TMath::DOUBLE TMath::cot(DOUBLE x)
{
	return cos(x) / sin(x);
}
TMath::DOUBLE TMath::acot(DOUBLE x)
{
	return PI / 2 - atan(x);
}
TMath::DOUBLE TMath::coth(DOUBLE x)
{
	return cosh(x) / sinh(x);
}
/* ================================ SECANT ======================================== */
TMath::DOUBLE TMath::sec(DOUBLE x)
{
	return 1 / cos(x);
}
TMath::DOUBLE TMath::asec(DOUBLE x)
{
	return acos(1 / x);
}
TMath::DOUBLE TMath::sech(DOUBLE x)
{
	return 1 / cosh(x);
}
/* ================================ COSECANT ======================================== */
TMath::DOUBLE TMath::csc(DOUBLE x)
{
	return 1 / sin(x);
}
TMath::DOUBLE TMath::acsc(DOUBLE x)
{
	return asin(1 / x);
}
TMath::DOUBLE TMath::csch(DOUBLE x)
{
	return 1 / sinh(x);
}
/* ================================= FLOOR, CEIL AND MODULO ======================================== */
TMath::LONG TMath::floor(DOUBLE x)
{
	LONG truncated = LONG(x);
	if (x < 0) {
		if (truncated > x) {
			return truncated - 1;
		} else {
			return truncated;
		}
	}
	else {
		return truncated;
	}
}
TMath::LONG TMath::ceil(DOUBLE x)
{
	LONG truncated = LONG(x);
	if (x < 0) {
		return truncated;
	} else {
		return truncated + 1;
	}
}
TMath::DOUBLE TMath::mod(DOUBLE x, DOUBLE y)
{
	return y * ((x / y) - floor(x / y));
}
/* =============================== EXPONENTIAL FUNCTION, SQRT, LOGARITHM ======================= */
TMath::DOUBLE TMath::exp(DOUBLE x)
{
	DOUBLE r = 0;
	for (LONG n = 0; n <= 15L; n++)
	{
		r += pow(x, n) / facd(n);
	}
	return r;
}
TMath::DOUBLE TMath::sqrt(DOUBLE x)
{
	return root(x, 2);
}
TMath::DOUBLE TMath::root(DOUBLE x, DOUBLE n)
{
	return pow(x, 1 / n);
}
TMath::DOUBLE TMath::ln(DOUBLE x)
{
	x = (x - 1) / (x + 1);
	DOUBLE r = 0;
	for (LONG n = 0; n <= 100L; n++)
	{
		r += 2 * pow(x, 2 * n + 1) / (2 * n + 1);
	}
	return r;
}
TMath::DOUBLE TMath::lg(DOUBLE x)
{
	return ln(x) / ln(10);
}
TMath::DOUBLE TMath::lb(DOUBLE x)
{
	return ln(x) / ln(2);
}
TMath::DOUBLE TMath::log(DOUBLE x, DOUBLE n)
{
	return ln(x) / ln(n);
}
/* =================================== POWER FUNCTIONS =====================================================*/
TMath::DOUBLE TMath::pow(DOUBLE x, LONG n)
{
	if (n < 0) {
		return 1 / pow(x, -n);
	}

	DOUBLE r = 1;
	for (LONG i = 1; i <= n; i++)
	{
		r *= x;
	}
	return r;
}

TMath::LONG TMath::pow(LONG x, LONG n)
{
	if (n < 0) {
		return 1 / pow(x, -n);
	}

	LONG r = 1;
	for (LONG i = 1; i <= n; i++)
	{
		r *= x;
	}
	return r;
}
TMath::DOUBLE TMath::pow(DOUBLE x, DOUBLE n)
{
	return exp(n * ln(x));
}
/* ========================================== FACULTY ============================================*/
TMath::LONG TMath::fac(LONG n) {
	LONG r = 1;
	for (LONG i = 2; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
TMath::DOUBLE TMath::facd(LONG n) {
	DOUBLE r = 1;
	for (LONG i = 2; i <= n; i++) {
		r *= DOUBLE(i);
	}
	return r;
}
TMath::LONG TMath::oddfac(LONG n) {
	LONG r = 1;
	for (LONG i = 3; i <= n; i += 2) {
		r *= i;
	}
	return r;
}
TMath::DOUBLE TMath::oddfacd(LONG n) {
	DOUBLE r = 1;
	for (LONG i = 3; i <= n; i += 2) {
		r *= DOUBLE(i);
	}
	return r;
}
TMath::DOUBLE TMath::abs(DOUBLE x) {
	if (x < 0) return -x;
	else return x;
}

/* ====================================== COMPARISONS ==========*/
TMath::DOUBLE TMath::equal(DOUBLE x, DOUBLE y) {
	return equal(x, y, EQUAL_EPSILON);
}
TMath::DOUBLE TMath::equal(DOUBLE x, DOUBLE y, DOUBLE eps) {
	return std::fabs(x - y) < eps;
}

/* ========================================== DEGREE / RADIANT CONVERSION ================================*/
TMath::DOUBLE TMath::rad(DOUBLE deg)
{
	return PI / 180 * deg;
}
TMath::DOUBLE TMath::deg(DOUBLE rad)
{
	return 180 / PI * rad;
}
/* ======================================== VECTOR IMPLEMENTATIONS =====================================*/

int TMath::Vector::checkDimensions(Vector a) {
	int mdim = dim();
	if (mdim != a.dim()) throw TMath::MISM_DIM_ERR;
	return mdim;
}

TMath::DOUBLE& TMath::Vector::operator[](int i) {
	return elements.at(i);
};

TMath::Vector TMath::Vector::operator+(Vector a) {
	int d = checkDimensions(a);
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) + a[i];
	}
	return b;
};

TMath::Vector TMath::Vector::operator-(Vector a) {
	int d = checkDimensions(a);
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) - a[i];
	}
	return b;
};

TMath::Vector TMath::Vector::operator*(DOUBLE scalar) {
	int d = dim();
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = elements.at(i) * scalar;
	}
	return b;
};

TMath::Vector TMath::Vector::operator/(DOUBLE scalar) {
	int d = dim();
	Vector b(d);
	for (unsigned int i = 0; i < d; i++) {
		b[i] = this->elements.at(i) / scalar;
	}
	return b;
};

bool TMath::Vector::equal(Vector a, DOUBLE eps) {
	int d = checkDimensions(a);
	for (unsigned int i = 0; i < d; i++) {
		if (!TMath::equal(elements.at(i), a[i], eps)) {
			return false;
		}
	}
	return true;
};

bool TMath::Vector::operator==(Vector a) {
	int d = checkDimensions(a);
	return this->equal(a, EQUAL_EPSILON);
};

TMath::DOUBLE TMath::Vector::dot(Vector a) {
	int d = checkDimensions(a);
	Vector b(d);
	DOUBLE sum = 0;
	for (unsigned int i = 0; i < d; i++) sum += elements.at(i) * a[i];
	return sum;
};

TMath::Vector TMath::Vector::cross(Vector a) {
	int d = checkDimensions(a);
	return Vector(d);
};

TMath::DOUBLE TMath::Vector::sum() {
	int d = dim();
	DOUBLE sum = 0;
	for (unsigned int i = 0; i < d; i++) sum += elements[i];
	return sum;
};

int TMath::Vector::dim() {
	return elements.size();
}
