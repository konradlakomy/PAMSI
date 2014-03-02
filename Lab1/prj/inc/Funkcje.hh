#ifndef FUNKCJE_HH
#define FUNKCJE_HH
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
using namespace std; 

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za operacje na kontenerach.
 *
 *  Plik zawiera deklaracje funkcji odpowiedzialnych za wykonywanie operacji na kontenerach 
 *  sa to funkcje wczytaj, pomnoz, porownaj dzialajace w oparciu o biblioteke <vector>
 */


/*!
 *
 * \brief Definicja funkcji wczytującej dane do kontenera
 *
 * \param[in] Tab - referencja na kontener tablicy (vector).
 *
 * \param[in] NazwaPliku - zmienna zawierajaca nazwe pliku z ktorego pobierany jest zestaw danych
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad odczytu.
 *
 */
int wczytaj(vector <int>& Tab, string NazwaPliku);

/*!
 *
 * \brief Definicja funkcji wykonujacej operacje mnożenia elementow kontenera
 *
 * \param[in] Tab - referencja na kontener tablicy (vector).
 *
 * \return Funkcja nie zwraca zadnej wartości 
 *
 */

void pomnoz(vector <int>& Tab);

/*!
 * 
 * \brief Definicja funkcji porównującej dwa kontenery
 *
 * \param[in] Tab1 - referencja na kontener tablicy (vector).
 * 
 * \param[in] Tab2 - referencja na kontener tablicy (vector).
 *
 * \return Zwraca wartośc 1 gdy kontenery są takie same, 0 gdy są rózne.
 *
 */
int porownaj(vector <int>& Tab1, vector <int>& Tab2);
#endif
