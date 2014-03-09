#include "Funkcje.hh"
#include "PomiarCzasu.hh"

/*!
 * \file
 * \brief Modul odpowiedzialny za pomiar czasu algorytmu.
 *
 * Plik zawiera opisy funkcji odpowiedzialnych za obliczanie czasu
 * wykonywania sie kazdego z algorytmow.
 */

timespec diff(timespec start, timespec end) {
    timespec temp;
    if((end.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;    
    }   
    return temp;
}



void PomiarCzasu(string NazwaPliku1, string NazwaPliku2) {
TablicaLiczb Tab1, Tab2;
struct timespec time1, time2;


cout << setw(30) << left;
cout << "FUNKCJA" << "CZAS DZIALANIA" << endl;
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1.pomnoz();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "POMNOZ()" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1.zamien_elementy(3,4);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "ZAMIEN_ELEMENTY(i,j)" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1.odwroc_kolejnosc();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "ODWROC_KOLEJNOSC()" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1.dodaj_element(32);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "DODAJ_ELEMENT()" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
dodaj_elementy(Tab1,Tab2);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "DODAJ_ELEMENTY(tab1,tab2)" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
porownaj(Tab1,Tab2);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "POROWNAJ(tab1,tab2)" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1=Tab2;
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "OPERATOR '='"<< setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1==Tab2;
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "OPERATOR '=='" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
Tab1.wczytaj(NazwaPliku1.c_str());
Tab2.wczytaj(NazwaPliku2.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Tab1+Tab2;
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(30) << left;
cout << "OPERATOR '+'" << setw(7) << right << diff(time1, time2).tv_nsec << " ns" << endl;
Tab1.wyczysc();
Tab2.wyczysc();
/********************************************************************/
}


