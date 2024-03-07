/**
 * @file Pojazd.h
 * @brief Deklaracja klasy Pojazd
 */

#ifndef POJAZD_H
#define POJAZD_H

#pragma once
#include <string>
#include <fstream>

 /**
  * @class Pojazd
  * @brief Klasa reprezentuj¹ca ogólny pojazd
  */

class Pojazd {
public:
    /**
     * @brief Konstruktor domyœlny
     */
    Pojazd();
    /**
     * @brief Konstruktor z parametrami
     * @param marka Marka pojazdu
     * @param rokProdukcji Rok produkcji pojazdu
     * @param moc Moc pojazdu
     * @param typ Typ pojazdu
     */
    Pojazd(std::string marka, int rokProdukcji, int moc, std::string typ = "");
    /**
     * @brief Destruktor pojazdu
     */
    virtual ~Pojazd();
    /**
     * @brief Metoda wypisuj¹ca informacje o pojeŸdzie
     */
    virtual void WypiszInformacje() const;
    /**
     * @brief Metoda pobieraj¹ca markê pojazdu
     * @return Marka pojazdu
     */
    const std::string& PobierzMarke() const;
    /**
     * @brief Metoda pobieraj¹ca rok produkcji pojazdu
     * @return Rok produkcji pojazdu
     */
    int PobierzRokProdukcji() const;
    /**
     * @brief Metoda pobieraj¹ca moc pojazdu
     * @return Moc pojazdu
     */
    int PobierzMoc() const;
    /**
     * @brief Metoda pobieraj¹ca typ pojazdu
     * @return Typ pojazdu
     */
    const std::string& PobierzTyp() const; 
    /**
    * @brief Metoda zapisuj¹ca dane pojazdu do pliku tekstowego.
    * @param plik Strumieñ wyjœciowy do pliku.
    */
    virtual void ZapiszDoPlikuTxt(std::ofstream& plik) const;
    /**
    * @brief Metoda odczytuj¹ca dane pojazdu z pliku tekstowego.
    * @param plik Strumieñ wejœciowy z pliku.
    */
    virtual void OdczytajZPlikuTxt(std::ifstream& plik);
    /**< Zmienna sprawdzaj¹ca czy pojazd jest zarezerwowany */
    bool czyZarezerwowany = 0;
protected:
    /**< Marka pojazdu */
    std::string marka;
    /**< Rok produkcji pojazdu */
    int rokProdukcji;
    /**< Moc pojazdu */
    int moc;
    /**< Typ pojazdu */
    std::string typ;
};

#endif // POJAZD_H

