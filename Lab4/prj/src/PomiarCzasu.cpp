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



void BenchmarkLoad(string FileName) {
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


void BenchmarkSort (string FileName) 
{
	Stack_Version1 S11, S12;
	Stack_Version2 S21, S22;
	Stack_Version3 S31, S32;
	Queue_Version1 Q11, Q12;
	Queue_Version2 Q21, Q22; 
	struct timespec time1, time2;

cout << setw(25) << "FUNCTION" << setw(25) << "SORTTIME" << endl << endl;

S11.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S11.QuickSort(0,S11.Sizee());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "QUICKSORT OF STACK VERSION 1" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

S12.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S12.MergeSort(0,S12.Sizee());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "MERGESORT OF STACK VERSION 1" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

S21.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S21.QuickSort(0,S21.Sizee());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "QUICKSORT OF STACK VERSION 2" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

S22.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S22.MergeSort(0,S22.Sizee());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "MERGESORT OF STACK VERSION 2" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

S31.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S31.QuickSort();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "QUICKSORT OF STACK VERSION 3" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

S32.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
S32.MergeSort();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "MERGESORT OF STACK VERSION 3" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

Q11.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Q11.QuickSort(0,Q11.Size());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "QUICKSORT OF QUEUE VERSION 1" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

Q12.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Q12.MergeSort(0,Q12.Size());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "MERGESORT OF QUEUE VERSION 1" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

Q21.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Q21.QuickSort();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "QUICKSORT OF QUEUE VERSION 2" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;

Q22.Load(FileName.c_str());
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
Q22.MergeSort();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
cout << setw(40) << left;
cout << "MERGESORT OF QUEUE VERSION 2" << setw(7) << right << diff(time1, time2).tv_nsec/1000 << " \u00B5" << "s" << endl;


}
