#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H
#endif //POLYNOMIAL_POLYNOMIAL_H

#include <cmath>
#include <vector>
#include <iostream>
#include <initializer_list>
#include <algorithm>

class Polynomial{
public:

    Polynomial();
    Polynomial(int deg, int n);
    Polynomial(int x);
    Polynomial(int deg, std::vector<double> &coefficients);
    Polynomial(const Polynomial &polynomial);
    Polynomial (std::initializer_list<double> &initializerList);
    Polynomial(Polynomial &&polynomial): coefficients(polynomial.coefficients), deg(polynomial.deg){};

    ~Polynomial();

    double &coef(int n);
    double value(double point);

    Polynomial add(Polynomial &polynomial1, Polynomial &polynomial2) const;
    Polynomial multyply(Polynomial &polynomial1, Polynomial &polynomial2) const;
    Polynomial minus(Polynomial &polynomial1, Polynomial &polynomial2) const;

    friend std::ostream& operator<<(std::ostream& os, Polynomial& polynomial);
    friend std::istream& operator>>(std::istream& os, Polynomial& polynomial);

    Polynomial &operator= (const Polynomial &polynomial);
    Polynomial &operator= (Polynomial &&polynomial);

    double &operator[] (int n);
    double &operator() (double point) const;

private:

/*
 * deg -- степень многочлена,
 * coefficients -- вектор коэффициентов
 *
 * */

    int deg;
    std::vector<double> coefficients;

};
