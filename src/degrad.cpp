#include "tmath.hpp"

TMath::DOUBLE TMath::rad(const DOUBLE &deg)
{
	return PI / 180.0 * deg;
}
TMath::DOUBLE TMath::deg(const DOUBLE &rad)
{
	return 180.0 / PI * rad;
}