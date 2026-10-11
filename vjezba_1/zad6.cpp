/*
6. Definirajte strukturu Fraction (razlomak) s članovima numerator i denominator te
metodama:
◦ void reduce() — skraćuje razlomak (koristite najveći zajednički djelitelj),
◦ double value() — vraća decimalnu vrijednost,
◦ void print() — ispisuje razlomak u obliku 3/4.
Napišite i globalnu funkciju Fraction sum(const Fraction& a, const Fraction& b) koja
vraća skraćeni zbroj

*/


#include <iostream>
#include <cstdlib>

int nzd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0) {
        int ostatak = a % b;
        a = b;
        b = ostatak;
    }

    return a;
}

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {
        int d = nzd(numerator, denominator);

        if (d != 0) {
            numerator /= d;
            denominator /= d;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double value() {
        return (double)numerator / denominator;
    }

    void print() {
        std::cout << numerator << "/" << denominator;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    Fraction rezultat;

    rezultat.numerator = a.numerator * b.denominator +
        b.numerator * a.denominator;
    rezultat.denominator = a.denominator * b.denominator;

    rezultat.reduce();

    return rezultat;
}

int main() {
    Fraction a = { 2, 4 };
    Fraction b = { 3, 6 };

    a.reduce();
    b.reduce();

    std::cout << "Prvi razlomak: ";
    a.print();
    std::cout << std::endl;

    std::cout << "Drugi razlomak: ";
    b.print();
    std::cout << std::endl;

    Fraction rezultat = sum(a, b);

    std::cout << "Zbroj: ";
    rezultat.print();
    std::cout << std::endl;

    std::cout << "Decimalna vrijednost: "
        << rezultat.value() << std::endl;

    return 0;
}

