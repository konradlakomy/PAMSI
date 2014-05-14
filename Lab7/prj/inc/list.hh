#ifndef LIST_HH
#define LIST_HH

#include "main.hh"

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za za implementacje tablicy asocjacyjnej na strukturze listy.
 *
 *  Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie operacji na  
 *  tablicy asocjacyjnej.
 */


/*!
 * \brief Modeluje pojecie tablicy asocjacyjnej i metod z nia zwiazanych.
 *
 *  Deklaracja klasy AssocArray1 opisujacej 
 *  struture danych tablicy asocjacyjnej zaimplementowanej w liście.
 */
template <class T>
	class AssocArray1
	{
		private:

/*!
 * \brief Struktura tworzaca tablice asocjacyjna.
 *
 *  Struktura sluzy do przechowywania elementow tablicy asocjacyjnej tj. 
 *  klucza oraz przypisanej do niego wartosci. 
 */
			typedef struct _Data
			{
				T data;
				string name;

			} Data ;
			
			list<Data> array;
		public:


/*!
 * \brief Struktura porownujaca klucze tablicy asocjacyjnej.
 *
 *  Struktura zawierajaca metody przeciazenia operatorow ().
 *  Sluza do porównywania kluczy, w celu wyszukania elementu. 
 */
			struct Compare 
			{

/*!
 * \brief Metoda odpowiedzialna za porownywanie elementów tablicy.
 * 
 * \param[in] a - obiekt struktury tablicy.
 *
 * \param[in] name - klucz tablicy.
 *
 * \return Zwraca wartosc logiczna true gdy nierownosc jest prawdziwa lub false gdy jest nie prawdziwa
 *
 */
				bool operator()(Data a, string name) const
				{
					return a.name < name;
				}

/*!
 * \brief Metoda odpowiedzialna za porownywanie elementów tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \param[in] a - obiekt struktury tablicy.
 *
 * \return Zwraca wartosc logiczna true gdy nierownosc jest prawdziwa lub false gdy jest nie prawdziwa
 *
 */
    				bool operator()(string name, Data a) const
    				{
					return name < a.name; 
				}
			};


/*!
 * \brief Iterator tablicy asocjacyjnej.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \return Ustawia iterator na kluczu name jesli zostanie znaleziony lub na koniec tablicy jesli nie zostanie odnaleziony.
 *
 */

			typename list<Data>::iterator Key(string name)
			{
				if(binary_search(array.begin(), array.end(), name, Compare())) 
				{
					typename list<Data>::iterator it=lower_bound(array.begin(), array.end(), name, Compare());
					return it;
				}
				else 
					return array.end();
			}


/*!
 * \brief Metoda pozwalajaca na sprawdzenie rozmiaru tablicy
 * 
 * \return Zwraca rozmiar tablicy
 *
 */
			long Size();

/*!
 * \brief Metoda pozwalajaca na sprawdzenie czy tablica jest pusta
 * 
 * \return Zwraca wartosc logiczna true jesli jest pusta lub false jesli zawiera elementy.
 *
 */
			bool IsEmpty();

/*!
 * \brief Metoda pozwalajaca na wyswietlenie elementow tablicy.
 * 
 * \return Zwraca wartosc logiczna false jesli jest pusta lub true jesli zawiera elementy.
 *
 */
			bool Print(); 

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
 * \brief Metoda pozwalajaca na usuwanie elementu z tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli element zostal usuniety lub false jesli nie zostal odnaleziony.
 *
 */

			bool DelItem(string name); 

/*!
 * \brief Metoda pozwalajaca wyszukac element w tablicy na podstawie klucza.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \return Zwraca wartosc znajdujaca sie pod tym kluczem
 *
 */

			T GetValue(string name);


/*!
 * \brief Metoda pozwalajaca wyszukac klucz w tablicy na podstawie podanej wartosci.
 * 
 * \param[in] data - wartosc w tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli klucz zostal odnaleziony lub false gdy nie znaleziono
 *
 */
			bool FindKey(T data);
	};
#endif
