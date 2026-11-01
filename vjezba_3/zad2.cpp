#include <iostream>
#include <vector>
/*
2. Korisnik unosi broj dana n, a zatim n izmjerenih temperatura.
◦ Vektor temperatura stvorite konstruktorom s n elemenata i popunite ga preko
indeksa.
◦ Napravite novi vektor promjena temperature između susjednih dana (drugi minus
prvi, treći minus drugi, …). Kroz vektor temperatura prođite iteratorima. Za novi
vektor unaprijed rezervirajte mjesto.
◦ Za izvještaj je potrebno točno 7 dana. Jednim pozivom resize skratite vektor na
7 dana ako je uneseno više, odnosno dopunite ga do 7 dana temperaturom zadnjeg
izmjerenog dana ako je uneseno manje.

Broj dana: 4
12.5 14 13 9.5
Promjene: 1.5 -1 -3.5
Izvjestaj: 12.5 14 13 9.5 9.5 9.5 9.5
Koliko elemenata imaju std::vector<int> a(5); i std::vector<int> b{5};? Provjerite ispisom.

*/

int main() {

	int dan;
	std::vector<float> temp;
	std::vector<float>promjena_temp;

	std:: cout << "Unesite broj dana" << std::endl;
	std:: cin >> dan;
	
	for (int i = 0; i < dan; i++) {
		
		std:: cout << "Unesite temperaturu za " << i<< ". dan: " << std::endl;
		float br;
		std::cin >> br;
		temp.push_back(br);
	}
	

	for (int i = 0; i < temp.size() - 1; i++) {

		promjena_temp.push_back(temp[i+1] - temp[i]);
	}

	std::cout << "promjene temperature su" << std:: endl;

	for (int i = 0; i < promjena_temp.size(); i++) {
		
		std:: cout << promjena_temp[i] << std :: endl;
	}

	if (temp.size() > 7) {
		
		temp.resize(7);
		std::cout << "Izvjestaj:" << std::endl;
		for (int i = 0; i < temp.size(); i++) {

			std::cout << temp[i] << std::endl;
		}
	}
	else {
		std::cout << "Unesite dodatne dane temperature";
		for (int i = temp.size(); i < 7; i++) {
			float br1;
			std::cin >> br1;
			temp.push_back(br1);
		}
		
		std::cout << "Izvjestaj:" << std:: endl;
		
		for (int i = 0; i < temp.size(); i++) {

			std::cout << temp[i] << std::endl;
		}
	}

	
	
	return 0;
}