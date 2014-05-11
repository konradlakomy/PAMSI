#ifndef GRAPH_HH
#define GRAPH_HH
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <stack>
#include <queue>

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za implementacje struktury grafu.
 *
 *  Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie operacji na  
 *  strukturze grafu.
 */

using namespace std;

static const int MaxVertexAmount = 100;


/*!
 * \brief Modeluje pojecie grafu i metod z nim zwiazanych.
 *
 *  Deklaracja klasy Graph opisujacej 
 *  struture danych grafu zaimplementowanej za pomocą macierzy sąsiedztwa.
 */
class Graph {
private:

	int **AdjacencyMatrix;
	int Vertex;
	int Edge;

public:
/*
 * \brief Konstruktor tworzacy tablice asocjacyjna.
 *
 */
	Graph();

/*!
 * \brief Metoda odpowiedzialna za wyświetlanie tablicy sąsiedztwa.
 * 
 * \return Metoda nie zwraca żadnej wartości. 
 *
 */

	void Print();

/*!
 * \brief Metoda pozwalajaca na dodawanie nowej krawędzi grafu.
 * 
 * \param[in] V1 - Wierzchołek nr1.  
 *
 * \param[in] V2 - Wierzchołek nr2.
 *
 * \param[in] C - Waga.
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
	void AddEdge(int V1, int V2, int C);

/*!
 * \brief Metoda pozwalajaca na usuwanie krawędzi z grafu.
 * 
 * \param[in] V1 - Wierzchołek nr1.  
 *
 * \param[in] V2 - Wierzchołek nr2.
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
	void DelEdge(int V1, int V2);

/*!
 * \brief Metoda pozwalajaca na sprawdzenie czy istnieje bezpośrednie połączenie między wierzchołkami.
 * 
 * \param[in] V1 - Wierzchołek nr1.  
 *
 * \param[in] V2 - Wierzchołek nr2.
 *
 * \return Metoda zwraca wartość true jeśli istnieje lub false jeśli nie istnieje połączenie.
 *
 */
	bool IsEdge(int V1, int V2);

/*!
 * \brief Metoda pozwalajaca na wyświetlenie wierzchołków które są połączone z wierzchołkiem V.
 * 
 * \param[in] V - Wierzchołek.  
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
	void Neighbourhood(int V);

/*!
 * \brief Metoda pozwalajaca na wczytanie grafu do programu
 * 
 * \param[in] NazwaPliku - Nazwa pliku który ma zostać wczytany 
 *
 * \return Metoda zwraca wartość 1 jeśli plik nie został odczytany lub 0 gdy został odczytany.
 *
 */
	int Load(string NazwaPliku);

/*!
 * \brief Metoda pozwalajaca na przeszukiwanie grafu w głąb.
 * 
 * \param[in] V1 - Wierzchołek od którego ma sie zacząć przeszukiwanie.  
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
	void DFS(int V1); 

/*!
 * \brief Metoda pozwalajaca na przeszukiwanie grafu wszerz.
 * 
 * \param[in] V1 - Wierzchołek od którego ma sie zacząć przeszukiwanie.  
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
	void BFS(int V1);

};

#endif
