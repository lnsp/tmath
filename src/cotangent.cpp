#include "tmath.hpp"

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