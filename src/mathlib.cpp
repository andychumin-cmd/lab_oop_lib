#include "mathlib.h"
#include <cmath>
#include <sstream>

MathLib::MathLib(double a, double b, double c) : a(a), b(b), c(c) {}

double MathLib::discriminant() const {
    return b * b - 4.0 * a * c;
}

int MathLib::solve(double& x1, double& x2) const {
    if (a == 0.0) return -1;               // не квадратное
    double D = discriminant();
    if (D < 0) return 0;                   // корней нет
    if (D == 0) { x1 = -b / (2.0 * a); return 1; }
    x1 = (-b + std::sqrt(D)) / (2.0 * a);
    x2 = (-b - std::sqrt(D)) / (2.0 * a);
    return 2;
}

double MathLib::evaluate(double x) const {
    return a * x * x + b * x + c;
}

std::string MathLib::toString() const {
    std::ostringstream oss;
    oss << a << "x^2 + " << b << "x + " << c << " = 0";
    return oss.str();
}

const char* libVersion() { return "v2.0-improved"; }
