/*

1. Zadana je pretprocesorska direktiva (makro) #define MAX(a, b) a > b ? a : b. Prije
pokretanja predvidite vrijednosti varijabli
int a = MAX(3, 5);
int b = 2 * MAX(3, 5);
a zatim provjerite.
◦ Popravite makro zagradama i ponovno provjerite.
int c = MAX(3, 5) + 1;


◦Napišite inline funkciju my_max. Za int i = 3; usporedite rezultat poziva
MAX(++i, 2) i my_max(++i, 2) i vrijednost i nakon poziva.
◦ 

Funkciju my_max napišite kao function template i pozovite je za int, double, char i
std::string.

*/
#include <iostream>
#define MAX(a, b) a > b ? a : b
#define my_MAX(a, b) (a > b ? a : b)

template <typename T>
	T my_max(T a, T b) {

	return a > b ? a : b ;
	
	}



int main(void) {
	std::cout <<  "*****3dio zad****" << std::endl;
	int d = 5;
	int r = 4; 

	std::cout << my_max(d, r) << std::endl;
	std::cout << my_max(5.4, 3.3)<< std:: endl;
	std::cout << my_max("mijau", "vau") << std::endl;
	std::cout << my_max('b', 'a') << std::endl;
	//std::cout <<  << std::endl;
	std::cout << "*****Zad1********" << std::endl;
	// 1 dio zadataka
	int a = my_MAX(3, 5);
	std::cout << a << std:: endl;
	
	int b = 2 * my_MAX(3 , 5);
	std::cout << b << std::endl;
	
	int c = my_MAX(3, 5) + 1;
	std::cout << c << std::endl;

	std::cout << "*********" << std::endl;

	// 2 dio zadataka
	int i = 3;
	int x = MAX(++i, 2); 
	std::cout << x << std::endl;

	int y = my_MAX(++i, 2);
	std::cout << y << std::endl;

	return 0;
}