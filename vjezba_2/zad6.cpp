
#include <iostream>
#include <string>

struct Student {
    std::string ime;
    std::string JMBAG;
    int godina;
    int ects;
    double prosjek;
};

void ispisi(Student& s) {
    std::cout << s.ime << " " << s.JMBAG
        << " Godina: " << s.godina
        << " ECTS: " << s.ects
        << " Prosjek: " << s.prosjek << "\n";
}

void povecaj_godinu(Student& s) {
    s.godina++;
}

void filter_students(Student s[], int n,
    void (*action)(Student&),
    bool (*cond)(const Student&)) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

int main() {
    Student studenti[] = {
        {"Marko", "1234567890", 1, 50, 4.2},
        {"Dinko", "2345678901", 1, 0, 3.0},
        {"Anamarija", "3456789012", 2, 55, 4.5},
        {"Petar", "4567890123", 3, 30, 3.8},
        {"Luka", "5678901234", 1, 20, 2.9}
    };

    int n = 5;

    std::cout << "Studenti prve godine s polozenim ispitom:\n";
    filter_students(studenti, n, ispisi, [](const Student& s) {
        return s.godina == 1 && s.ects > 0;
        });

    std::cout << "\nStudenti s prosjekom vecim od 3.5:\n";
    filter_students(studenti, n, ispisi, [](const Student& s) {
        return s.prosjek > 3.5;
        });

    filter_students(studenti, n, povecaj_godinu, [](const Student& s) {
        return s.ects >= 45;
        });

    std::cout << "\nStudenti nakon povecanja godine:\n";
    for (int i = 0; i < n; i++) {
        ispisi(studenti[i]);
    }

    return 0;
}
