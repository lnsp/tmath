#include "tmath.hpp"

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