#include "Queue.hh"

/*!
 * \file
 * \brief Modul odpowiedzialny za operacje na kolejce.
 *
 *  Plik zawiera opisy metod odpowiedzialnych za wykonywanie operacji na strukturze 
 *  danych kolejki w wersji tablicowej i listowej.
 */

Queue_Version1::Queue_Version1()
{
	front = -1; 
	rear = -1;
	Tab = new int[MAX_SIZE];
}

Queue_Version1::~Queue_Version1()
{
	delete [] Tab;
}

bool Queue_Version1::IsEmpty()
{
	return (front == -1 && rear == -1); 
}

bool Queue_Version1::IsFull()
{
	return (rear+1)%MAX_SIZE == front ? true : false;
}

void Queue_Version1::Enqueue(int x)
{
	if(IsFull())
	{
		cout<<"Error: Queue_Version1 is Full\n";
		return;
	}
	if (IsEmpty())
	{ 
		front = rear = 0; 
	}
	else
	{
		rear = (rear+1)%MAX_SIZE;
	}
	Tab[rear] = x;
}

void Queue_Version1::Dequeue()
{
	if(IsEmpty())
	{
		cout<<"Error: Queue_Version1 is Empty\n";
		return;
	}
	else if(front == rear ) 
	{
		rear = front = -1;
	}
	else
	{
		front = (front+1)%MAX_SIZE;
	}
}

int Queue_Version1::Front()
{
	if(front == -1)
	{
		cout<<"Error: cannot return front from empty Queue_Version1\n";
		return -1; 
	}
	return Tab[front];
}

void Queue_Version1::Print()
{ 
	int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
	for(int i = 0; i <count; i++)
	{
		int index = (front+i) % MAX_SIZE; 
		cout << Tab[index] << " ";
	}
cout << endl;
}

int Queue_Version1::Load(string FileName) 
{
	int ElementCount;	
	int x;
	ifstream StrmWe;
	StrmWe.open(FileName.c_str());
	if(!StrmWe.is_open()) 
	{
		cerr << "!!! File cannot be opened" << endl; 
		return 1;
	}
	StrmWe >> ElementCount;
	if (StrmWe.fail()) 
	{
	StrmWe.clear();
	StrmWe.ignore(numeric_limits<int>::max( ),'\n');
	} 
	while(!StrmWe.eof()) 
	{
		StrmWe>>x;
		if (StrmWe.fail()) 
		{
			StrmWe.clear();
			StrmWe.ignore(numeric_limits<int>::max( ),'\n');
		} 
		else 
		{ 
			Enqueue( x );
		}
	}
	StrmWe.close();
	return 0; 
}

/*****************************************************/

Queue_Version2::Queue_Version2()
{
	head = NULL;
}

Queue_Version2::~Queue_Version2()
{
	if(head == NULL) return;
	NODE *cur = head;
	while(cur) 
	{
		Node *ptr = cur;
		cur = cur->next;
		delete ptr;
	}
}

void Queue_Version2::Enqueue(int Element)
{
	if(head == NULL) 
	{
		head = new NODE;
		head->data = Element;
		head->next = NULL;
		return;
	}
	NODE *cur = head;
	while(cur) 
	{
		if(cur->next == NULL) 
		{
			NODE *ptr = new NODE;
			ptr->data = Element;
			ptr->next = NULL;
			cur->next = ptr;
			return;
		}
		cur = cur->next;
	}
}

void Queue_Version2::Print()
{
	if(head==NULL) return;
	Node *cur = head;
	while(cur) 
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int Queue_Version2::Dequeue()
{
	if(head == NULL) 
	{
		cout << "empty eStack!" << endl;
		return 0;
	}
	NODE *tmp = head;
	int value = head->data;
	if(head->next) 
	{
		head = head->next;
	}
	else 
	{
		delete tmp;
		head = NULL;
	}
	return value;
}

bool Queue_Version2::IsEmpty()
{
return head == NULL ? true : false;
}

int Queue_Version2::Front()
{
	return head->data;
}


int Queue_Version2::Load(string FileName) 
{
	int ElementCount;	
	int x;
	ifstream StrmWe;
	StrmWe.open(FileName.c_str());
	if(!StrmWe.is_open()) 
	{
		cerr << "!!! File cannot be opened" << endl; 
		return 1;
	}
	StrmWe >> ElementCount;
	if (StrmWe.fail()) 
	{
	StrmWe.clear();
	StrmWe.ignore(numeric_limits<int>::max( ),'\n');
	} 
	while(!StrmWe.eof()) 
	{
		StrmWe>>x;
		if (StrmWe.fail()) 
		{
			StrmWe.clear();
			StrmWe.ignore(numeric_limits<int>::max( ),'\n');
		} 
		else 
		{ 
			Enqueue( x );
		}
	}
	StrmWe.close();
	return 0; 
}
