#ifndef _TMATH_TEST_HPP
#define _TMATH_TEST_HPP

#include <string>
#include "tmath.hpp"

namespace TMathTest {
bool equal(TMath::DOUBLE x, TMath::DOUBLE y, TMath::DOUBLE tolerance);
bool equal(TMath::DOUBLE x, TMath::DOUBLE y);
void assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression);
void assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression, TMath::DOUBLE tolerance);
}

#endif
