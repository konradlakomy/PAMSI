#include "graph.hh"

/*!
 * \file
 * \brief Modul glowny programu.
 *
 *  Plik zawiera opis funkcji main programu.
 */

int main()
{
	Graph Graph1;
	Graph1.Load("dane/graph1.txt");
	Graph1.Print();
	Graph1.DFS(0);
	Graph1.BFS(0);
	return 0;
}
