#include "tmath.hpp"

TMath::LONG TMath::fac(const LONG &n) {
	LONG r = 1;
	for (LONG i = 2; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
TMath::DOUBLE TMath::facd(const LONG &n) {
	DOUBLE r = 1;
	for (LONG i = 2; i <= n; i++) {
		r *= DOUBLE(i);
	}
	return r;
}
TMath::LONG TMath::oddfac(const LONG &n) {
	LONG r = 1;
	for (LONG i = 3; i <= n; i += 2) {
		r *= i;
	}
	return r;
}
TMath::DOUBLE TMath::oddfacd(const LONG &n) {
	DOUBLE r = 1;
	for (LONG i = 3; i <= n; i += 2) {
		r *= DOUBLE(i);
	}
	return r;
}