/**
 * @file Motocykl.h
 * @brief Deklaracja klasy Motocykl
 */
#ifndef MOTOCYKL_H
#define MOTOCYKL_H

#pragma once
#include "Pojazd.h"
#include <fstream>

 /**
  * @brief Klasa reprezentuj�ca motocykl, dziedzicz�ca po klasie Pojazd.
  */
class Motocykl : public Pojazd {
public:
    /**
     * @brief Konstruktor domy�lny klasy Motocykl.
     */
    Motocykl();
    /**
     * @brief Konstruktor klasy Motocykl inicjalizuj�cy obiekt okre�lonymi warto�ciami.
     * @param marka Marka motocykla.
     * @param rokProdukcji Rok produkcji motocykla.
     * @param moc Moc motocykla.
     * @param rodzaj Rodzaj motocykla.
     */
    Motocykl(std::string marka, int rokProdukcji, int moc, std::string rodzaj);
    /**
     * @brief Destruktor klasy Motocykl.
     */
    virtual ~Motocykl();
    /**
     * @brief Metoda wypisuj�ca informacje o motocyklu.
     */
    void WypiszInformacje() const override;
    /**
     * @brief Metoda pobieraj�ca rodzaj motocykla.
     * @return Rodzaj motocykla.
     */
    std::string PobierzRodzaj() const;
    /**
     * @brief Metoda zapisuj�ca dane motocykla do pliku tekstowego.
     * @param plik Strumie� wyj�ciowy do pliku.
     */
    void ZapiszDoPlikuTxt(std::ofstream& plik) const override;
    /**
     * @brief Metoda odczytuj�ca dane motocykla z pliku tekstowego.
     * @param plik Strumie� wej�ciowy z pliku.
     */
    void OdczytajZPlikuTxt(std::ifstream& plik) override;

private:
    /**< Rodzaj motocykla. */
    std::string rodzaj;
};

#endif // MOTOCYKL_H
