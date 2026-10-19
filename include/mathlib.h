#ifndef MATHLIB_H
#define MATHLIB_H

#include <string>

// Класс инкапсулирует все математические выкладки
class MathLib {
private:
    double a, b, c;                    // коэффициенты ax^2 + bx + c = 0
    double discriminant() const;       // D = b^2 - 4ac

public:
    MathLib(double a, double b, double c);

    // Возвращает количество корней; x1, x2 заполняются при наличии
    int solve(double& x1, double& x2) const;

    // Значение функции в точке: f(x) = ax^2 + bx + c
    double evaluate(double x) const;

    std::string toString() const;
};

// Версия библиотеки — для проверки раздельной разработки
const char* libVersion();

#endif
