#include "benchmark.hh"
#include "list.hh"
#include "bst.hh"
#include "hash.hh"
#include "list.cpp"
#include "hash.cpp"
#include "bst.cpp"
#include "main.hh"


using namespace std;

/*!
 * \file
 * \brief Modul odpowiedzialny za pomiar czasu dostepu.
 *
 * Plik zawiera opisy funkcji odpowiedzialnych za obliczanie czasu
 * wykonywania sie kazdego z algorytmow.
 */

string MakeKey(const int length) {
   	string s="";
	static const char tmp[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    	for (int i = 0; i < length; ++i) {
        	s += tmp[rand() % (sizeof(tmp) - 1)];
    	}
	return s;
}

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

void AccessTime() 
{

	struct timespec time1, time2;
	AssocArray1 <int> arr1;
	//AssocArray2<int> *arr2 = new AssocArray2<int>();
	//AssocArray3 <int> arr3;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
	for(int i=0; i<10; i++) 
		arr1.AddItem(MakeKey(10) , rand());
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << endl << "ACCESS TIME: " <<  (double)diff(time1, time2).tv_nsec/1000000000 << " \u00B5" << "s" << endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
	arr1.GetValue("J4ogHFZQxw");
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << endl << "ACCESS TIME: " <<  (double)diff(time1, time2).tv_nsec/1000000000 << " \u00B5" << "s" << endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
	arr1.DelItem("J4ogHFZQxw");
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << endl << "ACCESS TIME: " <<  (double)diff(time1, time2).tv_nsec/1000000000 << " \u00B5" << "s" << endl;





}
