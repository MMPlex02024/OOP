#include <iostream>
#include <string>
#include <vector>

/*
Napišite funkciju std::vector<std::string> split_words(const std::string& text)
koja rečenicu dijeli na riječi (find, substr). Riječi mogu biti odvojene s više razmaka. Za
rečenicu koju korisnik unese ispišite:
◦ broj riječi i najdulju riječ,
◦ riječi obrnutim redoslijedom, spojene znakom - u jedan string (+=),
◦ riječ koja je prva po abecedi (operator <).
banana Zebra auto Mrkva kiwi
broj rijeci: 5
najdulja: banana
kiwi-Mrkva-auto-Zebra-banana
prva po abecedi: Mrkva


*/
std::vector<std::string> split_words(const std::string& text) {

    std::vector<std::string> words;
    size_t start = 0;

    while (start < text.size()) {

        if (text[start] == ' ') {
            start++;
            continue;
        }

        size_t end = text.find(' ', start);

        if (end == std::string::npos) {
            words.push_back(text.substr(start));
            break;
        }

        words.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    return words;
}

int main() {

    std::string text;

    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, text);

    std::vector<std::string> words = split_words(text);

    std::cout << "Broj rijeci: " << words.size() << std::endl;

    if (words.empty()) {
        return 0;
    }

    std::string najdulja = words[0];
    std::string prva = words[0];

    for (int i = 1; i < words.size(); i++) {

        if (words[i].size() > najdulja.size()) {
            najdulja = words[i];
        }

        if (words[i] < prva) {
            prva = words[i];
        }
    }

    std::cout << "Najdulja: " << najdulja << std::endl;

    std::string obrnuto = "";

    for (int i = static_cast<int>(words.size()) - 1; i >= 0; i--) {
        obrnuto += words[i];

        if (i > 0) {
            obrnuto += "-";
        }
    }

    std::cout << obrnuto << std::endl;
    std::cout << "Prva po abecedi: " << prva << std::endl;

    return 0;
}
