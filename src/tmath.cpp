#include "tmath.hpp"

/* ================================ SINE ======================================== */
TMath::DOUBLE TMath::sin(const DOUBLE &_x)
{
	const DOUBLE x = mod(_x + PI, 2 * PI) - PI;
	DOUBLE r = 0;
	for (LONG n = 0; n <= 8L; n++) {
		r += pow(DOUBLE(-1), n) * pow(x, 2 * n + 1) / fac(2 * n + 1);
	}
	return r;
}
TMath::DOUBLE TMath::asin(const DOUBLE &x)
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
TMath::DOUBLE TMath::sinh(const DOUBLE &x)
{
	return 0.5 * (exp(x) - exp(-x));
}
/* ================================ COSINE ======================================== */
TMath::DOUBLE TMath::cos(const DOUBLE &_x)
{
	const DOUBLE x = mod(_x + PI, 2 * PI) - PI;
	DOUBLE r = 0;
	for (LONG n = 0; n <= 8L; n++) {
		r += pow(DOUBLE(-1.0), n) * pow(x, 2 * n) / fac(2 * n);
	}
	return r;
}
TMath::DOUBLE TMath::acos(const DOUBLE &x)
{
	return PI / 2 - asin(x);
}
TMath::DOUBLE TMath::cosh(const DOUBLE &x)
{
	return 0.5 * (exp(x) + exp(-x));
}
/* ================================ TANGENT ======================================== */
TMath::DOUBLE TMath::tan(const DOUBLE &x)
{
	return sin(x) / cos(x);
}
TMath::DOUBLE TMath::atan(const DOUBLE &x)
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
TMath::DOUBLE TMath::tanh(const DOUBLE &x)
{
	return sinh(x) / cosh(x);
}
/* ================================ COTANGENT ======================================== */
TMath::DOUBLE TMath::cot(const DOUBLE &x)
{
	return cos(x) / sin(x);
}
TMath::DOUBLE TMath::acot(const DOUBLE &x)
{
	return PI / 2 - atan(x);
}
TMath::DOUBLE TMath::coth(const DOUBLE &x)
{
	return cosh(x) / sinh(x);
}
/* ================================ SECANT ======================================== */
TMath::DOUBLE TMath::sec(const DOUBLE &x)
{
	return 1 / cos(x);
}
TMath::DOUBLE TMath::asec(const DOUBLE &x)
{
	return acos(1 / x);
}
TMath::DOUBLE TMath::sech(const DOUBLE &x)
{
	return 1 / cosh(x);
}
/* ================================ COSECANT ======================================== */
TMath::DOUBLE TMath::csc(const DOUBLE &x)
{
	return 1 / sin(x);
}
TMath::DOUBLE TMath::acsc(const DOUBLE &x)
{
	return asin(1 / x);
}
TMath::DOUBLE TMath::csch(const DOUBLE &x)
{
	return 1 / sinh(x);
}
/* ================================= FLOOR, CEIL AND MODULO ======================================== */
TMath::LONG TMath::floor(const DOUBLE &x)
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
TMath::LONG TMath::ceil(const DOUBLE &x)
{
	LONG truncated = LONG(x);
	if (x < 0) {
		return truncated;
	} else {
		return truncated + 1;
	}
}
TMath::DOUBLE TMath::mod(const DOUBLE &x, const DOUBLE &y)
{
	return y * ((x / y) - floor(x / y));
}
/* =============================== EXPONENTIAL FUNCTION, SQRT, LOGARITHM ======================= */
TMath::DOUBLE TMath::exp(const DOUBLE &x)
{
	DOUBLE r = 0;
	for (LONG n = 0; n <= 15L; n++)
	{
		r += pow(x, n) / facd(n);
	}
	return r;
}
TMath::DOUBLE TMath::sqrt(const DOUBLE &x)
{
	return root(x, 2);
}
TMath::DOUBLE TMath::root(const DOUBLE &x, const DOUBLE &n)
{
	return pow(x, 1 / n);
}
TMath::DOUBLE TMath::ln(const DOUBLE &_x)
{
	const DOUBLE x = (_x - 1) / (_x + 1);
	DOUBLE r = 0;
	for (LONG n = 0; n <= 100L; n++)
	{
		r += 2 * pow(x, 2 * n + 1) / (2 * n + 1);
	}
	return r;
}
TMath::DOUBLE TMath::lg(const DOUBLE &x)
{
	return ln(x) / ln(10);
}
TMath::DOUBLE TMath::lb(const DOUBLE &x)
{
	return ln(x) / ln(2);
}
TMath::DOUBLE TMath::log(const DOUBLE &x, const DOUBLE &n)
{
	return ln(x) / ln(n);
}
/* =================================== POWER FUNCTIONS =====================================================*/
TMath::DOUBLE TMath::pow(const DOUBLE &x, const LONG &n)
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

TMath::LONG TMath::pow(const LONG &x, const LONG &n)
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
TMath::DOUBLE TMath::pow(const DOUBLE &x, const DOUBLE &n)
{
	return exp(n * ln(x));
}
/* ========================================== FACULTY ============================================*/
TMath::LONG TMath::fac(const LONG &n) {
	LONG r = 1;
	for (LONG i = 2; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
TMath::DOUBLE TMath::facd(const LONG &n) {
	DOUBLE r = 1;
	for (LONG i = 2; i <= n; i++) {
		r *= DOUBLE(i);
	}
	return r;
}
TMath::LONG TMath::oddfac(const LONG &n) {
	LONG r = 1;
	for (LONG i = 3; i <= n; i += 2) {
		r *= i;
	}
	return r;
}
TMath::DOUBLE TMath::oddfacd(const LONG &n) {
	DOUBLE r = 1;
	for (LONG i = 3; i <= n; i += 2) {
		r *= DOUBLE(i);
	}
	return r;
}
TMath::DOUBLE TMath::abs(const DOUBLE &x) {
	if (x < 0) return -x;
	else return x;
}
/* ========================================== DEGREE / RADIANT CONVERSION ================================*/
TMath::DOUBLE TMath::rad(const DOUBLE &deg)
{
	return PI / 180 * deg;
}
TMath::DOUBLE TMath::deg(const DOUBLE &rad)
{
	return 180 / PI * rad;
}
