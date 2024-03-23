#include <iostream>

#include "polynomial.h"

int main() {
    Polynomial polynomial1(3, 1);
    Polynomial polynomial2 = std::move(polynomial1);
    polynomial2 = polynomial2.add(polynomial1, polynomial2);
    auto polynomial = polynomial1.add(polynomial1, polynomial2);
    std::cout << polynomial;
    std::cout << polynomial(0);
    return 0;
}
