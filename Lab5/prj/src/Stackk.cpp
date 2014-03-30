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

int Stack_Version1::Pop() 
{	int Value;
	Value=Tab[Top];
	Size--;
	Top--;
	int *tmp = new int[Size];
	for (int i=0; i<Size; i++) tmp[i]=Tab[i];
	delete [] Tab;
	Tab = tmp;
	return Value;
}

int Stack_Version1::Peek()
{
	return Tab[Top];
}

void Stack_Version1::Print() 
{
	if(!IsEmpty()) 
	{
	for(int i=Top; i>=0; i--) cout << Tab[i] << " ";
	cout << endl;
	}
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

bool Stack_Version1::IsEmpty()
{
	return (Top == -1 && Size == 0);
}


int Stack_Version1::Sizee() 
{
return Top+1;
}

void Stack_Version1::Random(int Value) {
	int Tmp;
	for(int i=0; i<Value; i++) 
	{
		Tmp =( rand() % Value ) + 1;
		Push(Tmp);
	}
}

void Stack_Version1::Merge(int Start, int End)
{
	int i, j, tmp;
	int *t = new int[End+1];
	int s=(Start+End)/2;
	for (i=Start; i<=End; i++) 
		t[i]=Tab[i];  
	i=Start; j=s+1; tmp=Start;                
	while (i<=s && j<=End) 
	{         
		if (t[i]<t[j])
			Tab[tmp++]=t[i++];
		else
			Tab[tmp++]=t[j++];
	}
	while (i<=s) 
		Tab[tmp++]=t[i++]; 
}

void Stack_Version1::MergeSort(int Start, int End)
{
	if (Start<End) 
	{
		int s=(Start+End)/2;
		MergeSort(Start, s);    
		MergeSort(s+1, End);   
		Merge(Start, End);   
	}
}


void Stack_Version1::QuickSort(int Start, int End)
{
	int i, j, Pivot, Tmp;
	i=(Start+End)/2;
	Pivot=Tab[i];	
	Tab[i]=Tab[End];
	for ( i = j = Start; i < End; i++)	
		if (Tab[i] < Pivot)
		{
			Tmp=Tab[i];
			Tab[i]=Tab[j];
			Tab[j]=Tmp;
			j++;
		}
		Tab[End] = Tab[j];
		Tab[j] = Pivot;
		if(Start < j-1)
			QuickSort(Start, j-1);
		if(j+1 < End)
			QuickSort(j+1, End);
}

void Stack_Version1::Built(int n)
{
	int i, j, k, x;
	for(i = 2; i <= n; i++)
	{
		j = i; k = j / 2;
		x = Tab[i-1];
		while((k > 0) && (Tab[k-1] < x))
		{
		  Tab[j-1] = Tab[k-1];
		  j = k; k = j / 2;
		}
		Tab[j-1] = x;
	}
}


void Stack_Version1::Heap(int n)
{
	int tmp;
	if (n>0)
	{
		tmp=Tab[n-1];
		Tab[n-1]=Tab[0];
		Tab[0]=tmp;
		n--;
		Built(n);
		Heap(n);
	}
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


bool Stack_Version2::IsFull() 
{ 
	return (Top==(Size-1)) ? true : false;
} 

bool Stack_Version2::IsEmpty() 
{
	return (Top==-1 && Size==1);
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

int Stack_Version2::Pop() 
{
	int Value=Tab[Top];
	Top--;
	if((Top+1)*4<=Size) 
	{
		Size=Size/2;
		int *tmp = new int[Size];
		for (int i=0; i<Size; i++) tmp[i]=Tab[i];
		delete [] Tab;
		Tab = tmp;
	}
	return Value;
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

int Stack_Version2::Sizee() 
{
return Top+1;
}

void Stack_Version2::Random(int Value) {
	int Tmp;
	for(int i=0; i<Value; i++) 
	{
		Tmp =( rand() % Value ) + 1;
		Push(Tmp);
	}
}

void Stack_Version2::Merge(int Start, int End)
{
	int i, j, tmp;
	int *t = new int[End+1];
	int s=(Start+End)/2;
	for (i=Start; i<=End; i++) 
		t[i]=Tab[i];  
	i=Start; j=s+1; tmp=Start;                
	while (i<=s && j<=End) 
	{         
		if (t[i]<t[j])
			Tab[tmp++]=t[i++];
		else
			Tab[tmp++]=t[j++];
	}
	while (i<=s) 
		Tab[tmp++]=t[i++]; 
}

void Stack_Version2::MergeSort(int Start, int End)
{
	if (Start<End) 
	{
		int s=(Start+End)/2;
		MergeSort(Start, s);    
		MergeSort(s+1, End);   
		Merge(Start, End);   
	}
}


void Stack_Version2::QuickSort(int Start, int End)
{
	int i, j, Pivot, Tmp;
	i=(Start+End)/2;
	Pivot=Tab[i];	
	Tab[i]=Tab[End];
	for ( i = j = Start; i < End; i++)	
		if (Tab[i] < Pivot)
		{
			Tmp=Tab[i];
			Tab[i]=Tab[j];
			Tab[j]=Tmp;
			j++;
		}
		Tab[End] = Tab[j];
		Tab[j] = Pivot;
		if(Start < j-1)
			QuickSort(Start, j-1);
		if(j+1 < End)
			QuickSort(j+1, End);
}

void Stack_Version2::Built(int n)
{
	int i, j, k, x;
	for(i = 2; i <= n; i++)
	{
		j = i; k = j / 2;
		x = Tab[i-1];
		while((k > 0) && (Tab[k-1] < x))
		{
		  Tab[j-1] = Tab[k-1];
		  j = k; k = j / 2;
		}
		Tab[j-1] = x;
	}
}


void Stack_Version2::Heap(int n)
{
	int tmp;
	if (n>0)
	{
		tmp=Tab[n-1];
		Tab[n-1]=Tab[0];
		Tab[0]=tmp;
		n--;
		Built(n);
		Heap(n);
	}
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

int Stack_Version3::Size() {
	int i=0;
	NODE *tmp=top;
	while(tmp) 
	{
		i++;
		tmp = tmp->next;
	}
return i;
}


void Stack_Version3::MergeSort() 
{
    	if (IsEmpty()) return;
    
    	Stack_Version3  StackLeft,
    	  		StackRight,
    			StackTmp;

    	while (!IsEmpty()) 
	{
        	StackLeft.Push(Pop());
        	if (!IsEmpty()) 
		
            		StackRight.Push(Pop());
        	
    	}


    	if (!StackLeft.IsEmpty() && !StackRight.IsEmpty()) 
	{
        	StackLeft.MergeSort();
        	StackRight.MergeSort();
    	}

    	while (!StackLeft.IsEmpty() || !StackRight.IsEmpty()) 
	{
        	if (StackLeft.IsEmpty()) 
		
            		StackTmp.Push(StackRight.Pop());
		
        	else if (StackRight.IsEmpty()) 

            		StackTmp.Push(StackLeft.Pop());

		else if (StackLeft.Peek()>StackRight.Peek()) 
            
			StackTmp.Push(StackLeft.Pop());
         	else 
            		StackTmp.Push(StackRight.Pop());
        
    	}

    	while (!StackTmp.IsEmpty()) 
        	
		Push(StackTmp.Pop());
    
}


void Stack_Version3::QuickSort() {
    	if (Size() <= 1) return;
    	int elem;
    	Stack_Version3 Pivot, 
		       Less, 
		       More, 
		       Tmp;

    	Pivot.Push(Pop());

    	while (!IsEmpty()) 
	{
        	elem = Pop();
        	if (elem < Pivot.Peek()) 
			Less.Push(elem);
        	else if (elem > Pivot.Peek()) 
			More.Push(elem);
        	else                          
			Pivot.Push(elem);
    	}

	if(!Less.IsEmpty() && !More.IsEmpty()) 
	{
    		Less.QuickSort();
    		More.QuickSort();
	}

    	while (!Less.IsEmpty())  
		Tmp.Push(Less.Pop());
    	while (!Pivot.IsEmpty()) 
		Tmp.Push(Pivot.Pop());
    	while (!More.IsEmpty())  
		Tmp.Push(More.Pop());
    	while (!Tmp.IsEmpty()) 
        	Push(Tmp.Pop());
    
}



