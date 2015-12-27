#include <iostream>
#include "tmath.hpp"

using namespace TMath;

int main(int argc, char const *argv[]) {
    for (DOUBLE x = -5; x <= 5; x += 0.25)
        std::cout << x << "~" << ceil(x) << std::endl;
    for (LONG n = 0; n < 4; n++)
        std::cout << pow(DOUBLE(-1), n) << std::endl;

    std::cout << sin(0) << std::endl;
    std::cout << sin(PI/2.0) << std::endl;

    return 0;
}
