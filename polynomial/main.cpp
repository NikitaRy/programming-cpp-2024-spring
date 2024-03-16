#include <iostream>

#include "polynomial.h"

int main() {
    int n = 2;
    std::vector<double> coefficients = {1.0, 1.5, 1.0};
    Polynomial polynomial = Polynomial(coefficients.size(), coefficients);
    //std::cout << polynomial.coef(n) << " "  << polynomial.value(0) << std::endl;
    Polynomial polynomial1 = polynomial;

    std::cout << polynomial1[1];
    return 0;
}
