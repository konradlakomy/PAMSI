#include "Stackk.hh"

/*!
 * \file
 * \brief Modul odpowiedzialny za operacje na stosie.
 *
 *  Plik zawiera opisy metod odpowiedzialnych za wykonywanie operacji na strukturze 
 *  danych stosu w wersji tablicowej i listowej.
 */

Stack_Version1::Stack_Version1() 
{
	Top=-1;
	Size=1;
	Tab = new int[Size];
}

Stack_Version1::~Stack_Version1() 
{
	delete [] Tab;
}

void Stack_Version1::Stack(int Size) 
{
	int *tmp = new int[Size];
	for (int i=0; i<Size; i++) tmp[i]=Tab[i];
	delete [] Tab;
	Tab = tmp;
}

bool Stack_Version1::IsFull() 
{ 
	return (Top==(Size-1)) ? true : false;
} 

void Stack_Version1::Push(int Element) 
{
	if(IsFull()==1) 
	{
		int *tmp = new int[++Size];
		for (int i=0; i<Size; i++) tmp[i]=Tab[i];
		delete [] Tab;
		Tab = tmp;
	}
	Tab[++Top]=Element;
}

void Stack_Version1::Pop() 
{
	Size--;
	Top--;
	int *tmp = new int[Size];
	for (int i=0; i<Size; i++) tmp[i]=Tab[i];
	delete [] Tab;
	Tab = tmp;
}

int Stack_Version1::Peek()
{
	return Tab[Top];
}

void Stack_Version1::Print() 
{
	for(int i=Top; i>=0; i--) cout << Tab[i] << " ";
	cout << endl;
}

int Stack_Version1::Load(string FileName) 
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
			Push( x );
		}
	}
	StrmWe.close();
	return 0; 
}

/***************************************************************/

Stack_Version2::Stack_Version2() 
{
	Top=-1;
	Size=1;
	Tab = new int[Size];
}

Stack_Version2::~Stack_Version2() 
{
	delete [] Tab;
}

void Stack_Version2::Stack(int Size) 
{
	int *tmp = new int[Size];
	for (int i=0; i<Size; i++) tmp[i]=Tab[i];
	delete [] Tab;
	Tab = tmp;
}

bool Stack_Version2::IsFull() 
{ 
	return (Top==(Size-1)) ? true : false;
} 

int Stack_Version2::Peek()
{
	return Tab[Top];
}

void Stack_Version2::Push(int Element) 
{
	if(IsFull()==1) 
	{
		Size=Size*2;
		int *tmp = new int[Size];
		for (int i=0; i<Size; i++) tmp[i]=Tab[i];
		delete [] Tab;
		Tab = tmp;
	}
	Tab[++Top]=Element;
}

void Stack_Version2::Pop() 
{
	Top--;
	if((Top+1)*4<=Size) 
	{
		Size=Size/2;
		int *tmp = new int[Size];
		for (int i=0; i<Size; i++) tmp[i]=Tab[i];
		delete [] Tab;
		Tab = tmp;
	}
}

void Stack_Version2::Print() 
{
	for(int i=Top; i>=0; i--) cout << Tab[i] << " ";
	cout << endl;
}

int Stack_Version2::Load(string FileName) 
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
			Push( x );
		}
	}
	StrmWe.close();
	return 0; 
}

/*******************************************************************/

Stack_Version3::Stack_Version3()
{
	top = NULL;
}

Stack_Version3::~Stack_Version3()
{
	while(top) 
	{
		NODE *tmp = top;
		top = top->next;
		delete tmp;
	}
}

void Stack_Version3::Push(int Element) 
{
	NODE *ptr = new NODE;
	ptr->next = top;
	ptr->data = Element;
	top = ptr;
}

int Stack_Version3::Pop()
{
	NODE *tmp = top;
	int val = top->data;
	top = top->next;
	delete tmp;
	return val;
}

bool Stack_Version3::IsEmpty()
{
return top == NULL ? true : false;
}


int Stack_Version3::Peek()
{
	return top->data;
}

void Stack_Version3::Print()
{
	NODE *tmp = top;
	while(tmp) 
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int Stack_Version3::Load(string FileName) 
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
			Push( x );
		}
	}
	StrmWe.close();
	return 0; 
}



