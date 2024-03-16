#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H
#endif //POLYNOMIAL_POLYNOMIAL_H
#include <vector>
#include <iostream>

class Polynomial{
public:
    Polynomial();
    Polynomial(int deg, int n);
    Polynomial(int x);
    Polynomial(int deg, std::vector<double> coefficients);
    Polynomial(const Polynomial &polynomial);
    ~Polynomial();
    double &coef(int n);
    double value(double point);
    Polynomial add(Polynomial &polynomial1, Polynomial &polynomial2);
    Polynomial multyply(Polynomial &polynomial1, Polynomial &polynomial2);
    Polynomial minus(Polynomial &polynomial1, Polynomial &polynomial2);
    friend std::ostream& operator<<(std::ostream& os, Polynomial& polynomial);
    friend std::istream& operator>>(std::istream& os, Polynomial& polynomial);
private:
    int deg;
    std::vector<double> coefficients;
};
