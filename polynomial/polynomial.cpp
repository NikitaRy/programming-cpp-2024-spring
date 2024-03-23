#include "polynomial.h"

/* Конструктор по умолчанию: нулевой многочлен*/

Polynomial::Polynomial() {
    this -> deg = 0;
    this -> coefficients.push_back(0);
}

/* Деструктор не нужен из-за векторов */

Polynomial::~Polynomial(){}

/* Конструктор по степени и вектору коэффициентов */

Polynomial::Polynomial(int deg, std::vector<double> &coefficients) {
    this -> deg = deg;
    this -> coefficients = coefficients;
}
/* Конструктор по степени --
 * заполняем каким-то одним значением
 * */
Polynomial::Polynomial(int deg, int n) {
    this -> deg = deg;
    for(int i = 0; i < deg; i++)
        this -> coefficients.push_back(n);
}
/* Получить коэффициент при и n-ой степени */

double &Polynomial::coef(int n) {
    if (n > deg)
        coefficients[n] = INFINITY;
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

Polynomial Polynomial::multyply(Polynomial &polynomial1, Polynomial &polynomial2) const{
    int deg1 = polynomial1.deg;
    int deg2 = polynomial2.deg;

/* Сначала выравниваем степени многочленов, считая старшие коэффициенты нулевыми*/

    if (deg1 > deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial2.coefficients.push_back(0.0);
    if (deg1 < deg2)
        for(int i = 0; i < abs(deg1-deg2); i++)
            polynomial1.coefficients.push_back(0.0);

/* Берем степень с запасом: удвоенную максимальную
 * Очевидно, что это для некоторых случаев неоптимально по памяти
 * Однако, в большинстве случаев, это решение неплохо*/

    int deg = std::max(deg1, deg2) * 2;
    std::vector<double> coefficients(deg, 0);

    for(int i = 0; i < deg; i++)
        for(int j = 0; j < deg; j++)
            coefficients[i+j] += polynomial1.coefficients[i]*polynomial2.coefficients[j];

    Polynomial polynomial(deg, coefficients);
    return polynomial;


}

/* Вычитание многочленов */

Polynomial Polynomial::minus(Polynomial &polynomial1, Polynomial &polynomial2) const{
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

Polynomial Polynomial::add(Polynomial &polynomial1, Polynomial &polynomial2) const {
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

    return std::move(Polynomial(deg, coefficients));
}

/* Перегрузка operator<< */

std::ostream &operator<<(std::ostream &os, Polynomial &polynomial) {
    for(int i = 0; i < polynomial.deg; i++)
        os << polynomial.coefficients[i] << " ";
    os << std::endl;
    return os;
}

/* Вывод многчленов
 * Спецификация: вводим не n коэффициентов, а n+1; старший из них нулевой */

std::istream &operator>>(std::istream &os, Polynomial &polynomial)  {
    int i = 0;
    while(polynomial.coef(i)!=INFINITY){
        os >> polynomial.coef(i);
        i++;
    }
    return os;
}

/* Конструктор копирования */

Polynomial::Polynomial(const Polynomial &polynomial) {
    deg = polynomial.deg;
    coefficients.resize(deg);
    for(int i = 0; i < deg; i++){
        coefficients[i] = polynomial.coefficients[i];
    }
}

/* Cast-конструктор */

Polynomial::Polynomial(int x) {
    deg = 0;
    coefficients.push_back(x);
}

/* Конструктор инициализации */
Polynomial::Polynomial(std::initializer_list<double> &initializerList) {
    deg = initializerList.size();
    coefficients.resize(deg);
    std::copy(initializerList.begin(), initializerList.end(), coefficients.begin());
}

/* Перегрузка operator= */

Polynomial &Polynomial::operator=(const Polynomial &polynomial) {
    if(this == &polynomial)
        return *this;
    deg = polynomial.deg;
    coefficients.resize(deg);
    for(int i = 0; i < deg; i++)
        coefficients[i] = polynomial.coefficients[i];
    return *this;
}

/* Индексация --
 * аки аналог функции coef
 * */

double &Polynomial::operator[](int n) {
    if(n >= 0 && n < deg)
        return coefficients[n];
    if(n >= deg){
        static double k = 0;
        return k;
    }
    else
        exit(-1);
}

/* Перемещающее присваивание */

Polynomial &Polynomial::operator=(Polynomial &&polynomial){
    if(this == &polynomial)
        return *this;
    polynomial.coefficients.resize(this->deg);
    for(int i = 0; i < polynomial.deg; i++){
        polynomial.coefficients[i] = this->coefficients[i];
    }

    return *this;
}

/* Перегрузка operator():
 * значение многочлена в точке point*/

double &Polynomial::operator()(double point) const{
    static double value = 0;
    for(int i = 0; i < this->deg; i++){
        value += this->coefficients[i]*std::pow(point, i);
    }
    return value;
}







