#include "tmath.hpp"

/* ================================= FLOOR, CEIL AND MODULO ======================================== */
TMath::LONG TMath::floor(const DOUBLE &x)
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
TMath::LONG TMath::ceil(const DOUBLE &x)
{
	LONG truncated = LONG(x);
	if (x < 0) {
		return truncated;
	} else {
		if (truncated < x) {
			return truncated + 1;
		} else {
			return truncated;
		}
	}
}
TMath::DOUBLE TMath::mod(const DOUBLE &x, const DOUBLE &y)
{
	return y * ((x / y) - floor(x / y));
}
