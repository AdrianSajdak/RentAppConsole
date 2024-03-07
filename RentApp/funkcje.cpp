#include "funkcje.h"
#include <iostream>
#include <fstream>
#include <algorithm> // np.: find_if

void ZwolnijPamiec(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    pojazdy.clear();
}

void WypiszPojazdy(const std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazd�w jest pusta." << std::endl;
        return;  // Zako�cz dzia�anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Lista pojazdow:" << std::endl;

    for (const auto& pojazd : pojazdy) {
        pojazd->WypiszInformacje();
        std::cout << std::endl;
    }
}

void DodajPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    std::cout << "Czy dodawany pojazd to samoch�d czy motocykl? (s/m): ";
    char typ;
    std::cin >> typ;
        while (std::cin.fail() || (typ != 's' && typ != 'm')) {
            std::cout << "B��dne dane. Podaj poprawny typ (s/m): ";
            std::cin.clear();  // Czyszczenie flagi b��du
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Usuwanie b��dnych danych z bufora
            std::cin >> typ;
        }

    std::string marka;
    int moc, rokProdukcji;

    std::cout << "Podaj mark� pojazdu: ";
    std::cin >> marka;
        while (marka.empty()) {
            std::cout << "Nie podano marki pojazdu. Spr�buj ponownie.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> marka;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Podaj rok produkcji pojazdu: ";
    std::cin >> rokProdukcji;
        while (std::cin.fail()) {
            std::cout << "B��dne dane. Podaj poprawny rok produkcji pojazdu: ";
            std::cin.clear();
            //std::numeric_limits<std::streamsize>::max() zwraca maksymaln� warto��, jak� mo�e przyj�� typ std::streamsize
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
            std::cin >> rokProdukcji;
        }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
        while (std::cin.fail()) {
            std::cout << "B��dne dane. Podaj poprawn� moc pojazdu: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> moc;
        }

    if (typ == 's') {
        int liczbaDrzwi;
        std::string opcjeNaped[] = { "AWD", "RWD", "FWD" };
        std::string naped;
        bool dobraOpcja = false;

        std::cout << "Podaj liczb� drzwi: ";
        std::cin >> liczbaDrzwi;
            while (std::cin.fail()) {
                std::cout << "B��dne dane. Podaj poprawn� moc pojazdu: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> liczbaDrzwi;
            }

            while (!dobraOpcja) {
                std::cout << "Podaj rodzaj nap�du (AWD/RWD/FWD): ";
                std::cin >> naped;

                if (!naped.empty()) {
                    for (const std::string& opcja : opcjeNaped) {
                        if (naped == opcja) {
                            dobraOpcja = true;
                            break;
                        }
                    }
                    if (!dobraOpcja) {
                        std::cout << "Niepoprawna opcja. Spr�buj ponownie." << std::endl;
                    }
                }
                else {
                    std::cout << "Podany ci�g znak�w nie mo�e by� pusty. Spr�buj ponownie." << std::endl;
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
                std::cout << "Nie podano rodzaju motocykla. Spr�buj ponownie.";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> rodzaj;
            }

        std::unique_ptr<Pojazd> nowyMotocykl = std::make_unique<Motocykl>(marka, rokProdukcji, moc, rodzaj);
        pojazdy.push_back(std::move(nowyMotocykl));
    }
    else {
        std::cout << "B��dny wyb�r. Nie dodano pojazdu." << std::endl;
        return;
    }
    std::cout << "Pojazd dodany do bazy danych." << std::endl;
}

void UsunPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazd�w jest pusta." << std::endl;
        return;  // Zako�cz dzia�anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Podaj mark� pojazdu: ";
    std::string marka;
    std::cin >> marka;
        while(marka.empty()) {
            std::cout << "Nie podano marki pojazdu. Spr�buj ponownie.";
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
            std::cout << "B��dne dane. Podaj poprawny rok produkcji pojazdu: ";
            std::cin.clear();
            //std::numeric_limits<std::streamsize>::max() zwraca maksymaln� warto��, jak� mo�e przyj�� typ std::streamsize
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
            std::cin >> rokProdukcji;
        }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
        while (std::cin.fail()) {
            std::cout << "B��dne dane. Podaj poprawn� moc pojazdu: ";
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
            std::cout << "Nie mo�na usun�� zarezerwowanego pojazdu." << std::endl;
        }
        else {
            pojazdy.erase(it);
            std::cout << "Pojazd usuni�ty z bazy danych." << std::endl;
        }
    }
    else {
        std::cout << "Nie znaleziono pojazdu o podanych parametrach." << std::endl;
    }
}

void ZarezerwujPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazd�w jest pusta." << std::endl;
        return;  // Zako�cz dzia�anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Podaj mark� pojazdu: ";
    std::string marka;
    std::cin >> marka;
    while (marka.empty()) {
        std::cout << "Nie podano marki pojazdu. Spr�buj ponownie.";
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
        std::cout << "B��dne dane. Podaj poprawny rok produkcji pojazdu: ";
        std::cin.clear();
        //std::numeric_limits<std::streamsize>::max() zwraca maksymaln� warto��, jak� mo�e przyj�� typ std::streamsize
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
        std::cin >> rokProdukcji;
    }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
    while (std::cin.fail()) {
        std::cout << "B��dne dane. Podaj poprawn� moc pojazdu: ";
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
            std::cout << "Pojazd jest ju� zarezerwowany." << std::endl;
        }
        else {
            int pin;
            std::cout << "Podaj PIN: ";
            std::cin >> pin;
                if(std::cin.fail()) {
                    std::cout << "B��dnie wprowadzono PIN.";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            if (pin == 1234) {
                (*it)->czyZarezerwowany = 1;

                std::cout << "Pojazd zosta� zarezerwowany." << std::endl;
            }
            else {
                std::cout << "Nieprawid�owy PIN. Rezerwacja nie zosta�a dokonana." << std::endl;
            }
        }
    }
    else {
        std::cout << "Nie znaleziono pojazdu o podanych parametrach." << std::endl;
    }
}

void UsunRezerwacje(std::vector<std::unique_ptr<Pojazd>>& pojazdy) {
    if (pojazdy.empty()) {
        std::cout << "Baza pojazd�w jest pusta." << std::endl;
        return;  // Zako�cz dzia�anie funkcji, gdy wektor jest pusty
    }

    std::cout << "Podaj mark� pojazdu: ";
    std::string marka;
    std::cin >> marka;
    while (marka.empty()) {
        std::cout << "Nie podano marki pojazdu. Spr�buj ponownie.";
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
        std::cout << "B��dne dane. Podaj poprawny rok produkcji pojazdu: ";
        std::cin.clear();
        //std::numeric_limits<std::streamsize>::max() zwraca maksymaln� warto��, jak� mo�e przyj�� typ std::streamsize
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruje az do napotkania nowej linii
        std::cin >> rokProdukcji;
    }

    std::cout << "Podaj moc pojazdu: ";
    std::cin >> moc;
    while (std::cin.fail()) {
        std::cout << "B��dne dane. Podaj poprawn� moc pojazdu: ";
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
                    std::cout << "B��dnie wprowadzono PIN."; 
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            if (pin == 1234) {
                (*it)->czyZarezerwowany = 0;

                std::cout << "Rezerwacja zosta�a anulowana." << std::endl;
            }
            else {
                std::cout << "Nieprawid�owy PIN. Rezerwacja nie zosta�a anulowana." << std::endl;
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
        std::cerr << "Nie mo�na otworzy� pliku do zapisu." << std::endl;
        return;
    }

    for (const auto& pojazd : pojazdy) {
        pojazd->ZapiszDoPlikuTxt(plik);
    }

    plik.close();
    std::cout << "Zapis zako�czony" << std::endl;
}
void OdczytajWektorZPlikuTxt(std::vector<std::unique_ptr<Pojazd>>& pojazdy, const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie mo�na otworzy� pliku do odczytu." << std::endl;
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
    std::cout << "Wczytywanie zako�czone" << std::endl;
}