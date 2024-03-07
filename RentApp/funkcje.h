/**
 * @file FUNKCJE.h
 * @brief Deklaracja funkcji programu
 */
#ifndef FUNKCJE_H
#define FUNKCJE_H

#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include "Pojazd.h"
#include "Samochod.h"
#include "Motocykl.h"

/**
 * @brief Zwalnia pamiêæ z dynamicznie alokowanych obiektów w wektorze.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 */
void ZwolnijPamiec(std::vector<std::unique_ptr<Pojazd>>& pojazdy);
/**
 * @brief Wypisuje informacje o pojazdach zapisanych w wektorze.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 */
void WypiszPojazdy(const std::vector<std::unique_ptr<Pojazd>>& pojazdy);
/**
 * @brief Dodaje nowy pojazd do wektora na podstawie danych podanych przez u¿ytkownika.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 */
void DodajPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy);
/**
 * @brief Usuwa pojazd z wektora na podstawie danych podanych przez u¿ytkownika.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 */
void UsunPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy);
/**
 * @brief Rezerwuje pojazd na podstawie danych podanych przez u¿ytkownika.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 */
void ZarezerwujPojazd(std::vector<std::unique_ptr<Pojazd>>& pojazdy);
/**
 * @brief Usuwa rezerwacjê pojazdu na podstawie danych podanych przez u¿ytkownika.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 */
void UsunRezerwacje(std::vector<std::unique_ptr<Pojazd>>& pojazdy);
/**
 * @brief Zapisuje informacje o pojazdach do pliku tekstowego.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 * @param nazwaPliku Nazwa pliku do zapisu.
 */
void ZapiszWektorDoPlikuTxt(const std::vector<std::unique_ptr<Pojazd>>& pojazdy, const std::string& nazwaPliku);
/**
 * @brief Wczytuje informacje o pojazdach z pliku tekstowego i dodaj do wektora.
 * @param pojazdy Wektor wskaŸników na obiekty klasy Pojazd.
 * @param nazwaPliku Nazwa pliku do odczytu.
 */
void OdczytajWektorZPlikuTxt(std::vector<std::unique_ptr<Pojazd>>& pojazdy, const std::string& nazwaPliku);

#endif // FUNKCJE_H
