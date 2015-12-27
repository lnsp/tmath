#include "tmath.hpp"

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
	for (LONG n = 0; n <= 8; n++)
	{
		r += pow(DOUBLE(-1), n) * pow(x, 2 * n + 1) / (2 * n + 1);
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
TMath::DOUBLE TMath::cosec(DOUBLE x)
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
		r += pow(x, n) / fac(n);
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
	for (LONG i = 3; i <= n; i++) {
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
/* ========================================== DEGREE / RADIANT CONVERSION ================================*/
TMath::DOUBLE TMath::rad(DOUBLE deg)
{
	return PI / 180 * deg;
}
TMath::DOUBLE TMath::deg(DOUBLE rad)
{
	return 180 / PI * rad;
}
