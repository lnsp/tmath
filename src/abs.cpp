#include "tmath.hpp"

TMath::DOUBLE TMath::abs(const DOUBLE &x) {
	if (x < 0) return -x;
	else return x;
}