#include "Motocykl.h"
#include <iostream>


Motocykl::Motocykl() : Pojazd(), rodzaj("") {
    // ewentualne dodatkowe inicjalizacje
}

Motocykl::Motocykl(std::string marka, int rokProdukcji, int moc, std::string rodzaj) : Pojazd(marka, rokProdukcji, moc), rodzaj(rodzaj) {}

Motocykl::~Motocykl() {}

void Motocykl::WypiszInformacje() const {
    Pojazd::WypiszInformacje();
    std::cout << ", Rodzaj: " << rodzaj;
}

std::string Motocykl::PobierzRodzaj() const {
    return rodzaj;
}

void Motocykl::ZapiszDoPlikuTxt(std::ofstream& plik) const {
    plik << "Motocykl " << marka << " " << rokProdukcji << " " << moc << " " << rodzaj << " " << czyZarezerwowany << "\n";
}

// Implementacja funkcji OdczytajZPlikuTxt
void Motocykl::OdczytajZPlikuTxt(std::ifstream& plik) {
    plik >> marka >> rokProdukcji >> moc >> rodzaj >> czyZarezerwowany;
    typ = "Motocykl";
}