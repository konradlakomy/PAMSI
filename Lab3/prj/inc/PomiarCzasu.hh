#ifndef POMIARCZASU_HH
#define POMIARCZASU_HH
#include "main.hh"

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za pomiar czasu algorytmu.
 *
 * Plik zawiera deklaracje funkcji odpowiedzialnych za obliczanie czasu
 * wykonywania sie kazdego z algorytmow.
 */


/*!
 *
 * \brief Definicja funkcji obliczajacej roznice pomiedzy dwoma strukturami czasu.
 *
 * \param[in] start - moment rozpoczecia dzialania algorytmu
 *
 * \param[in] end - moment zakonczenia dzialania algorytmu
 *
 * \return Zwraca roznice pomiedzy dwoma strukturami czasu
 *
 */

timespec diff(timespec start, timespec end);

/*!
 *
 * \brief Definicja funkcji dokonujacej pomiaru czasu dzialania kazdego z algorytmow. 
 *
 * \param[in] FileName - plik zawierajacy zestaw danych do przetworzenia
 *
 * \return Funkcja nie zwraca zadnej wartosci. 
 *
 */

void PomiarCzasu(string FileName); 
#endif
