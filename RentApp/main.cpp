// RentApp (main.cpp): Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include "Pojazd.h"
#include "Samochod.h"
#include "Motocykl.h"
#include "funkcje.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "polish");

    std::vector<std::unique_ptr<Pojazd>> pojazdy;

    OdczytajWektorZPlikuTxt(pojazdy, "pojazdy.txt");
    if (pojazdy.empty()) {
        std::cout << "Pusta baza pojazdów. Dodaj pojazdy." << std::endl;
    }

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Pokaż pojazdy" << endl;
        cout << "2. Dokonaj rezerwacji pojazdu" << endl;
        cout << "3. Usuń rezerwację pojazdu" << endl;
        cout << "4. Dodaj nowy pojazd do oferty" << endl;
        cout << "5. Usuń pojazd z oferty" << endl;
        cout << "6. Wyłącz aplikację" << endl;
        cout << "Wybierz opcję: ";

        int wybor;
        cin >> wybor;
            while (std::cin.fail()) {
                std::cout << "Błędny wybór! Spróbuj ponownie:";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> wybor;
            }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (wybor) {
        case 1:
            WypiszPojazdy(pojazdy);
            break;

        case 2:
            ZarezerwujPojazd(pojazdy);
            break;

        case 3:
            UsunRezerwacje(pojazdy);
            break;

        case 4:
            DodajPojazd(pojazdy);
            break;

        case 5:
            UsunPojazd(pojazdy);
            break;

        case 6:
            ZapiszWektorDoPlikuTxt(pojazdy, "pojazdy.txt");
            ZwolnijPamiec(pojazdy);
            std::cout << "\nDziękuję za korzystanie z programu!\nMiłego dnia!\n" << std::endl;
            return 0;

        default:
            cout << "Wybierz opcje z przedziału <1;6>" << endl;
        }
    }

    return 0;
}