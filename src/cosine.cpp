#include "tmath.hpp"

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