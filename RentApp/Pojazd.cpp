#include "Pojazd.h"
#include <iostream>


Pojazd::Pojazd() : marka(""), rokProdukcji(0), moc(0), typ("") {}

 
Pojazd::Pojazd(std::string marka, int rokProdukcji, int moc, std::string typ) : marka(marka), rokProdukcji(rokProdukcji), moc(moc), typ(typ) {}

Pojazd::~Pojazd() {}

void Pojazd::WypiszInformacje() const {    
    if (czyZarezerwowany)
    {
        std::cout << "ZAREZERWOWANY ";
    }
    else {
        std::cout << "NIE-ZAREZERWOWANY ";
    }
    std::cout << "Marka: " << marka << ", Rok produkcji: " << rokProdukcji << ", Moc: " << moc << "KM ";
}

const std::string& Pojazd::PobierzMarke() const {
    return marka;
}

int Pojazd::PobierzRokProdukcji() const {
    return rokProdukcji;
}

int Pojazd::PobierzMoc() const {
    return moc;
}
const std::string& Pojazd::PobierzTyp() const {
    return typ;
}

void Pojazd::ZapiszDoPlikuTxt(std::ofstream& plik) const {
    plik << marka << " " << rokProdukcji << " " << moc << " " << typ << " " << czyZarezerwowany << "\n";
}

void Pojazd::OdczytajZPlikuTxt(std::ifstream& plik) {
    plik >> marka >> rokProdukcji >> moc >> typ >> czyZarezerwowany;
}