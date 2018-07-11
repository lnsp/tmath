#include <iostream>
#include "tmath.hpp"

TMath::Vector solve(TMath::Matrix A, TMath::Vector b, TMath::DOUBLE delta)
{
    int n = A.rowCount(), m = A.colCount(), p = b.dim();
    if (n != m || n != p) throw "mismatch dimensions";

    TMath::Vector x, x_ = b;
    do {
        x = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                x[i] = x[i] - A[i][j] * x_[j];
            }
            x[i] = x[i] / A[i][i];
        }
    } while ((x_ - (x_ = x)).length() > delta);

    return x_;
}

int main()
{
    std::cout << "TMath :: Jacobi iteration solver" << std::endl;
    int n;
    std::cout << "Enter matrix dimension: "; std::cin >> n;
    TMath::Matrix A(n, n);
    std::cout << "Enter matrix (row per row, space separated):" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            TMath::DOUBLE f;
            std::cin >> f;
            A[i][j] = f;
        }
    }
    TMath::Vector b(n);
    std::cout << "Enter vector:" << std::endl;
    for (int i = 0; i < n; i++) {
        TMath::DOUBLE f;
        std::cin >> f;
        b[i] = f;
    }
    TMath::DOUBLE delta;
    std::cout << "Enter delta: ";
    std::cin >> delta;
    TMath::Vector x;
    try {
        x = solve(A, b, delta);
    } catch (std::string err) {
        std::cout << "error: " << err << std::endl;
        return 1;
    }
    std::cout << "Solution: " << x.to_string() << std::endl;
    return 0;
}