#include "tmath.hpp"

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