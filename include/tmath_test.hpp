#ifndef _TMATH_TEST_HPP
#define _TMATH_TEST_HPP

#include <string>
#include <functional>
#include "tmath.hpp"

namespace TMathTest {
const TMath::DOUBLE DEFAULT_TOLERANCE = 0.001;
bool equal(TMath::DOUBLE x, TMath::DOUBLE y, TMath::DOUBLE tolerance);
void assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression);
void assert(TMath::DOUBLE value, TMath::DOUBLE correct, std::string expression, TMath::DOUBLE tolerance);
void assert(TMath::Matrix a, TMath::Matrix b, std::string expression);
void assert(TMath::Matrix a, TMath::Matrix b, std::string expression, TMath::DOUBLE tolerance);
void assert(TMath::Vector a, TMath::Vector b, std::string expression);
void assert(TMath::Vector a, TMath::Vector b, std::string expression, TMath::DOUBLE tolerance);
void assertTrue(bool b, std::string expression);
void assertError(std::function<void ()>, std::string expression);
}

#endif
