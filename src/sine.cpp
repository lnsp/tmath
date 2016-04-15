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