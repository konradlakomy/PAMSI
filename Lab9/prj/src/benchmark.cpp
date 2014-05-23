#include "benchmark.hh"
#include "graph.hh"


using namespace std;

/*!
 * \file
 * \brief Modul odpowiedzialny za pomiar czasu przeszukiwania.
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

void SearchTime() 
{
	Graph Graph1;
	srand(time(0));
	struct timespec time1, time2;
	Graph1.Load("dane/graph1.txt");

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
	Graph1.A_Star('C','E');
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "SEARCH TIME: " <<  (double)diff(time1, time2).tv_nsec/1000000 << " ms" << endl << endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
	Graph1.DFS('C');
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "SEARCH TIME: " <<  (double)diff(time1, time2).tv_nsec/1000000 << " ms" << endl << endl;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1); 
	Graph1.BFS('C');
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout << "SEARCH TIME: " << (double)diff(time1, time2).tv_nsec/1000000 << " ms" << endl << endl;


}
