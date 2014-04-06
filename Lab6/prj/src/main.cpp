#include "array.hh"
#include "array.cpp"

/*!
 * \file
 * \brief Modul glowny programu.
 *
 *  Plik zawiera opis funkcji main programu.
 */

int main()
{
	AssocArray <int> arr;

//przykladowe uzycie programu.

	arr.AddItem("Lukasz" , 25);
	arr.AddItem("Mateusz" , 23);
	arr.AddItem("Monika" , 19);
	arr.AddItem("Laura" , 17);
	arr.AddItem("Ewa" , 18);
	arr.AddItem("Konrad" , 22);
	arr.AddItem("Tomek" , 35);
	arr.AddItem("Maciek" , 19);
	arr.Print();

	arr.AddItem("Ewa" , 23);
	arr.Print();

	arr.DelItem("Konrad");
	arr.Print();

	arr.GetValue("Laura");

	arr.FindKey(19);
return 0;
}
