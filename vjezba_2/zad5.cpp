
#include <iostream>

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    return a / b;
}

int main() {
    double (*operacije[4])(double, double) = {
        add, subtract, multiply, divide
    };

    double a, b;
    int izbor;

    std::cout << "Unesi dva broja: ";
    std::cin >> a >> b;

    std::cout << "0 - Zbrajanje\n";
    std::cout << "1 - Oduzimanje\n";
    std::cout << "2 - Mnozenje\n";
    std::cout << "3 - Dijeljenje\n";

    std::cout << "Odaberi operaciju: ";
    std::cin >> izbor;

    if (izbor < 0 || izbor > 3) {
        std::cout << "Ne može!";
    }
    else if (izbor == 3 && b == 0) {
        std::cout << "Ne može se sa nulom djeliti!";
    }
    else {
        std::cout << "Rezultat: " << operacije[izbor](a, b);
    }

    return 0;
}
