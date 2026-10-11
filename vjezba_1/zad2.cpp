/*
Učitajte godinu rođenja (std::cin >>), a zatim ime i prezime u jedan std ::  string koristeći std::getline(). Ispišite:
-Inicijale (npr. Ana Horvat -> A.H.)
- Broj znakova imena i prezimena bez razmaka (koristite range-based for),
- koliko godina osoba navršava ove godine.
*/


#include <iostream>
#include <string>
#include <cctype>

int main() {
    int godinar;
    std::string ime_prezime;

    std::cout << "Unesite godinu rođenja: ";
    std::cin >> godinar;
    std::cin.ignore();

    std::cout << "Unesite ime i prezime: ";
    std::getline(std::cin, ime_prezime);

     
    std::string inicijali;
    bool prvo_slovo = true;

    for (char c : ime_prezime) {
        if (c == ' ') {
            prvo_slovo = true;
        }
        else if (prvo_slovo) {
            inicijali += std::toupper(static_cast<unsigned char>(c));
            inicijali += '.';
            prvo_slovo = false;
        }
    }

     
    int broj_znakova = 0;

    for (char c : ime_prezime) {
        if (c != ' ') {
            broj_znakova++;
        }
    }

    
    int godina = 2026;
    int godine =  godina - godinar;

    std::cout << "Inicijali: " << inicijali << std::endl;
    std::cout << "Broj znakova bez razmaka: "
        << broj_znakova << std::endl;
    std::cout << "Osoba navrsava "
        << godine << " godina." << std::endl;

    return 0;
}

