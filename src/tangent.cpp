#include "tmath.hpp"

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