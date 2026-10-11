/*
5. Definirajte strukturu Point s koordinatama x i y (double).
◦ Napišite funkcije void move_by(Point* p, double dx, double dy) i double dist(
const Point* a, const Point* b) kao u C-u, pomoću pointera.
◦ Iste funkcije napišite pomoću referenci. Usporedite pozive u main funkciji.
◦ Za niz od pet točaka pronađite točku najbližu ishodištu.
Napomena: std::sqrt se nalazi u #include <cmath>

*/


#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

void move_by(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b) {
    return std::sqrt(std::pow(a->x - b->x, 2) +
        std::pow(a->y - b->y, 2));
}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) +
        std::pow(a.y - b.y, 2));
}

int main() {
    Point p1 = { 2, 3 };
    Point p2 = { 5, 7 };

    move_by(&p1, 2, 1);
    std::cout << "Pointer: " << p1.x << ", " << p1.y << std::endl;
    std::cout << "Udaljenost: " << dist(&p1, &p2) << std::endl;

    move_by(p1, 1, 2);
    std::cout << "Referenca: " << p1.x << ", " << p1.y << std::endl;
    std::cout << "Udaljenost: " << dist(p1, p2) << std::endl;

    Point tocke[5] = {
        {2, 3},
        {4, 5},
        {1, 1},
        {7, 2},
        {3, 4}
    };

    Point ishodiste = { 0, 0 };
    int najbliza = 0;

    for (int i = 1; i < 5; i++) {
        if (dist(tocke[i], ishodiste) <
            dist(tocke[najbliza], ishodiste)) {
            najbliza = i;
        }
    }

    std::cout << "Najbliza tocka ishodistu: ("
        << tocke[najbliza].x << ", "
        << tocke[najbliza].y << ")" << std::endl;

    return 0;
}
