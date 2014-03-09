#include "Funkcje.hh"
#include "PomiarCzasu.hh"

/*!
 * \file
 * \brief Modul glowny programu.
 *
 *  Plik zawiera opis funkcji main programu.
 */


int main() {

TablicaLiczb Tab1, Tab2;

cout << setw(30) << right << "LICZBA ELEMENTOW 10" << endl << endl;
PomiarCzasu("dane/10x1.csv" , "dane/10x2.csv");
cout << endl << endl;

cout << setw(30) << right << "LICZBA ELEMENTOW 100" << endl << endl;
PomiarCzasu("dane/100x1.csv" , "dane/100x2.csv");
cout << endl << endl;

cout << setw(30) << right << "LICZBA ELEMENTOW 1000" << endl << endl;
PomiarCzasu("dane/1000x1.csv" , "dane/1000x2.csv");
cout << endl << endl;

return 0;

}
