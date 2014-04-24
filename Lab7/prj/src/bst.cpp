#include "bst.hh"

/*!
 * \file
 * \brief Modul odpowiedzialny za implementacje tablicy asocjacyjnej na drzewie binarnym.
 *
 *  Plik zawiera opisy metod odpowiedzialnych za wykonywanie operacji na 
 *  tablicy asocjacyjnej.
 */

template <class T>
bool AssocArray2<T>::IsEmpty() 
{
	if(Empty(root) == true) return true;
	else return false;
}

template <class T>
bool AssocArray2<T>::Add(string name, T val) 
{
	if(Key(root, name)) 
	{
		ChangeValue(Key(root, name), val);
	}
	else 
	{
        	if (root) 
		{
            		this->AddValue(root, name, val);
        	} 
		else 
		{
            		root = new Node<T>(name, val);
        	}
	}
	return true;
}

template <class T>
bool AssocArray2<T>::DelValue(string name) 
{
	return this->DeleteValue(NULL, this->root, name);
}

template <class T> 
bool AssocArray2<T>::Print() 
{
	if(!IsEmpty()) {
	cout << endl << setw(20) << left << "KEY" << setw(20) << "VALUE" << endl << endl; 
        PrintTree(this->root); 
	cout << endl;
	return true;	
	}
	else 
	{
		return false;
	}
}

template <class T>
T AssocArray2<T>::GetValue(string name)
{	
	Node<T> *wsk;
	wsk= Key(root, name);
	cout << endl << setw(20) << left << "KEY" << setw(20) << "VALUE" << endl << endl; 
	if(wsk) 
	{	
		cout << setw(20) << left << wsk->name << setw(20) << wsk->data << endl;	
		return wsk->data;
	}
	else 
	{
		cout << "Podany klucz nie istnieje!!!" << endl;
		return false;
	}
}

template <class T>
bool AssocArray2<T>::FindKey(T val)
{
	if(GetKey(this->root, val)) return true;
	else return false;	
}

template <class T>
void AssocArray2<T>::Size()
{
	cout << "Nodes: " << Nodes(root) << endl;
	cout << "Height: " << Height(root) << endl;
}
