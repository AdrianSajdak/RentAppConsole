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
  * @brief Klasa reprezentuj�ca og�lny pojazd
  */

class Pojazd {
public:
    /**
     * @brief Konstruktor domy�lny
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
     * @brief Metoda wypisuj�ca informacje o poje�dzie
     */
    virtual void WypiszInformacje() const;
    /**
     * @brief Metoda pobieraj�ca mark� pojazdu
     * @return Marka pojazdu
     */
    const std::string& PobierzMarke() const;
    /**
     * @brief Metoda pobieraj�ca rok produkcji pojazdu
     * @return Rok produkcji pojazdu
     */
    int PobierzRokProdukcji() const;
    /**
     * @brief Metoda pobieraj�ca moc pojazdu
     * @return Moc pojazdu
     */
    int PobierzMoc() const;
    /**
     * @brief Metoda pobieraj�ca typ pojazdu
     * @return Typ pojazdu
     */
    const std::string& PobierzTyp() const; 
    /**
    * @brief Metoda zapisuj�ca dane pojazdu do pliku tekstowego.
    * @param plik Strumie� wyj�ciowy do pliku.
    */
    virtual void ZapiszDoPlikuTxt(std::ofstream& plik) const;
    /**
    * @brief Metoda odczytuj�ca dane pojazdu z pliku tekstowego.
    * @param plik Strumie� wej�ciowy z pliku.
    */
    virtual void OdczytajZPlikuTxt(std::ifstream& plik);
    /**< Zmienna sprawdzaj�ca czy pojazd jest zarezerwowany */
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

