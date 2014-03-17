#include "PomiarCzasu.hh"
#include "Stackk.hh"
#include "Queue.hh"
#include "main.hh"

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



void PomiarCzasu(string FileName) {
Stack_Version1 S1;
Stack_Version2 S2;
Stack_Version3 S3;
Queue_Version1 Q1;
Queue_Version2 Q2; 
struct timespec time1, time2;



cout << setw(25) << "FUNCTION" << setw(25) << "WORKTIME" << endl << endl;

clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S1.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "ARRAY IMPLEMENTATION OF STACK VERSION 1" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S2.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "ARRAY IMPLEMENTATION OF STACK VERSION 2" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S3.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "LIST IMPLEMENTATION OF STACK" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Q1.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "ARRAY IMPLEMENTATION OF QUEUE" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Q2.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "LIST IMPLEMENTATION OF QUEUE" << setw(7) << right << (diff(time1, time2).tv_nsec)/1000 << " \u00B5" << "s" << endl;



}

