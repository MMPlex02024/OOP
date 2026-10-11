/*
Zadan je niz int numbers[] = {4, -7, 12, 0, 9, -3};
	- Koristeći range-based for ispišite niz, a zatim svaki negativni element zamjenite njegovom apsolutnom vrijednošću.

	- Napišite funkciju int& find_max (int arr[], int n) koja vraća referencu na najveći element niza.
		Koristeći povratnu vrijednost kao lvalue, postavite največi element na 0 i ispišite niz.
*/


#include <iostream>
#include <cstdlib>

int& find_max(int niz[], int velicina) {
    int najveci = 0;

    for (int i = 1; i < velicina; i++) {
        if (niz[i] > niz[najveci]) {
            najveci = i;
        }
    }

    return niz[najveci];
}

int main() {
    int numbers[] = { 4, -7, 12, 0, 9, -3 };
    int duljina = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Pocetni niz: ";
    for (int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (int& x : numbers) {
        if (x < 0) {
            x = std::abs(x);
        }
    }

    std::cout << "Niz nakon promjene: ";
    for (int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    find_max(numbers, duljina) = 0;

    std::cout << "Konacni niz: ";
    for (int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
