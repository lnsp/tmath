#include "tmath.h"

/* ================================ SINUS ======================================== */
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
	x = mod(x + 1, 2) - 1;
	DOUBLE r = 0;
	for (LONG n = 0; n <= 8L; n++)
	{
		r += fac(2 * n) / (pow(DOUBLE(2), 2 * n) * pow(fac(n), 2) * (2 * n + 1)) * pow(x, 2 * n + 1);
	}
	return r;
}
TMath::DOUBLE TMath::sinh(DOUBLE x)
{
	return 0.5 * (exp(x) - exp(-x));
}
/* ================================ KOSINUS ======================================== */
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
/* ================================ TANGENS ======================================== */
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
/* ================================ KOTANGENS ======================================== */
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
/* ================================ SEKANS ======================================== */
TMath::DOUBLE TMath::sec(DOUBLE x)
{
	return 1 / cos(x);
}
TMath::DOUBLE TMath::arcsec(DOUBLE x)
{
	return acos(1 / x);
}
TMath::DOUBLE TMath::sech(DOUBLE x)
{
	return 1 / cosh(x);
}
/* ================================ KOSEKANS ======================================== */
TMath::DOUBLE TMath::cosec(DOUBLE x)
{
	return 1 / sin(x);
}
TMath::DOUBLE TMath::arccsc(DOUBLE x)
{
	return asin(1 / x);
}
TMath::DOUBLE TMath::csch(DOUBLE x)
{
	return 1 / sinh(x);
}
/* ================================= SECTION: FLOOR, CEIL AND MODULO ======================================== */
TMath::LONG TMath::floor(DOUBLE x)
{
	return LONG(x);
}
TMath::LONG TMath::ceil(DOUBLE x)
{
	return LONG(x) + 1;
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
TMath::DOUBLE TMath::log(DOUBLE n, DOUBLE x)
{
	return ln(x) / ln(n);
}
/* =================================== POWER FUNCTIONS =====================================================*/
TMath::DOUBLE TMath::pow(DOUBLE x, LONG n)
{
	DOUBLE r = 1;
	for (LONG i = 1; i <= n; i++)
	{
		r *= x;
	}
	return r;
}
TMath::LONG TMath::pow(LONG x, LONG n)
{
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
	for (LONG i = 1; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
/* ========================================== DEGREE <-> RADIANT ================================*/
TMath::DOUBLE TMath::rad(DOUBLE deg)
{
	return PI / 180 * deg;
}
TMath::DOUBLE TMath::deg(DOUBLE rad)
{
	return 180 / PI * rad;
}