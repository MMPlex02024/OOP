#include <iostream>

inline bool ascending(int a, int b) {
    return a > b;
}

inline bool descending(int a, int b) {
    return a < b;
}


void my_sort(int arr[], int n, bool (*cmp)(int, int)) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main(void) {

    int arr[] = { 5, 2, 9, 1, 7 };
    int n = 5;

    std::cout << "Niz: ";// <<  std::endl;
    for (int i = 0; i < n; i++) {
        std::cout<< arr[i]<< " ";
    }

    my_sort(arr, n, ascending);

    std::cout << "\nUzlazno: ";
    for (int i = 0; i < n; i++) {
       std:: cout << arr[i] << " ";
    }

    my_sort(arr, n, descending);

    std::cout << "\nSilazno: ";
    for (int i = 0; i < n; i++) {
     std :: cout << arr[i] << " ";
    }


	return 0;
}