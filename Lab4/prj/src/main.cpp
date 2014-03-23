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
BenchmarkSort("dane/10.csv");
cout << endl << "NUMBER OF ELEMENTS: 100" << endl << endl;
BenchmarkSort("dane/100.csv");
cout << endl << "NUMBER OF ELEMENTS: 1000" << endl << endl;
BenchmarkSort("dane/1000.csv");

return 0;

}
