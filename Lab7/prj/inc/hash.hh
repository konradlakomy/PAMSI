#ifndef HASH_HH
#define HASH_HH

#include "main.hh"

static const int tableSize = 100;

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za za implementacje tablicy asocjacyjnej na strukturze tablicy haszujacej.
 *
 *  Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie operacji na  
 *  tablicy asocjacyjnej.
 */


/*!
 * \brief Modeluje pojecie tablicy asocjacyjnej i metod z nia zwiazanych.
 *
 *  Deklaracja klasy AssocArray3 opisujacej 
 *  struture danych tablicy asocjacyjnej zaimplementowanej w tablicy haszującej.
 */
template <class T>
class AssocArray3
{

private:

/*!
 * \brief Struktura tworzaca tablice asocjacyjna.
 *
 *  Struktura sluzy do przechowywania elementow tablicy asocjacyjnej tj. 
 *  klucza, przypisanej do niego wartosci oraz wskaźniku na element następny. 
 */
	struct item 
	{
		string name;
		T data;
		item* next;
	};

item* HashTable[tableSize];

public:

/*
 * \brief Konstruktor tworzacy tablice asocjacyjna.
 *
 */
	AssocArray3();

/*!
 * \brief Metoda odpowiedzialna za haszowanie elementów tablicy.
 * 
 * \param[in] key - klucz tablicy.  
 *
 * \return Zwraca indeks pod ktorym zostanie zapisana wartosc. 
 *
 */
	int Hash(string key);

/*!
 * \brief Metoda odpowiedzialna za zliczanie elementow pod danym indeksem.
 * 
 * \param[in] index - indeks tablicy.  
 *
 * \return Zwraca liczbe oznaczajaca ilosc elementow pod danym indeksem. 
 *
 */
	int NumberOfItemsInIndex(int index);

/*!
 * \brief Metoda pozwalajaca na sprawdzenie czy tablica jest pusta
 * 
 * \return Zwraca wartosc logiczna true jesli jest pusta lub false jesli zawiera elementy.
 *
 */
	bool IsEmpty();

/*!
 * \brief Metoda pozwalajaca na dodawanie nowego elementu do tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \param[in] data - wartosc w tablicy.
 *
 * \return Zwraca wartosc logiczna true jesli element zostal dodany.
 *
 */
	bool AddItem(string name, T data);

/*!
 * \brief Metoda pozwalajaca na wyswietlenie elementow tablicy.
 * 
 * \return Zwraca wartosc logiczna false jesli jest pusta lub true jesli zawiera elementy.
 *
 */
	bool PrintTable();

/*!
 * \brief Metoda pozwalajaca wyszukac element w tablicy na podstawie klucza.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli klucz zostal odnaleziony lub false gdy nie znaleziono
 *
 */
	bool GetValue(string name);

/*!
 * \brief Metoda pozwalajaca wyszukac klucz w tablicy na podstawie podanej wartosci.
 * 
 * \param[in] data - wartosc w tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli klucz zostal odnaleziony lub false gdy nie znaleziono
 *
 */
	bool FindKey(T data);

/*!
 * \brief Metoda pozwalajaca na usuwanie elementu z tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli element zostal usuniety lub false jesli nie zostal odnaleziony.
 *
 */
	bool RemoveItem(string name);

/*!
 * \brief Metoda pozwalajaca na zmiane wartosci w tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \param[in] data - wartosc w tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli element zostal zamieniony lub false jesli nie zostal odnaleziony.
 *
 */
	bool ChangeValue(string name, T data);



};

#endif
