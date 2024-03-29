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
  * @brief Klasa reprezentująca motocykl, dziedzicząca po klasie Pojazd.
  */
class Motocykl : public Pojazd {
public:
    /**
     * @brief Konstruktor domyślny klasy Motocykl.
     */
    Motocykl();
    /**
     * @brief Konstruktor klasy Motocykl inicjalizujący obiekt określonymi wartościami.
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
     * @brief Metoda wypisująca informacje o motocyklu.
     */
    void WypiszInformacje() const override;
    /**
     * @brief Metoda pobierająca rodzaj motocykla.
     * @return Rodzaj motocykla.
     */
    std::string PobierzRodzaj() const;
    /**
     * @brief Metoda zapisująca dane motocykla do pliku tekstowego.
     * @param plik Strumień wyjściowy do pliku.
     */
    void ZapiszDoPlikuTxt(std::ofstream& plik) const override;
    /**
     * @brief Metoda odczytująca dane motocykla z pliku tekstowego.
     * @param plik Strumień wejściowy z pliku.
     */
    void OdczytajZPlikuTxt(std::ifstream& plik) override;

private:
    /**< Rodzaj motocykla. */
    std::string rodzaj;
};

#endif // MOTOCYKL_H
