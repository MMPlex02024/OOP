#include <iostream>
#include <string>


/*
. Napišite funkcije
◦ std::string with_separators(std::string digits) koja broju zapisanom kao
string umeće točku ispred svake skupine od tri znamenke, gledano s desna (insert);
broj može biti negativan,
◦ std::string without_separators(std::string text) koja uklanja sve točke (find
, erase).
"1234567" -> "1.234.567" "-1234567" -> "-1.234.567"
"100000" -> "100.000" "1.234.567" -> "1234567"
Zašto je lakše umetati točke krenuvši od kraja stringa?


*/


std::string with_separators(std::string digits) {

    int start = 0;

    if (digits[0] == '-')
        start = 1;

    for (int i = digits.size() - 3; i > start; i -= 3) {
        digits.insert(i, ".");
    }

    return digits;
}

std::string without_separators(std::string text) {

    size_t pos = text.find('.');

    while (pos != std::string::npos) {
        text.erase(pos, 1);
        pos = text.find('.');
    }

    return text;
}

int main() {

    std::string broj;

    std::cout << "Unesite broj: ";
    std::cin >> broj;

    std::string novi = with_separators(broj);

    std::cout << "S tockama: " << novi << std::endl;
    std::cout << "Bez tocaka: " << without_separators(novi) << std::endl;

    return 0;
}
