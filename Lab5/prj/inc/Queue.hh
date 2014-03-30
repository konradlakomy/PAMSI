#ifndef QUEUE_HH
#define QUEUE_HH
#include "main.hh"

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za operacje na kolejce.
 *
 *  Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie operacji na strukturze 
 *  danych kolejki w wersji tablicowej i listowej.
 */



/*!
 * \brief Modeluje pojecie kolejki i metod z nia zwiazanych.
 *
 *  Deklaracja klasy Queue_Version1 opisujacej 
 *  struture danych kolejki zaimplementowanej w tablicy.
 */
class Queue_Version1
{
	int *Tab;
	int front, rear; 
public:

/*!
 *
 * \brief Konstruktor obiektu klasy Queue_Version1
 *
 */
	Queue_Version1();

/*!
 *
 * \brief Destruktor obiektu klasy Queue_Version1
 *
 */
	~Queue_Version1();

/*!
 *
 * \brief Sprawdza czy kolejka jest pusta.
 *
 * \return Zwraca true gdy jest pusta, false gdy jest pełna.
 */
	bool IsEmpty();

/*!
 *
 * \brief Sprawdza czy kolejka jest pełna.
 *
 * \return Zwraca true gdy jest pełna, false gdy nie jest pełna.
 */
	bool IsFull();

/*!
 *
 * \brief Dodaje nowy element do kolejki.
 *
 * \param[in] x - Wartosc ktora ma byc dodana do kolejki.
 */
	void Enqueue(int x);

/*!
 *
 * \brief Usuwa element z kolejki.
 *
 * \return Zwraca wartosc elementu ktory jest usuwany z kolejki.
 */
	int Dequeue();

/*!
 *
 * \brief Element na poczatku kolejki.
 *
 * \return Zwraca wartosc elementu ktory znajduje sie na poczatku kolejki.
 */
	int Front();

/*!
 *
 * \brief Wyswietla elementy aktualnie znajdujace sie w kolejce.
 *
 */
	void Print();

/*!
 *
 * \brief Ilosc elementow w kolejce.
 *
 * \return Zwraca aktualna ilosc elementow znajdujaca sie w kolejce.
 */
	int Size();

/*!
 *
 * \brief Metoda wczytująca dane do kolejki z pliku.
 *
 * \param[in] FileName - Nazwa pliku z ktorego maja byc wczytane dane
 *
 * \return Zwraca 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad
 */
	int Load(string FileName);

/*!
 *
 * \brief Metoda losujaca elementy tablicy.
 *
 * param[in] Value - Liczba elementow ktora ma byc wylosowana
 *
 */

	void Random(int Value);

/*!
 *
 * \brief Metoda wypelniajaca tablice ciagiem liczb od 1,2,3...
 *
 * param[in] Value - Liczba elementow ktora ma zawierac tablica
 *
 */

	void Fill(int Value);

/*!
 *
 * \brief Funkcja scalajaca tablice.
 *
 * \param[in] Start - Indeks poczatkowy
 *
 * \param[in] End - Indeks koncowy
 *
 */
	void Merge(int Start, int End);

/*!
 *
 * \brief Algorytm sortowania przez scalanie.
 *
 * \param[in] Start - Indeks poczatkowy
 *
 * \param[in] End - Indeks koncowy
 *
 */
	void MergeSort(int Start, int End);

/*!
 *
 * \brief Algorytm sortowania szybkiego, z stałym elementem pivot.
 *
 * \param[in] Start - Indeks poczatkowy
 *
 * \param[in] End - Indeks koncowy
 *
 */
	void QuickSort1(int Start, int End);

/*!
 *
 * \brief Algorytm sortowania szybkiego, z losowym elementem pivot.
 *
 * \param[in] Start - Indeks poczatkowy
 *
 * \param[in] End - Indeks koncowy
 *
 */

	void QuickSort2(int Start, int End);

/*!
 *
 * \brief Funkcja budujaca kopiec.
 *
 * \param[in] n - Liczba elementow
 *
 */
	void Built(int n);

/*!
 *
 * \brief Algorytm sortowania przez kopcowanie.
 *
 * \param[in] n - Liczba elementow
 *
 */
	void Heap(int n);
};

/*!
 * \brief Modeluje pojecie kolejki i metod z nia zwiazanych.
 *
 *  Deklaracja klasy Queue_Version2 opisujacej 
 *  struture danych kolejki zaimplementowanej w liscie.
 */
class Queue_Version2
{

/*!
 * \brief Modeluje pojecie węzła kolejki.
 *
 *  Deklaracja struktury Node opisujacej 
 *  pojedynczy wezel listy przechowujacy elementy kolejki.
 */
	typedef struct Node {
		Node *next;
		int data;
	} NODE;
	NODE* head;
public:

/*!
 *
 * \brief Konstruktor obiektu klasy Queue_Version2
 *
 */
	Queue_Version2();

/*!
 *
 * \brief Destruktor obiektu klasy Queue_Version2
 *
 */
	~Queue_Version2();

/*!
 *
 * \brief Dodaje nowy element do kolejki.
 *
 * \param[in] Element - Wartosc ktora ma byc dodana do kolejki.
 */
	void Enqueue(int Element);

/*!
 *
 * \brief Sprawdza czy kolejka jest pusta.
 *
 * \return Zwraca true gdy jest pusta, false gdy jest pełna.
 */
	bool IsEmpty();

/*!
 *
 * \brief Ilosc elementow w kolejce.
 *
 * \return Zwraca aktualna ilosc elementow znajdujaca sie w kolejce.
 */
	int Size();

/*!
 *
 * \brief Usuwa element z kolejki.
 *
 * \return Zwraca wartosc elementu ktory jest usuwany z kolejki.
 */
	int Dequeue();

/*!
 *
 * \brief Wyswietla elementy aktualnie znajdujace sie w kolejce.
 *
 */
	void Print();

/*!
 *
 * \brief Element na poczatku kolejki.
 *
 * \return Zwraca wartosc elementu ktory znajduje sie na poczatku kolejki.
 */
	int Front();

/*!
 *
 * \brief Metoda wczytująca dane do kolejki z pliku.
 *
 * \param[in] FileName - Nazwa pliku z ktorego maja byc wczytane dane
 *
 * \return Zwraca 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad
 */
	int Load(string FileName);

/*!
 *
 * \brief Funkcja scalajaca kolejki.
 *
 * \param[in] &One - Referencja na adres pierwszej kolejki
 *
 * \param[in] &Two - Referencja na adres drugiej kolejki
 *
 */
	void Merge(Queue_Version2 &One, Queue_Version2 &Two);

/*!
 *
 * \brief Algorytm sortowania przez scalanie.
 *
 */
	void MergeSort();

/*!
 *
 * \brief Algorytm sortowania szybkiego.
 *
 */
	void QuickSort();
	

};
#endif
