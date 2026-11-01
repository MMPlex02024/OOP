#include <iostream>
#include <string>

/*
4. Napišite funkciju bool split_email(const std::string& email, std::string& user,
std::string& domain) koja e-mail adresu dijeli na korisničko ime (dio prije @) i domenu
(dio iza @). Funkcija vraća false ako adresa nije ispravna:
◦ nema znaka @ ili ih ima više (find, rfind),
◦ @ je na početku ili na kraju,
◦ u domeni nema točke.
Adresu korisnik unosi kao cijeli redak (std::getline).
"ana.horvat@oss.unist.hr" -> korisnik: ana.horvat, domena: oss.unist.hr
"ana@horvat@oss.unist.hr" -> neispravna adresa
"ana.horvat@oss" -> neispravna adresa



*/
bool split_email(const std::string& email, std::string& user, std::string& domain) {

    size_t pos = email.find('@');

    if (pos == std::string::npos)
        return false;

    if (pos != email.rfind('@'))
        return false;

    if (pos == 0 || pos == email.size() - 1)
        return false;

    user = email.substr(0, pos);
    domain = email.substr(pos + 1);

    if (domain.find('.') == std::string::npos)
        return false;

    return true;
}

int main() {

    std::string email, user, domain;

    std::cout << "Unesite email adresu: ";
    std::getline(std::cin, email);

    if (split_email(email, user, domain)) {
        std::cout << "Korisnik: " << user << std::endl;
        std::cout << "Domena: " << domain << std::endl;
    }
    else {
        std::cout << "Neispravna adresa!" << std::endl;
    }

    return 0;
}