#ifndef BST_HH
#define BST_HH
#include "main.hh"
#include <string>
using namespace std;

/*!
 * \file
 * \brief Definicja modułu odpowiedzialnego za za implementacje tablicy asocjacyjnej na strukturze drzewa binarnego.
 *
 *  Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie operacji na  
 *  tablicy asocjacyjnej.
 */
 

/*!
 * \brief Modeluje pojecie węzła drzewa binarnego i metod z nim związanych
 *
 *  Deklaracja struktury Node opisujacej
 *  struture węzła budującego drzewo binarne.
 */
template <class T>
struct Node 
{
	string name;
	T data;
    	Node *left;
    	Node *right;
 

    	Node(string name, T val) 
	{
		this->name = name;
        	this->data = val;
    	}

 
    	Node(string name, T val, Node<T> left, Node<T> right) 
	{
		this->name = name;
        	this->data = val;
        	this->left = left;
        	this->right = right;
    	}
};

/*!
 * \brief Modeluje pojecie tablicy asocjacyjnej i metod z nia zwiazanych.
 *
 *  Deklaracja klasy AssocArray2 opisujacej 
 *  struture danych tablicy asocjacyjnej zaimplementowanej w drzewie binarnym.
 */

template <class T>
class AssocArray2 {
 
private:
    	Node<T> *root;
	
/*!
 * \brief Metoda pozwalajaca na dodawanie nowego elementu do drzewa.
 * 
 * \param[in] root - wskaznik na korzen drzewa
 *
 * \param[in] name - klucz.  
 *
 * \param[in] val - wartosc.
 *
 */
    	void AddValue(Node<T> *root, string name, T val) 
	{
        	if (root->name > name) 
		{
            		if (!root->left) 
			{
                		root->left = new Node<T>(name, val);
            		} 
			else 
			{
                		AddValue(root->left, name, val);
            		}
        	} 
		else 
		{
            		if (!root->right) 
			{
                		root->right = new Node<T>(name, val);
            		} 
			else 
			{
                		AddValue(root->right, name, val);
            		}
        	}
    	}


/*!
 * \brief Metoda pozwalajaca na usuwanie elementu z drzewa.
 * 
 * \param[in] parent - wskaznik na wezel wyzej.  
 *
 * \param[in] current - wskaznik na element aktualny.  
 *
 * \param[in] name - klucz.  
 *
 * \return Zwraca wartosc logiczna true jesli element zostal usuniety lub false jesli nie zostal odnaleziony.
 *
 */
    	bool DeleteValue(Node<T>* parent, Node<T>* current, string name) 
	{
        	if (!current) return false;
        	if (current->name == name) 
		{
            		if (current->left == NULL || current->right == NULL) 
			{
                		Node<T>* temp = current->left;
                		if (current->right) temp = current->right;
                		if (parent) 
				{
                    			if (parent->left == current) 
					{
                        			parent->left = temp;
                    			} 
					else 
					{
                        			parent->right = temp;
                    			}
                		} 
				else 
				{
                    			this->root = temp;
                		}
            		} 
			else 
			{
                		Node<T>* validSubs = current->right;
                		while (validSubs->left) 
				{
		                    	validSubs = validSubs->left;
                		}
                		string temp = current->name;
                		current->name = validSubs->name;
                		validSubs->name = temp;
                		return DeleteValue(current, current->right, temp);
            		}
            		delete current;
            		return true;
        	}
        	return DeleteValue(current, current->left, name) ||
               	DeleteValue(current, current->right, name);
    	}

/*!
 * \brief Metoda pozwalajaca na zmiane wartosci w drzewie.
 * 
 * \param[in] root - wskaznik na korzen drzewa.  
 *
 * \param[in] val - wartosc.  
 *
 */
	void ChangeValue(Node<T> *root, T val) 
	{
	root->data = val;
	}
	
/*!
 * \brief Metoda pozwalajaca na wyswietlenie elementow tablicy.
 * 
 * \param[in] root - wskaznik na korzen drzewa.  
 *
 */
    	void PrintTree(Node<T> *root) 
	{
        	if (!root) return;
        	PrintTree(root->left);
		cout << setw(20) << left << root->name << setw(20) << root->data << endl << endl;
       		PrintTree(root->right);
    	}

/*!
 * \brief Metoda zwracajaca wskaznik na zadany element w drzewie.
 * 
 * \param[in] root - wskaznik na korzen drzewa.  
 *
 * \param[in] name - klucz.  
 *
 * \return Zwraca adres pod ktorym znajduje sie wartosc podanego elementu
 *
 */
	Node<T> *Key(Node<T> *root, string name) 
	{
		while(root !=NULL && name != root->name) {
		if(name < root->name) root=root->left; else root=root->right;
		}
		return root;
	}

/*!
 * \brief Metoda pozwalajaca wyszukac klucz w drzewie na podstawie podanej wartosci.
 * 
 * \param[in] root - wskaznik na korzen drzewa.  
 *
 * \param[in] val - wartosc.  
 *
 * \return Zwraca wartosc logiczna true jesli klucz zostal odnaleziony lub false gdy nie znaleziono
 *
 */
	bool GetKey(Node<T> *root, T val ) 
	{
		if(!root) return false;
		if(val == root-> data)
		{ 
			cout << root->name << endl;
			return true;
		} 
		GetKey(root->left, val);
		GetKey(root->right, val);
	}


/*!
 * \brief Metoda pozwalajaca obliczyc ilosc wezlow w drzewie.
 * 
 * \param[in] root - wskaznik na korzen drzewa.   
 *
 * \return Zwraca ilosc wezlow w drzewie
 *
 */
    	int Nodes(Node<T> *root) 
	{
        	if (!root) return 0;
        	else return 1 + Nodes(root->left) + Nodes(root->right);
    	}
 
/*!
 * \brief Metoda pozwalajaca obliczyc wysokosc drzewa.
 * 
 * \param[in] root - wskaznik na korzen drzewa.   
 *
 * \return Zwraca wysokosc drzewa.
 *
 */
    	int Height(Node<T> *root) 
	{
	        if (!root) return 0;
	        else return 1 + max(Height(root->left), Height(root->right));
	}

/*!
 * \brief Metoda pozwalajaca na sprawdzenie czy drzewo jest puste
 * 
 * \param[in] root - wskaznik na korzen drzewa.   
 *
 * \return Zwraca wartosc logiczna true jesli jest pusta lub false jesli zawiera elementy.
 *
 */
	bool Empty(Node<T> *root)
	{
		if(!root) return true;
		else return false; 
	}

public:

/*!
 * \brief Metoda pozwalajaca na dodawanie nowego elementu do tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \param[in] val - wartosc w tablicy.
 *
 * \return Zwraca wartosc logiczna true jesli element zostal dodany.
 *
 */
	bool Add(string name, T val);

/*!
 * \brief Metoda pozwalajaca na usuwanie elementu z tablicy.
 * 
 * \param[in] name - klucz tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli element zostal usuniety lub false jesli nie zostal odnaleziony.
 *
 */
	bool DelValue(string name); 

/*!
 * \brief Metoda pozwalajaca na wyswietlenie elementow tablicy.
 * 
 * \return Zwraca wartosc logiczna false jesli jest pusta lub true jesli zawiera elementy.
 *
 */
	bool Print();

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
 * \param[in] val - wartosc w tablicy.  
 *
 * \return Zwraca wartosc logiczna true jesli klucz zostal odnaleziony lub false gdy nie znaleziono
 *
 */
	bool FindKey(T val);

/*!
 * \brief Metoda pozwalajaca na sprawdzenie rozmiaru tablicy
 * 
 * \return Zwraca rozmiar tablicy
 *
 */
	void Size();

/*!
 * \brief Metoda pozwalajaca na sprawdzenie czy tablica jest pusta
 * 
 * \return Zwraca wartosc logiczna true jesli jest pusta lub false jesli zawiera elementy.
 *
 */
	bool IsEmpty();


};

#endif
