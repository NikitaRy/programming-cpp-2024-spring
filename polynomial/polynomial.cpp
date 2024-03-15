#include <math.h>
#include "polynomial.h"

/* Конструктор по умолчанию: нулевой многочлен*/

Polynomial::Polynomial() {
    this -> deg = 0;
    this -> coefficients.push_back(0);
}

/* Деструктор не нужен из-за векторов */

Polynomial::~Polynomial(){}

/* Конструктор по степени и вектору коэффициентов */

Polynomial::Polynomial(int deg, std::vector<double> coefficients) {
    this -> deg = deg;
    this -> coefficients = coefficients;
}
/* Получить коэффициент при и n-ой степени */

double &Polynomial::coef(int n) {
    return this -> coefficients[n];
}

/* Значение в точке */

double Polynomial::value(double point) {
    double  value = 0;
    for(int i = 0; i <= this -> deg; i++){
        value += coef(i)*std::pow(point, i);
    }
    return value;
}

/* Умножение многочленов -- покомпонентное;
 * на БПФ сил нету :-)
 * */

Polynomial Polynomial::multyply(Polynomial polynomial1, Polynomial polynomial2) {
    int deg1 = polynomial1.deg;
    int deg2 = polynomial2.deg;

/* Сначала выравниваем степени многочленов, считая старшие коэффициенты нулевыми*/

    if (deg1 > deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial2.coefficients.push_back(0.0);
    if (deg1 < deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial1.coefficients.push_back(0.0);

    int deg = std::max(deg1, deg2) * 2;
    std::vector<double> coefficients(deg, 0);

    for(int i = 0; i < deg; i++)
        for(int j = 0; j < deg; j++)
            coefficients[i+j] += polynomial1.coefficients[i]*polynomial2.coefficients[j];

    Polynomial polynomial(deg, coefficients);
    return polynomial;


}

/* Вычитание многочленов */

Polynomial Polynomial::minus(Polynomial polynomial1, Polynomial polynomial2) {
    int deg1 = polynomial1.deg;
    int deg2 = polynomial2.deg;

/* Сначала выравниваем степени многочленов, считая старшие коэффициенты нулевыми*/

    if (deg1 > deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial2.coefficients.push_back(0.0);
    if (deg1 < deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial1.coefficients.push_back(0.0);

    int deg = std::max(deg1, deg2);
    std::vector<double> coefficients;

    for(int i = 0; i < deg; i++)
        coefficients.push_back(polynomial1.coefficients[i]-polynomial2.coefficients[i]);

    Polynomial polynomial(deg, coefficients);
    return polynomial;
}

/* Покомпонентное сложение многочленов */

Polynomial Polynomial::add(Polynomial polynomial1, Polynomial polynomial2) {
    int deg1 = polynomial1.deg;
    int deg2 = polynomial2.deg;

/* Сначала выравниваем степени многочленов, считая старшие коэффициенты нулевыми*/

    if (deg1 > deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial2.coefficients.push_back(0.0);
    if (deg1 < deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial1.coefficients.push_back(0.0);

    int deg = std::max(deg1, deg2);
    std::vector<double> coefficients;

    for(int i = 0; i < deg; i++)
        coefficients.push_back(polynomial1.coefficients[i]+polynomial2.coefficients[i]);

    Polynomial polynomial(deg, coefficients);
    return polynomial;

}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    for(int i = 0; i < polynomial.deg; i++)
        os << polynomial.coefficients[i] << " ";
    os << std::endl;
    return os;
}

