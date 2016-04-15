#include "tmath.hpp"

TMath::DOUBLE TMath::equal(const DOUBLE &x, const DOUBLE &y) {
	return equal(x, y, EQUAL_EPSILON);
}
TMath::DOUBLE TMath::equal(const DOUBLE &x, const DOUBLE &y, const DOUBLE &eps) {
	return abs(x - y) < eps;
}