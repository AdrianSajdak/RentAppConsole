/**
 * @file Samochod.h
 * @brief Deklaracja klasy Samochod
 */
#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#pragma once
#include "Pojazd.h"
#include <fstream>

/**
 * @brief Klasa reprezentuj�ca samoch�d, dziedzicz�ca po klasie Pojazd.
 */
class Samochod : public Pojazd {
public:
    /**
     * @brief Konstruktor domy�lny klasy Samochod.
     */
    Samochod();
    /**
     * @brief Konstruktor klasy Samochod inicjalizuj�cy obiekt okre�lonymi warto�ciami.
     * @param marka Marka samochodu.
     * @param rokProdukcji Rok produkcji samochodu.
     * @param moc Moc samochodu.
     * @param liczbaDrzwi Liczba drzwi samochodu.
     * @param naped Rodzaj nap�du samochodu.
     */
    Samochod(std::string marka, int rokProdukcji, int moc, int liczbaDrzwi, std::string naped);
    /**
    * @brief Destruktor klasy Samochod.
    */
    virtual ~Samochod();
    /**
     * @brief Metoda wypisuj�ca informacje o samochodzie.
     */
    void WypiszInformacje() const override;
    /**
     * @brief Metoda pobieraj�ca liczb� drzwi samochodu.
     * @return Liczba drzwi.
     */
    int PobierzLiczbeDrzwi() const;
    /**
    * @brief Metoda pobieraj�ca rodzaj nap�du samochodu.
    * @return Rodzaj nap�du.
    */
    std::string PobierzNaped() const;
    /**
    * @brief Metoda zapisuj�ca dane samochodu do pliku tekstowego.
    * @param plik Strumie� wyj�ciowy do pliku.
    */
    void ZapiszDoPlikuTxt(std::ofstream& plik) const override;
    /**
    * @brief Metoda odczytuj�ca dane samochodu z pliku tekstowego.
    * @param plik Strumie� wej�ciowy z pliku.
    */
    void OdczytajZPlikuTxt(std::ifstream& plik) override;
private:
    /**< Liczba drzwi samochodu. */
    int liczbaDrzwi;
    /**< Rodzaj nap�du samochodu. */
    std::string naped;
};

#endif // SAMOCHOD_H
