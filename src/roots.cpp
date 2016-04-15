#include "tmath.hpp"

TMath::DOUBLE TMath::sqrt(const DOUBLE &x)
{
	return root(x, 2);
}
TMath::DOUBLE TMath::root(const DOUBLE &x, const DOUBLE &n)
{
	if (x > 0) {
		return pow(x, 1 / n);
	} else {
		return 0;
	}
}