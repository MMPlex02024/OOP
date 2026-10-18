#include <iostream>
#include <algorithm>

template <typename T>
inline bool ascending(T a, T b) {
    return a > b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a < b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[i], arr[j])) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr1[] = { 5, 2, 9, 1, 7 };
    double arr2[] = { 3.5, 1.2, 4.8, 2.1 };
    char arr3[] = { 'd', 'a', 'c', 'b' };

    my_sort(arr1, 5, ascending<int>);
    my_sort(arr2, 4, ascending<double>);
    my_sort(arr3, 4, ascending<char>);

    std::cout << "INT uzlazno: ";
    for (int i = 0; i < 5; i++)
        std::cout << arr1[i] << " ";

    std::cout << "\nDOUBLE uzlazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << arr2[i] << " ";

    std::cout << "\nCHAR uzlazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << arr3[i] << " ";

    my_sort(arr1, 5, descending<int>);
    my_sort(arr2, 4, descending<double>);
    my_sort(arr3, 4, descending<char>);

    std::cout << "\nINT silazno: ";
    for (int i = 0; i < 5; i++)
        std::cout << arr1[i] << " ";

    std::cout << "\nDOUBLE silazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << arr2[i] << " ";

    std::cout << "\nCHAR silazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << arr3[i] << " ";

    return 0;
}
