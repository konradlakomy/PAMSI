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
	void Stack(int Size);
	bool IsFull();
	void Push(int Element);
	int Peek();
	int Load(string FileName);
	void Print();
	void Pop();
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
	void Stack(int Size);
	bool IsFull();
	int Peek();
	void Push(int Element);
	int Load(string FileName);
	void Print();
	void Pop();
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
	void Push(int Element);
	int Pop();
	bool IsEmpty();
	int Peek();
	int Load(string FileName);
	void Print();	

};


#endif
