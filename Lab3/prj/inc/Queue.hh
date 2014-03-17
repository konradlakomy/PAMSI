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
	bool IsEmpty();
	bool IsFull();
	void Enqueue(int x);
	void Dequeue();
	int Front();
	void Print();
	int Load(string FileName);
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
	void Enqueue(int Element);
	bool IsEmpty();
	int Dequeue();
	void Print();
	int Front();
	int Load(string FileName);

};
#endif
