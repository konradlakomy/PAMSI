#include "main.hh"
#include "PomiarCzasu.hh"
#include "Stackk.hh"
#include "Queue.hh"

/*!
 * \file
 * \brief Modul glowny programu.
 *
 *  Plik zawiera opis funkcji main programu.
 */


int main() {

cout << endl << "NUMBER OF ELEMENTS: 10" << endl << endl;
PomiarCzasu("dane/10x1.csv");

cout << endl << "NUMBER OF ELEMENTS: 100" << endl << endl;
PomiarCzasu("dane/100x1.csv");

cout << endl << "NUMBER OF ELEMENTS: 1000" << endl << endl;
PomiarCzasu("dane/1000x1.csv");

return 0;

}
