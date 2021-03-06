#ifndef STACKK_HH
#define STACKK_HH
#include "main.hh"


/*!
 * \brief Modeluje pojecie stosu i metod z nim zwiazanych.
 *
 *  Deklaracja klasy Stack_Version1 opisujacej 
 *  struture danych stosu zaimplementowanego w tablicy.
 */
class Stack_Version1 
{

	int *Tab;
	int Top, Size;
public:

/*!
 *
 * \brief Konstruktor obiektu klasy Stack_Version1
 *
 */
	Stack_Version1();

/*!
 *
 * \brief Destruktor obiektu klasy Stack_Version1
 *
 */
	~Stack_Version1();

/*!
 *
 * \brief Sprawdza czy stos jest pełny.
 *
 * \return Zwraca true gdy jest pełny, false gdy nie jest pełny.
 */
	bool IsFull();

/*!
 *
 * \brief Dodaje nowy element na stos.
 *
 * \param[in] Element - Wartosc ktora ma byc dodana na stos.
 */
	void Push(int Element);

/*!
 *
 * \brief Element na szczycie stosu.
 *
 * \return Zwraca wartosc elementu ktory znajduje sie na szczycie stosu.
 */
	int Peek();

/*!
 *
 * \brief Sprawdza czy stos jest pusty.
 *
 * \return Zwraca true gdy jest pusty, false gdy jest pełny.
 */
	bool IsEmpty();

/*!
 *
 * \brief Metoda wczytująca dane na stos z pliku.
 *
 * \param[in] FileName - Nazwa pliku z ktorego maja byc wczytane dane
 *
 * \return Zwraca 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad
 */
	int Load(string FileName);

/*!
 *
 * \brief Wyswietla elementy aktualnie znajdujace sie na stosie.
 *
 */
	void Print();

/*!
 *
 * \brief Usuwa element ze szczytu stosu.
 *
 * \return Zwraca wartosc elementu ktory jest sciagany ze stosu.
 */
	int Pop();

/*!
 *
 * \brief Ilosc elementow na stosie.
 *
 * \return Zwraca aktualna ilosc elementow na stosie.
 */
	int Sizee();

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
 * \brief Algorytm Sortowania szybkiego.
 *
 * \param[in] Start - Indeks poczatkowy
 *
 * \param[in] End - Indeks koncowy
 *
 */
	void QuickSort(int Start, int End);


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
 * \brief Modeluje pojecie stosu i metod z nim zwiazanych.
 *
 *  Deklaracja klasy Stack_Version1 opisujacej 
 *  struture danych stosu zaimplementowanego w tablicy.
 */
class Stack_Version2 
{
	int *Tab;
	int Top, Size;
public:

/*!
 *
 * \brief Konstruktor obiektu klasy Stack_Version2
 *
 */
	Stack_Version2();

/*!
 *
 * \brief Destruktor obiektu klasy Stack_Version2
 *
 */
	~Stack_Version2();
/*!
 *
 * \brief Sprawdza czy stos jest pełny.
 *
 * \return Zwraca true gdy jest pełny, false gdy nie jest pełny.
 */
	bool IsFull();

/*!
 *
 * \brief Dodaje nowy element na stos.
 *
 * \param[in] Element - Wartosc ktora ma byc dodana na stos.
 */
	void Push(int Element);

/*!
 *
 * \brief Element na szczycie stosu.
 *
 * \return Zwraca wartosc elementu ktory znajduje sie na szczycie stosu.
 */
	int Peek();

/*!
 *
 * \brief Sprawdza czy stos jest pusty.
 *
 * \return Zwraca true gdy jest pusty, false gdy jest pełny.
 */
	bool IsEmpty();

/*!
 *
 * \brief Metoda wczytująca dane na stos z pliku.
 *
 * \param[in] FileName - Nazwa pliku z ktorego maja byc wczytane dane
 *
 * \return Zwraca 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad
 */
	int Load(string FileName);

/*!
 *
 * \brief Wyswietla elementy aktualnie znajdujace sie na stosie.
 *
 */
	void Print();

/*!
 *
 * \brief Usuwa element ze szczytu stosu.
 *
 * \return Zwraca wartosc elementu ktory jest sciagany ze stosu.
 */
	int Pop();

/*!
 *
 * \brief Ilosc elementow na stosie.
 *
 * \return Zwraca aktualna ilosc elementow na stosie.
 */
	int Sizee();

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
 * \brief Algorytm Sortowania szybkiego.
 *
 * \param[in] Start - Indeks poczatkowy
 *
 * \param[in] End - Indeks koncowy
 *
 */
	void QuickSort(int Start, int End);

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
 * \brief Modeluje pojecie stosu i metod z nim zwiazanych.
 *
 *  Deklaracja klasy Stack_Version1 opisujacej 
 *  struture danych stosu zaimplementowanego w tablicy.
 */
class Stack_Version3 
{
/*!
 * \brief Modeluje pojecie węzła stosu.
 *
 *  Deklaracja struktury Node opisujacej 
 *  pojedynczy wezel listy przechowujacy elementy stosu.
 */
	typedef struct node {
		node *next;
		int data;
	} NODE;

	NODE *top;

public:

/*!
 *
 * \brief Konstruktor obiektu klasy Stack_Version3
 *
 */
	Stack_Version3();

/*!
 *
 * \brief Destruktor obiektu klasy Stack_Version3
 *
 */
	~Stack_Version3();

/*!
 *
 * \brief Dodaje nowy element na stos.
 *
 * \param[in] Element - Wartosc ktora ma byc dodana na stos.
 */
	void Push(int Element);

/*!
 *
 * \brief Usuwa element ze szczytu stosu.
 *
 * \return Zwraca wartosc elementu ktory jest sciagany ze stosu.
 */
	int Pop();

/*!
 *
 * \brief Sprawdza czy stos jest pusty.
 *
 * \return Zwraca true gdy jest pusty, false gdy jest pełny.
 */
	bool IsEmpty();

/*!
 *
 * \brief Element na szczycie stosu.
 *
 * \return Zwraca wartosc elementu ktory znajduje sie na szczycie stosu.
 */
	int Peek();

/*!
 *
 * \brief Metoda wczytująca dane na stos z pliku.
 *
 * \param[in] FileName - Nazwa pliku z ktorego maja byc wczytane dane
 *
 * \return Zwraca 0 gdy operacja przebiegla pomyslnie, 1 gdy wystapil blad
 */
	int Load(string FileName);

/*!
 *
 * \brief Wyswietla elementy aktualnie znajdujace sie na stosie.
 *
 */
	void Print();

/*!
 *
 * \brief Ilosc elementow na stosie.
 *
 * \return Zwraca aktualna ilosc elementow na stosie.
 */	
	int Size();

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
