#include "tmath.hpp"

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