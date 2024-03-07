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
 * @brief Klasa reprezentuj¹ca samochód, dziedzicz¹ca po klasie Pojazd.
 */
class Samochod : public Pojazd {
public:
    /**
     * @brief Konstruktor domyœlny klasy Samochod.
     */
    Samochod();
    /**
     * @brief Konstruktor klasy Samochod inicjalizuj¹cy obiekt okreœlonymi wartoœciami.
     * @param marka Marka samochodu.
     * @param rokProdukcji Rok produkcji samochodu.
     * @param moc Moc samochodu.
     * @param liczbaDrzwi Liczba drzwi samochodu.
     * @param naped Rodzaj napêdu samochodu.
     */
    Samochod(std::string marka, int rokProdukcji, int moc, int liczbaDrzwi, std::string naped);
    /**
    * @brief Destruktor klasy Samochod.
    */
    virtual ~Samochod();
    /**
     * @brief Metoda wypisuj¹ca informacje o samochodzie.
     */
    void WypiszInformacje() const override;
    /**
     * @brief Metoda pobieraj¹ca liczbê drzwi samochodu.
     * @return Liczba drzwi.
     */
    int PobierzLiczbeDrzwi() const;
    /**
    * @brief Metoda pobieraj¹ca rodzaj napêdu samochodu.
    * @return Rodzaj napêdu.
    */
    std::string PobierzNaped() const;
    /**
    * @brief Metoda zapisuj¹ca dane samochodu do pliku tekstowego.
    * @param plik Strumieñ wyjœciowy do pliku.
    */
    void ZapiszDoPlikuTxt(std::ofstream& plik) const override;
    /**
    * @brief Metoda odczytuj¹ca dane samochodu z pliku tekstowego.
    * @param plik Strumieñ wejœciowy z pliku.
    */
    void OdczytajZPlikuTxt(std::ifstream& plik) override;
private:
    /**< Liczba drzwi samochodu. */
    int liczbaDrzwi;
    /**< Rodzaj napêdu samochodu. */
    std::string naped;
};

#endif // SAMOCHOD_H
