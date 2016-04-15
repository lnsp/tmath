#include "tmath.hpp"

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