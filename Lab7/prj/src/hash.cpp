#include "hash.hh"

/*!
 * \file
 * \brief Modul odpowiedzialny za implementacje tablicy asocjacyjnej na tablicy haszującej.
 *
 *  Plik zawiera opisy metod odpowiedzialnych za wykonywanie operacji na 
 *  tablicy asocjacyjnej.
 */

template <class T>
AssocArray3<T>::AssocArray3()
{
	for(int i=0; i<tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->data = T(NULL);		
		HashTable[i]->next = NULL;
	}
}


template <class T>
bool AssocArray3<T>::IsEmpty()
{
	int val=0;
	for(int i=0; i<tableSize; i++)
	{
		if(HashTable[i]->name != "empty") val=1;

	}
	if(val == 1) return false;
	else return true;
}

template <class T>
bool AssocArray3<T>::AddItem(string name, T data)
{
	if(!ChangeValue(name, data)) 
	{
		int index=0;
		index = Hash(name);

		if(HashTable[index]->name == "empty")
		{
			HashTable[index]->name = name;
			HashTable[index]->data = data;	
		}
	
		else
		{
			item* Ptr = HashTable[index];
			item* n = new item;
			n->name = name;
			n->data = data;
			n->next = NULL;
			while(Ptr->next != NULL)
			{
				Ptr = Ptr->next;
			}
			Ptr->next = n;
		}
	}
	return true;
}

template <class T>
int AssocArray3<T>::NumberOfItemsInIndex(int index)
{
	int count = 0;
	
	if(HashTable[index]->name == "empty")
	{

		return count;
	}
	
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while(Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

template <class T>
bool AssocArray3<T>::PrintTable()
{
	if(!IsEmpty()) 
	{
	cout << endl << setw(20) << left << "KEY" << setw(20) << "VALUE" << endl << endl;
	for(int i=0; i<tableSize; i++)
	{
		item* Ptr = HashTable[i];
		while(Ptr != NULL)
		{
			cout << setw(20) << left << Ptr->name << setw(20) << Ptr->data << endl;
			Ptr = Ptr->next;
		}
		cout << endl;
	}
	return true;
	}
	else
	{
		cout << "Tablica jest pusta!!!" << endl;
		return false;
	}
}

template <class T>
int AssocArray3<T>::Hash(string key)
{
	long int hash=0;
	int index;
	
	for(unsigned int i=0; i<key.length(); i++)
	{
		hash = (hash + (int)key[i])*12;	
	}
	
	index = hash % tableSize;

	return index;
}

template <class T>
bool AssocArray3<T>::ChangeValue(string name, T data)
{
	int index = Hash(name);
	bool foundName = false;
	item* Ptr = HashTable[index];
	while(Ptr != NULL)
	{
		if(Ptr->name == name)
		{
			foundName = true;
			Ptr->data = data;
		}
		Ptr = Ptr->next;
	}
	if(foundName == true)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template <class T>
T AssocArray3<T>::GetValue(string name)
{
	int index = Hash(name);
	bool foundName = false;
	T data;
	item* Ptr = HashTable[index];
	cout << endl << setw(20) << left << "KEY" << setw(20) << "VALUE" << endl << endl;	
	while(Ptr != NULL)
	{
		if(Ptr->name == name)
		{
			foundName = true;
			data = Ptr->data;
		}
		Ptr = Ptr->next;
	}
	if(foundName == true)
	{
		cout << setw(20) << left << name << setw(20) << data << endl;
		return data;
	}
	else 
	{
		cout << "Nie znaleziono!!!" << endl;
		return T(NULL);
	}
}

template <class T>
bool AssocArray3<T>::FindKey(T data)
{
	bool foundName = false;
	string name;
	cout << endl << setw(20) << left << "KEY" << setw(20) << "VALUE" << endl << endl;
	for(int i=0; i<tableSize; i++)
	{
		item* Ptr = HashTable[i];
		while(Ptr != NULL)
		{
			if(Ptr->data == data)
			{
				foundName = true;
				name = Ptr->name;
			}
			Ptr = Ptr->next;
		}
	}
	if(foundName == true)
	{
		cout << setw(20) << left << name << setw(20) << data << endl;
		return true;	
	}
	else
	{
		cout << "Nie znaleziono!!!" << endl;
		return false;
	}
}

template <class T>
bool AssocArray3<T>::RemoveItem(string name)
{
	int index = Hash(name);
	item* delPtr;
	item* P1;
	item* P2;

	if(HashTable[index]->name == "empty" && HashTable[index]->data == T(NULL))
	{
		cout << "Podany klucz nie istnieje!!!" << endl;
		return false; 
	}

	else if(HashTable[index]->name == "empty" && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->data = T(NULL);
		cout << "Usunieto element: " << name << endl;
		return true;
	}

	else if(HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		cout << "Usunieto element: " << name << endl;
		return true;

	}

	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while(P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}

		if(P1 == NULL)
		{
			cout << "Podany klucz nie istnieje!!!" << endl;
			return false;

			
		}
		
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;
			delete delPtr;
			cout << "Usunieto element: " << name << endl;
			return true;

		}
	}


}

