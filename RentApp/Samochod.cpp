#include "Samochod.h"
#include <iostream>


Samochod::Samochod() : Pojazd(), liczbaDrzwi(0), naped("") {
    // ewentualne dodatkowe inicjalizacje
}

Samochod::Samochod(std::string marka, int rokProdukcji, int moc, int liczbaDrzwi, std::string naped) : Pojazd(marka, rokProdukcji, moc), liczbaDrzwi(liczbaDrzwi), naped(naped) {}

Samochod::~Samochod() {}

void Samochod::WypiszInformacje() const {
    Pojazd::WypiszInformacje();
    std::cout << ", Liczba drzwi: " << liczbaDrzwi << ", Napêd: " << naped;
}

int Samochod::PobierzLiczbeDrzwi() const {
    return liczbaDrzwi;
}
std::string Samochod::PobierzNaped() const {
    return naped;
}

void Samochod::ZapiszDoPlikuTxt(std::ofstream& plik) const {
    plik << "Samochod " << marka << " " << rokProdukcji << " " << moc << " " << liczbaDrzwi << " " << naped << " " << czyZarezerwowany << "\n";
}

// Implementacja funkcji OdczytajZPlikuTxt
void Samochod::OdczytajZPlikuTxt(std::ifstream& plik) {
    plik >> marka >> rokProdukcji >> moc >> liczbaDrzwi >> naped >> czyZarezerwowany;
    typ = "Samochod";
}