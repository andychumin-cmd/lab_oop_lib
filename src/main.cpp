#include <iostream>
#include <cstdlib>
#include "mathlib.h"

void printUsage(const char* prog) {
    std::cout << "Использование: " << prog << " <a> <b> <c> [x]\n"
              << "  a, b, c — коэффициенты ax^2 + bx + c = 0\n"
              << "  x       — (необязательно) точка для вычисления f(x)\n"
              << "Пример:   " << prog << " 1 -3 2 5\n";
}

int main(int argc, char* argv[]) {
    // --- обработка аргументов командной строки ---
    if (argc < 4 || argc > 5) {
        std::cerr << "Ошибка: получено аргументов: " << (argc - 1) << "\n";
        printUsage(argv[0]);
        return 1;
    }

    double a = std::atof(argv[1]);
    double b = std::atof(argv[2]);
    double c = std::atof(argv[3]);

    std::cout << "Библиотека: " << libVersion() << "\n";

    MathLib eq(a, b, c);                    // работа через объект
    std::cout << "Уравнение: " << eq.toString() << "\n";

    double x1 = 0, x2 = 0;
    int roots = eq.solve(x1, x2);
    switch (roots) {
        case 2:  std::cout << "Корни: x1 = " << x1 << ", x2 = " << x2 << "\n"; break;
        case 1:  std::cout << "Один корень: x = " << x1 << "\n"; break;
        case 0:  std::cout << "Действительных корней нет\n"; break;
        default: std::cout << "Это не квадратное уравнение (a = 0)\n"; break;
    }

    if (argc == 5) {                        // необязательный 4-й аргумент
        double x = std::atof(argv[4]);
        std::cout << "f(" << x << ") = " << eq.evaluate(x) << "\n";
    }
    return 0;
}
