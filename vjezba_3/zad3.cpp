#include <iostream>
#include <vector>
#include <array>

/*
3. Broj dana u tjednu zadajte kao constexpr int DAYS = 7;. Sati učenja po danima čuvaju
se u std::array<double, DAYS>.
◦ Napišite funkciju double total(const std::array<double, DAYS>& hours) koja
vraća ukupan broj sati u tjednu.
◦ Napišite funkciju int best_day(const std::array<double, DAYS>& hours) koja
vraća redni broj dana (od 1) s najviše sati učenja.
◦ Za prvi tjedan korisnik unosi sate za svaki dan. Pomoću funkcija ispišite ukupan
broj sati i dan s najviše sati učenja.
◦ Drugi tjedan popunite s fill(1.5). Usporedite tjedne operatorima == i <, zamijenite ih sa swap i ponovno ispišite ukupne sate.

*/

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours) {
   
    double suma = 0;

    for (int i = 0; i < DAYS; i++) {
        suma += hours[i];
    }

    return suma;
}

int best_day(const std::array<double, DAYS>& hours) {
    int najdan = 0;

    for (int i = 1; i < DAYS; i++) {
        if (hours[i] > hours[najdan]) {
            najdan = i;
        }
    }

    return najdan + 1;
}

int main() {
    std::array<double, DAYS> week1;
    std::array<double, DAYS> week2;

    for (int i = 0; i < DAYS; i++) {
        std::cout << "Unesite sate za " << i + 1 << ". dan: ";
        std::cin >> week1[i];
    }

    std::cout << "Ukupno sati: " << total(week1) << std::endl;
    std::cout << "Najbolji dan: " << best_day(week1) << std::endl;

    week2.fill(1.5);

    if (week1 == week2) {
        std::cout << "Tjedni su jednaki." << std::endl;
    }
    else {
        std::cout << "Tjedni nisu jednaki." << std::endl;
    }

    if (week1 < week2) {
        std::cout << "Prvi tjedan je manji od drugog." << std::endl;
    }
    else {
        std::cout << "Prvi tjedan nije manji od drugog." << std::endl;
    }

    week1.swap(week2);

    std::cout << "Nakon zamjene:" << std::endl;
    std::cout << "Prvi tjedan: " << total(week1) << std::endl;
    std::cout << "Drugi tjedan: " << total(week2) << std::endl;

    return 0;
}
