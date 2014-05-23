#ifndef GRAPH_HH
#define GRAPH_HH
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define INF 5000
#define CONST 65


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

/*!
 * \brief Struktura tworzaca wierzchołek grafu.
 *
 *  Struktura sluzy do przechowywania informacji na temat wierzcholka grafu.
 *   
 */
	typedef struct _node 
	{
		int nodeNo;
		int posX;
		int posY;
		int g;
		int h;
		char cameFrom;
		bool open;
		bool closed;
	} node;
	node graph[MaxVertexAmount];
	int Vertex;
	int AdjacencyMatrix[MaxVertexAmount][MaxVertexAmount];


public:
/*
 * \brief Konstruktor tworzacy tablice asocjacyjna.
 *
 */
Graph();

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
 * \brief Metoda odpowiedzialna za wyświetlanie tablicy sąsiedztwa.
 * 
 * \return Metoda nie zwraca żadnej wartości. 
 *
 */
void ShowMatrix();

/*!
 * \brief Metoda odpowiedzialna za wyświetlanie wierzchołków które są kolejno sprawdzane.
 * 
 * \return Metoda nie zwraca żadnej wartości. 
 *
 */
void PrintNodes();

/*!
 * \brief Metoda wyznaczajaca odleglosc typu manhattan miedzy dwoma wierzcholkami
 * 
 * \param[in] from - wierzcholek poczatkowy
 *
 * \param[in] to - wierzcholek docelowy
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
int Manhattan(node from, node to);

/*!
 * \brief Metoda sortujaca liste wierzcholkow ktore pozostaly do przeszukania
 * 
 * \param[in] openList - Lista przechowujaca wiercholki do przeszukania
 *
 * \param[in] size - rozmiar listy
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
void SortNodesByF(vector<char> &openList, int size);

/*!
 * \brief Metoda pozwalajaca wyswietlajaca droge miedzy dwoma wierzcholkami
 * 
 * \param[in] closedList - Lista przechowujaca droge miedzy wierzcholkami 
 *
 * \param[in] nodeNo - Wierzchołek docelowy.
 *
 * \return Metoda zwraca wartość 0 jesli droga została wyznaczona.
 *
 */
int PrintResult(stack<char> closedList, char nodeNo);

/*!
 * \brief Metoda pozwalajaca na wyznaczenie drogi miedzy dwoma wierzcholkami
 * 
 * \param[in] fromNode - Wierzchołek startowy  
 *
 * \param[in] toNode - Wierzchołek docelowy.
 *
 * \return Metoda zwraca wartość 0 jesli droga została wyznaczona.
 *
 */
int A_Star(char fromNode, char toNode);

/*!
 * \brief Metoda pozwalajaca na przeszukiwanie grafu w głąb.
 * 
 * \param[in] V - Wierzchołek od którego ma sie zacząć przeszukiwanie.  
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
void DFS(char V);

/*!
 * \brief Metoda pozwalajaca na przeszukiwanie grafu wszerz.
 * 
 * \param[in] V - Wierzchołek od którego ma sie zacząć przeszukiwanie.  
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
void BFS(char V);

/*!
 * \brief Metoda pozwalajaca na dodawanie nowej krawędzi grafu.
 * 
 * \param[in] V1 - Wierzchołek nr1.  
 *
 * \param[in] V2 - Wierzchołek nr2.
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
void AddEdge(char V1, char V2);

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
bool IsEdge(char V1, char V2);

/*!
 * \brief Metoda pozwalajaca na wyświetlenie wierzchołków które są połączone z wierzchołkiem V.
 * 
 * \param[in] V - Wierzchołek.  
 *
 * \return Metoda nie zwraca żadnej wartości.
 *
 */
void Neighbourhood(char V);
};
#endif 
