#ifndef LCS_HH
#define LCS_HH
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za implementacje algorytmu NWP.
 *
 *  Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie operacji   
 *  niezbędnych do wyznaczenia najdłuższego wspólnego podciągu.
 */


using namespace std;


/*!
 * \brief Modeluje pojecie algorytmu NWP i metod z nim związanych.
 *
 *  Deklaracja klasy LongestCommonSubsequence opisujacej 
 *  opisującej algorytm wyszukiwania najdłuższego wspólnego podciągu.
 */
class LongestCommonSubsequence 
{
private:

int **L; 
string x;
string y;
string subseq;
int n;
int m;

public:

/*!
 * \brief Metoda wczytująca dwa ciągi z których będzie wyznaczany najdłuższy wspólny podciąg.
 * 
 * \param[in] sequence1 - ciąg pierwszy
 *
 * \param[in] sequence2 - ciąg drugi
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
void AddSequence(string sequence1, string sequence2);

/*!
 * \brief Metoda odpowiedzialna za tworzenie tablicy i wyznaczenie długości NWP.
 * 
 * \return Metoda zwraca długość NWP. 
 *
 */
int LCS();

/*!
 * \brief Metoda odpowiedzialna za wyświetlenie wczytanych ciągów.
 * 
 * \return Metoda nie zwraca żadnej wartości. 
 *
 */
void PrintLoadedSequence();

/*!
 * \brief Metoda odpowiedzialna za wyświetlenie obliczonej tablicy NWP.
 * 
 * \return Metoda nie zwraca żadnej wartości. 
 *
 */
void PrintTable();

/*!
 * \brief Metoda odpowiedzialna za wyświetlenie wyznaczonego NWP.
 * 
 * \return Metoda nie zwraca żadnej wartości. 
 *
 */
void PrintSubsequence();
};
#endif 
