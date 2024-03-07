#include "funkcje.h"
#include <iostream>
#include <fstream>
#include <algorithm> // np.: find_if

void ZwolnijPamiec(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    pojazdy.clear();
}

void WypiszPojazdy(const std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazdów jest pusta." << std::endl;
        return;  // Zakoñcz dzia³anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Lista pojazdow:" << std::endl;

    for (const auto& pojazd : pojazdy) {
        pojazd->WypiszInformacje();
        std::cout << std::endl;
    }
}

void DodajPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    std::cout << "Czy dodawany pojazd to samochód czy motocykl? (s/m): ";
    char typ;
    std::cin >> typ;
        while (std::cin.fail() || (typ != 's' && typ != 'm')) {
            std::cout << "B³êdne dane. Podaj poprawny typ (s/m): ";
            std::cin.clear();  // Czyszczenie flagi b³êdu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Usuwanie b³êdnych danych z bufora
            std::cin >> typ;
        }

    std::string marka;
    int moc, rokProdukcji;

    std::cout << "Podaj markê pojazdu: ";
    std::cin >> marka;
        while (marka.empty()) {
            std::cout << "Nie podano marki pojazdu. Spróbuj ponownie.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> marka;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Podaj rok produkcji pojazdu: ";
    std::cin >> rokProdukcji;
        while (std::cin.fail()) {
            std::cout << "B³êdne dane. Podaj poprawny rok produkcji pojazdu: ";
            std::cin.clear();
            //std::numeric_limits<std::streamsize>::max() zwraca maksymaln¹ wartoœæ, jak¹ mo¿e przyj¹æ typ std::streamsize
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
            std::cin >> rokProdukcji;
        }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
        while (std::cin.fail()) {
            std::cout << "B³êdne dane. Podaj poprawn¹ moc pojazdu: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> moc;
        }

    if (typ == 's') {
        int liczbaDrzwi;
        std::string opcjeNaped[] = { "AWD", "RWD", "FWD" };
        std::string naped;
        bool dobraOpcja = false;

        std::cout << "Podaj liczbê drzwi: ";
        std::cin >> liczbaDrzwi;
            while (std::cin.fail()) {
                std::cout << "B³êdne dane. Podaj poprawn¹ moc pojazdu: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> liczbaDrzwi;
            }

            while (!dobraOpcja) {
                std::cout << "Podaj rodzaj napêdu (AWD/RWD/FWD): ";
                std::cin >> naped;

                if (!naped.empty()) {
                    for (const std::string& opcja : opcjeNaped) {
                        if (naped == opcja) {
                            dobraOpcja = true;
                            break;
                        }
                    }
                    if (!dobraOpcja) {
                        std::cout << "Niepoprawna opcja. Spróbuj ponownie." << std::endl;
                    }
                }
                else {
                    std::cout << "Podany ci¹g znaków nie mo¿e byæ pusty. Spróbuj ponownie." << std::endl;
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        // Stworzenie nowego samochodu
        std::unique_ptr<Pojazd> nowySamochod = std::make_unique<Samochod>(marka, rokProdukcji, moc, liczbaDrzwi, naped);
        pojazdy.push_back(std::move(nowySamochod));
    }
    else if (typ == 'm') {
        std::string rodzaj;

        std::cout << "Podaj rodzaj motocykla: ";
        std::cin >> rodzaj;
            while (rodzaj.empty()) {
                std::cout << "Nie podano rodzaju motocykla. Spróbuj ponownie.";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> rodzaj;
            }

        std::unique_ptr<Pojazd> nowyMotocykl = std::make_unique<Motocykl>(marka, rokProdukcji, moc, rodzaj);
        pojazdy.push_back(std::move(nowyMotocykl));
    }
    else {
        std::cout << "B³êdny wybór. Nie dodano pojazdu." << std::endl;
        return;
    }
    std::cout << "Pojazd dodany do bazy danych." << std::endl;
}

void UsunPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazdów jest pusta." << std::endl;
        return;  // Zakoñcz dzia³anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Podaj markê pojazdu: ";
    std::string marka;
    std::cin >> marka;
        while(marka.empty()) {
            std::cout << "Nie podano marki pojazdu. Spróbuj ponownie.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> marka;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int moc, rokProdukcji;

    std::cout << "Podaj rok produkcji pojazdu: ";
    std::cin >> rokProdukcji;
        while (std::cin.fail()) {
            std::cout << "B³êdne dane. Podaj poprawny rok produkcji pojazdu: ";
            std::cin.clear();
            //std::numeric_limits<std::streamsize>::max() zwraca maksymaln¹ wartoœæ, jak¹ mo¿e przyj¹æ typ std::streamsize
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
            std::cin >> rokProdukcji;
        }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
        while (std::cin.fail()) {
            std::cout << "B³êdne dane. Podaj poprawn¹ moc pojazdu: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> moc;
        }

    auto it = std::find_if(pojazdy.begin(), pojazdy.end(),
        [&](const std::unique_ptr<Pojazd>& pojazd) {
            return pojazd->PobierzMarke() == marka &&
                pojazd->PobierzMoc() == moc &&
                pojazd->PobierzRokProdukcji() == rokProdukcji;
        });

    if (it != pojazdy.end()) {
        if ((*it)->czyZarezerwowany) {
            std::cout << "Nie mo¿na usun¹æ zarezerwowanego pojazdu." << std::endl;
        }
        else {
            pojazdy.erase(it);
            std::cout << "Pojazd usuniêty z bazy danych." << std::endl;
        }
    }
    else {
        std::cout << "Nie znaleziono pojazdu o podanych parametrach." << std::endl;
    }
}

void ZarezerwujPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazdów jest pusta." << std::endl;
        return;  // Zakoñcz dzia³anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Podaj markê pojazdu: ";
    std::string marka;
    std::cin >> marka;
    while (marka.empty()) {
        std::cout << "Nie podano marki pojazdu. Spróbuj ponownie.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> marka;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int moc, rokProdukcji;

    std::cout << "Podaj rok produkcji pojazdu: ";
    std::cin >> rokProdukcji;
    while (std::cin.fail()) {
        std::cout << "B³êdne dane. Podaj poprawny rok produkcji pojazdu: ";
        std::cin.clear();
        //std::numeric_limits<std::streamsize>::max() zwraca maksymaln¹ wartoœæ, jak¹ mo¿e przyj¹æ typ std::streamsize
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
        std::cin >> rokProdukcji;
    }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
    while (std::cin.fail()) {
        std::cout << "B³êdne dane. Podaj poprawn¹ moc pojazdu: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> moc;
    }

    auto it = std::find_if(pojazdy.begin(), pojazdy.end(),
        [&](const std::unique_ptr<Pojazd>& pojazd) {
            return pojazd->PobierzMarke() == marka &&
                pojazd->PobierzRokProdukcji() == rokProdukcji &&
                pojazd->PobierzMoc() == moc;
        });

    if (it != pojazdy.end()) {
        if ((*it)->czyZarezerwowany) {
            std::cout << "Pojazd jest ju¿ zarezerwowany." << std::endl;
        }
        else {
            int pin;
            std::cout << "Podaj PIN: ";
            std::cin >> pin;
                if(std::cin.fail()) {
                    std::cout << "B³êdnie wprowadzono PIN.";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            if (pin == 1234) {
                (*it)->czyZarezerwowany = 1;

                std::cout << "Pojazd zosta³ zarezerwowany." << std::endl;
            }
            else {
                std::cout << "Nieprawid³owy PIN. Rezerwacja nie zosta³a dokonana." << std::endl;
            }
        }
    }
    else {
        std::cout << "Nie znaleziono pojazdu o podanych parametrach." << std::endl;
    }
}

void UsunRezerwacje(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazdów jest pusta." << std::endl;
        return;  // Zakoñcz dzia³anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Podaj markê pojazdu: ";
    std::string marka;
    std::cin >> marka;
    while (marka.empty()) {
        std::cout << "Nie podano marki pojazdu. Spróbuj ponownie.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> marka;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int moc, rokProdukcji;

    std::cout << "Podaj rok produkcji pojazdu: ";
    std::cin >> rokProdukcji;
    while (std::cin.fail()) {
        std::cout << "B³êdne dane. Podaj poprawny rok produkcji pojazdu: ";
        std::cin.clear();
        //std::numeric_limits<std::streamsize>::max() zwraca maksymaln¹ wartoœæ, jak¹ mo¿e przyj¹æ typ std::streamsize
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
        std::cin >> rokProdukcji;
    }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
    while (std::cin.fail()) {
        std::cout << "B³êdne dane. Podaj poprawn¹ moc pojazdu: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> moc;
    }

    auto it = std::find_if(pojazdy.begin(), pojazdy.end(),
        [&](const std::unique_ptr<Pojazd>& pojazd) {
            return pojazd->PobierzMarke() == marka &&
                pojazd->PobierzRokProdukcji() == rokProdukcji &&
                pojazd->PobierzMoc() == moc;
        });

    if (it != pojazdy.end()) {
        if ((*it)->czyZarezerwowany) {

            int pin;
            std::cout << "Podaj PIN: ";
            std::cin >> pin;
                if (std::cin.fail()) {
                    std::cout << "B³êdnie wprowadzono PIN."; 
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            if (pin == 1234) {
                (*it)->czyZarezerwowany = 0;

                std::cout << "Rezerwacja zosta³a anulowana." << std::endl;
            }
            else {
                std::cout << "Nieprawid³owy PIN. Rezerwacja nie zosta³a anulowana." << std::endl;
            }
        }
        else {
            std::cout << "Pojazd nie jest zarezerwowany." << std::endl;
        }
    }
    else {
        std::cout << "Nie znaleziono pojazdu o podanych parametrach." << std::endl;
    }
}

void ZapiszWektorDoPlikuTxt(const std::vector<std::unique_ptr<Pojazd>>& pojazdy, const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku do zapisu." << std::endl;
        return;
    }

    for (const auto& pojazd : pojazdy) {
        pojazd->ZapiszDoPlikuTxt(plik);
    }

    plik.close();
    std::cout << "Zapis zakoñczony" << std::endl;
}
void OdczytajWektorZPlikuTxt(std::vector<std::unique_ptr<Pojazd>>& pojazdy, const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku do odczytu." << std::endl;
        return;
    }

    while (!plik.eof()) {
        std::string typ;
        plik >> typ;

        if (typ == "Samochod") {
            std::unique_ptr<Samochod> samochod = std::make_unique<Samochod>();
            samochod->OdczytajZPlikuTxt(plik);
            pojazdy.push_back(std::move(samochod));
        }
        else if (typ == "Motocykl") {
            std::unique_ptr<Motocykl> motocykl = std::make_unique<Motocykl>();
            motocykl->OdczytajZPlikuTxt(plik);
            pojazdy.push_back(std::move(motocykl));
        }
        else {
            break;
        }
    }

    plik.close();
    std::cout << "Wczytywanie zakoñczone" << std::endl;
}