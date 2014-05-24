#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "main.hh"

using namespace std;

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za pomiar czasu dostepu.
 *
 * Plik zawiera deklaracje funkcji odpowiedzialnych za obliczanie czasu
 * po jakim zostaje odczytana wartosc z tablicy.
 */

string MakeKey(const int len);

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
 */

void AccessTime();

#endif
