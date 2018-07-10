#include <iostream>
#include "tmath.hpp"

#define ERR_DIM_MISMATCH "Matrix-vector dimension mismatch"
#define ERR_NOT_QUADRATIC "Can only solve quadratic systems"
#define ERR_NO_SOLUTION "The system has no unique solution"

// Solves A * x = b. Returns x.
TMath::Vector solve(TMath::Matrix A, TMath::Vector b)
{
    int n = A.rowCount(), m = A.colCount(), p = b.dim();
    if (n != m) throw ERR_NOT_QUADRATIC;
    if (n != p) throw ERR_DIM_MISMATCH;
    // Decompose into upper-right matrix
    for (int i = 0; i < m; i++) {
        // Swap out pivot element for better numerics
        int maxJ = i;
        for (int j = 0; j < n; j++) if (A[j][i] > A[maxJ][i]) maxJ = j;
        TMath::Vector tmpA = A[maxJ];
        A[maxJ] = A[i];
        A[i] = tmpA;
        TMath::DOUBLE tmpB = b[maxJ];
        b[maxJ] = b[i];
        b[i] = tmpB;
        // Make A[i+1...n][i] = 0.
        if (A[i][i] == 0.) throw ERR_NO_SOLUTION;
        for (int j = i + 1; j < n; j++) {
            TMath::DOUBLE f = A[j][i] / A[i][i];
            A[j] = A[j] - A[i] * f;
            b[j] = b[j] - b[i] * f;
        }
    }
    // Resubstitute into system
    TMath::Vector x(n);
    for (int i = n-1; i >= 0; i--) {
        TMath::DOUBLE f = 0;
        for (int j = n-1; j > i; j--) f += x[j] * A[i][j];
        x[i] = (b[i] - f) / A[i][i];
    }
    return x;
}

int main()
{
    std::cout << "TMath :: Gauss solver" << std::endl;
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
    TMath::Vector x;
    try {
        x = solve(A, b);
    } catch (std::string err) {
        std::cout << "error: " << err << std::endl;
        return 1;
    }
    std::cout << "Solution: " << x.to_string() << std::endl;
    return 0;
}
