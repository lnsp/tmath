#pragma once

namespace TMath {
	typedef long long LONG;
	typedef long double DOUBLE;
	const DOUBLE PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

	LONG	floor(DOUBLE x);
	LONG	ceil(DOUBLE x);
	DOUBLE	mod(DOUBLE x, DOUBLE y);

	DOUBLE	sin(DOUBLE x); // Sinus
	DOUBLE	asin(DOUBLE x); // Arkussinus
	DOUBLE	sinh(DOUBLE x); // Sinus hyperbolicus

	DOUBLE	cos(DOUBLE x); // Kosinus
	DOUBLE	acos(DOUBLE x); // Arkuskosinus
	DOUBLE	cosh(DOUBLE x); // Kosinus hyperbolicus

	DOUBLE	tan(DOUBLE x); // Tangens
	DOUBLE	atan(DOUBLE x); // Arkustangens
	DOUBLE	tanh(DOUBLE x); // Tangens hyperbolicus

	DOUBLE	cot(DOUBLE x); // Kotangens
	DOUBLE	acot(DOUBLE x); // Arkuskotangens
	DOUBLE	coth(DOUBLE x); // Kotangens hyperbolicus

	DOUBLE	sec(DOUBLE x); // Sekans
	DOUBLE	arcsec(DOUBLE x); // Arkussekans
	DOUBLE	sech(DOUBLE x); // Sekans hyperbolicus

	DOUBLE	cosec(DOUBLE x); // Kosekans
	DOUBLE	arccsc(DOUBLE x); // Arkus kosekans
	DOUBLE	csch(DOUBLE x); // Kosekans hyperbolicus

	DOUBLE	rad(DOUBLE deg);
	DOUBLE	deg(DOUBLE rad);

	DOUBLE	exp(DOUBLE x);
	DOUBLE	sqrt(DOUBLE x);
	DOUBLE	root(DOUBLE x, DOUBLE n);
	DOUBLE	ln(DOUBLE x);
	DOUBLE	lg(DOUBLE x);
	DOUBLE	lb(DOUBLE x);
	DOUBLE	log(DOUBLE n, DOUBLE y);

	DOUBLE	pow(DOUBLE x, DOUBLE n);
	DOUBLE	pow(DOUBLE x, LONG n);
	LONG	pow(LONG x, LONG n);

	LONG	fac(LONG n);
}