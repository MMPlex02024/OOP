/*
 U prostoru imena (namespace) geo definirajte konstantu PI. Napišite preopte
rećene funkcije:
◦ double area(double r) — površina kruga,
◦ double area(double a, double b) — površina pravokutnika,
◦ int area(int a) — površina kvadrata.
Napišite i funkciju void print_line(char c = '-', int length = 30) koja ispisuje liniju
znakova. Koristite je za odvajanje ispisa.
Prije pokretanja predvidite koja se funkcija poziva za area(5), area(5.0), area(2,
3) i area('A'), a zatim provjerite.

*/




#include <iostream>

namespace geo {
    const double PI = 3.141592653589793;

    double area(double r) {
        return PI * r * r;
    }

    double area(double a, double b) {
        return a * b;
    }

    int area(int a) {
        return a * a;
    }

    void print_line(char c = '-', int length = 30) {
        for (int i = 0; i < length; i++) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "area(5): " << geo::area(5) << std::endl;
    geo::print_line();

    std::cout << "area(5.0): " << geo::area(5.0) << std::endl;
    geo::print_line('*', 20);

    std::cout << "area(2, 3): " << geo::area(2, 3) << std::endl;
    geo::print_line();

    std::cout << "area('A'): " << geo::area('A') << std::endl;
    geo::print_line();

    return 0;
}
