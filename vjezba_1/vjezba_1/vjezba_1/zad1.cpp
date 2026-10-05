#include <iostream>

int main() {
	int a{};
	int b{};
	std::cin >> a >> b;

	bool razlika(a < b);
	std::cout << "Zbroj: " << a + b << std::endl;
	std::cout << "Aritmeticka vrijednost" << (a + b) / 2.0 << std::endl;
	std::cout << "A veci od B" << std::boolalpha << razlika << std::endl;

	return 0;

}