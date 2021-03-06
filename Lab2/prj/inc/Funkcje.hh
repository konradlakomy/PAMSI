#ifndef FUNKCJE_HH
#define FUNKCJE_HH
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>
#include <string>
#include <iomanip> 
using namespace std; 

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za operacje na kontenerach.
 *
 *  Plik zawiera deklaracje metod odpowiedzialnych za wykonywanie operacji na kontenerach 
 *  sa to funkcje dzialajace w oparciu o biblioteke <vector>
 */



/*!
 * \brief Modeluje pojecie tablicy liczb i metod z nia zwiazanych.
 *
 *  Deklaracja klasy TablicaLiczb opisujacej 
 *  kontener tablicy zawierajacej elementy typu integer. 
 */

class TablicaLiczb {
vector < int > Tab;
public:

/*!
 * \brief Metoda odpowiedzialna za indeksowanie elementow kontenera.
 * 
 * Metoda odpowiedzialana jest za indeksowanie wartosci ktore sa elementami kontenera.
 */
int 	   & operator[](int i)       { return Tab[i]; } 

/*!
 * \brief Metoda odpowiedzialna za indeksowanie elementow kontenera.
 * 
 * Metoda odpowiedzialana jest za indeksowanie wartosci ktore sa elementami kontenera.
 */
int  const & operator[](int i) const { return Tab[i]; }


/*!
 *
 * \brief Definicja metody wczytującej dane do kontenera
 *
 * \param[in] NazwaPliku - zmienna zawierajaca nazwe pliku z ktorego pobierany jest zestaw danych
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad odczytu.
 *
 */

bool wczytaj(string NazwaPliku);

/*!
 *
 * \brief Definicja metody wyswietlajacej dane kontenera
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad.
 *
 */

bool wyswietl();

/*!
 *
 * \brief Definicja metody wykonujacej operacje mnożenia elementow kontenera
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad.
 *
 */

bool pomnoz();

/*!
 *
 * \brief Definicja metody wykonujacej operacje zamiany dwoch elementow kontenera
 *
 * \param[in] i - indeks elementu kontenera tablicy.
 *
 * \param[in] j - indeks elementu kontenera tablicy.
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad.
 *
 */

bool zamien_elementy(unsigned int i,unsigned int j);

/*!
 *
 * \brief Definicja metody wykonujacej operacje odwrocenia kolejnosci elementow wektora
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad.
 *
 */

bool odwroc_kolejnosc();

/*!
 *
 * \brief Definicja metody dodajacej kolejne dane do kontenera
 *
 * \param[in] element - zmienna zawierajaca element typu integer ktory zostanie dodany do kontenera. 
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad odczytu.
 *
 */

int dodaj_element(int element);

/*!
 *
 * \brief Definicja metody kasujacej dane kontenera
 *
 * \return Metoda nie zwraca zadnej wartosci.
 *
 */

void wyczysc();

/*!
 *
 * \brief Definicja funkcji wykonujacej operacje porownania dwoch kontenerow
 *
 * \param[in] Tab1 - Kontener tablicy elementow.
 *
 * \param[in] Tab2 - Kontener tablicy elementow.
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad.
 *
 */

friend bool porownaj(TablicaLiczb Tab1, TablicaLiczb Tab2);

/*!
 *
 * \brief Definicja przeciazenia operatora porownania '==' wykonujacego operacje porownania dwoch kontenerow
 *
 * \param[in] Tab1 - Kontener tablicy elementow.
 *
 * \param[in] Tab2 - Kontener tablicy elementow.
 *
 * \return Zwraca wartosc 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad.
 *
 */

friend bool operator == (TablicaLiczb Tab1, TablicaLiczb Tab2);

/*!
 *
 * \brief Definicja funkcji wykonujacej operacje polaczenia dwoch kontenerow
 *
 * \param[in] Tab1 - Kontener tablicy elementow.
 *
 * \param[in] Tab2 - Kontener tablicy elementow.
 *
 * \return Zwraca kontener Tab1 bedacy polaczeniem dwoch kontenerow.
 *
 */


friend TablicaLiczb dodaj_elementy(TablicaLiczb Tab1, TablicaLiczb Tab2);

/*!
 *
 * \brief Definicja  przeciazenia operatora '+' wykonujacego operacje polaczenia dwoch kontenerow
 *
 * \param[in] Tab2 - Kontener tablicy elementow.
 *
 * \return Zwraca kontener tablicy bedacy polaczeniem z kontenerem Tab2.
 *
 */

TablicaLiczb operator + (TablicaLiczb Tab2);

/*!
 *
 * \brief Definicja przeciazenia operatora '=' wykonujacego przypisanie kontenerowi elementow z kontenera Tab2
 *
 * \param[in] Tab2 - Kontener tablicy elementow.
 *
 * \return Zwraca kontener tablicy zawierajacy elementy Tab2.
 *
 */

TablicaLiczb operator = (TablicaLiczb Tab2);






};


#endif
