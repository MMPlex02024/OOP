
#include <iostream>
 

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int twice(int a) {
    return a * 2;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = 5;

    my_transform(arr, n, twice);

    std::cout << "Udvostruceno: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    my_transform(arr, n, [](int a) {
        if (a % 2 == 0)
            return a / 2;
        else
            return a * 2;
        });

    std::cout << "\nNakon lambde: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    int suma = 0;
    int produkt = 1;

    auto izracunaj = [&](int a) {
        suma += a;
        produkt *= a;
        };

    for (int i = 0; i < n; i++)
        izracunaj(arr[i]);

    std::cout << "\nSuma: " << suma;
    std::cout << "\nProdukt: " << produkt;

    int prag = 3;
    int s = 0;

    auto veci_od_praga = [prag, &s](int a) {
        if (a > prag)
            s += a;
        };

    for (int i = 0; i < n; i++)
        veci_od_praga(arr[i]);

    std::cout << "\nSuma vecih od " << prag << ": " << s;

    return 0;
}
