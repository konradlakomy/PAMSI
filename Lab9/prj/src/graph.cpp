#include "graph.hh"

/*!
 * \file
 * \brief Opis modułu odpowiedzialnego za implementacje struktury grafu.
 *
 *  Plik zawiera opisy metod odpowiedzialnych za wykonywanie operacji na  
 *  strukturze grafu.
 */
	
Graph::Graph() 
{
	for(int i=0; i<MaxVertexAmount; i++) 
		for(int j=0; j<MaxVertexAmount; j++) 
			AdjacencyMatrix[i][j] = 0;
}

int Graph::Load(string NazwaPliku)
{
	int i = 0, j = 0, n=0;
	ifstream StrmWe;
	StrmWe.open(NazwaPliku.c_str());
	if(!StrmWe.is_open()) 
	{
		cerr << "!!! Plik nie zostal otwarty" << endl; 
		return 1;
	}
	StrmWe>>Vertex;
        while( StrmWe >> AdjacencyMatrix[i][j] ) {
        	if( ++j >= Vertex ) 
		{
            		j = 0;
            		i++;
		}
		n++;
		if( n > Vertex*Vertex - 1 ) break;
        	
	}
	for (i = 0; i < Vertex; i++)
	{
		StrmWe>>graph[i].posX;
	}
	for (i = 0; i < Vertex; i++)
	{
		StrmWe>>graph[i].posY;
	}

	StrmWe.close();

	for (int i = 0; i < Vertex; i++)
	{
		graph[i].nodeNo = i + CONST;
		graph[i].cameFrom=0;
		graph[i].open=0;
		graph[i].closed=0;
		graph[i].g=INF;
		graph[i].h=INF;
	}

	return 0;
}

void Graph::ShowMatrix() 
{
	cout << left << setw(4) << "V";
	for(int i=0; i<Vertex; i++) 
		cout << left << setw(3) << static_cast<char>(CONST+i);
	cout << endl;
	for(int i=0; i<Vertex; i++)
	{
		cout << left << setw(4) <<static_cast<char>(CONST+i);
		for(int j=0; j<Vertex; j++) 
		{
			cout << left << setw(3) << AdjacencyMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
    
}

void Graph::PrintNodes()
{
	cout << endl;
	for (int i = 0; i < Vertex; i++)
	{
		cout << endl << (char)graph[i].nodeNo << " (" << graph[i].posX << "," << graph[i].posY << ") " << setw(4) << graph[i].g << "+";
		cout << setw(4) << graph[i].h << "  open = " << graph[i].open << " closed = " << graph[i].closed;
	}
}

int Graph::Manhattan(node from, node to)
{
	int h;
	h = abs(to.posX - from.posX) + abs(to.posY - from.posY);
	return h;
}

void Graph::SortNodesByF(vector<char> &openList, int size)
{
	bool didChange = true;
	int i, f1, f0;
	char tempChar;
	while (didChange)
	{
		didChange = false;
		for (i = 0; i < size - 1; i++)
		{
			f1 = (graph[openList[i + 1] - CONST].h + graph[openList[i + 1] - CONST].g);
			f0 = (graph[openList[i] - CONST].h + graph[openList[i] - CONST].g);
			if (f1>f0)
			{
				tempChar = openList[i];
				openList[i] = openList[i + 1];
				openList[i + 1] = tempChar;
				didChange = true;
			}
		}
	}
}

int Graph::PrintResult(stack<char> closedList, char nodeNo)
{
	stack<char> result;
	char label;
	cout << endl;
	while (1)
	{
		result.push(closedList.top());
		label = graph[closedList.top() - CONST].cameFrom;
		closedList.pop();
		if (label == 0)
			break;
		if (label != closedList.top())
			closedList.pop();
	}
	cout << endl << "A*: ";
	while (result.size())
	{
		cout << result.top() << " ";
		result.pop();
	}
	cout << endl;
	return 0;
}

int Graph::A_Star(char fromNode, char toNode)
{
	vector<char> openList;
	openList.reserve(Vertex);
	stack<char> closedList;
	node currNode;
	int i;
	int tempG;
	int counter;
	bool isBetter;
	openList.push_back(graph[fromNode - CONST].nodeNo);
	graph[fromNode - CONST].g = 0;
	graph[fromNode - CONST].h = Manhattan(graph[fromNode - CONST], graph[toNode - CONST]);
	graph[fromNode - CONST].open++;
	while (openList.size())
	{
		//PrintNodes();
		SortNodesByF(openList, openList.size());
		closedList.push(openList.back());
		graph[openList.back() - CONST].closed++;
		if (closedList.top() == toNode)
		{
			PrintResult(closedList, toNode);
			cout << "ILOSC POWTORZEN ITERACJI: " << counter << endl;
			return 0;
		}
		graph[openList.back()-CONST].open = false;
		openList.pop_back();
		currNode = graph[closedList.top() - CONST];
		for (i = 0; i < Vertex; i++)
		{
			if (AdjacencyMatrix[currNode.nodeNo - CONST][i] && !graph[i].closed )
			{
				tempG = currNode.g + AdjacencyMatrix[currNode.nodeNo - CONST][i];
				isBetter = false;
				if (!graph[i].open)
				{
					openList.push_back(graph[i].nodeNo);
					graph[i].open = true;
					graph[openList.back() - CONST].h = Manhattan(graph[openList.back() - CONST] , graph[toNode - CONST]);
					isBetter = true;
				}
				else
				{
					if (tempG < graph[i].g)
					{
						isBetter = true;
					}
				}
				if (isBetter)
				{
					graph[i].cameFrom = currNode.nodeNo;
					graph[i].g = tempG;
				}
			}
			counter++;
		}
	}
	cout << endl << "Nie znalaziono sciezki" << endl;
	return 1;
}

void Graph::DFS(char V) 
{
	bool *visited = new bool[Vertex];
	for(int i=0; i<Vertex; i++) 
		visited[i] = false;
	stack<int> S;
	int counter=0;
	S.push(V);
	cout << "DFS:  ";
	while(!S.empty())
	{
		V = S.top();  S.pop();
		if(!visited[V-CONST])
     			{
         			visited[V-CONST] = true;
         			for(int i = 0; i < Vertex; i++) 
				{
					if(AdjacencyMatrix[V-CONST][i] && !visited[i]) 
						S.push(i+CONST);
					counter++;
				}
         			cout << V<< " ";

     			}
	} 
	cout << endl << "ILOSC POWTORZEN ITERACJI: " << counter << endl;
}

void Graph::BFS(char V)
{
	bool *visited = new bool[Vertex];
	for(int i=0; i<Vertex; i++) 
		visited[i] = false;
	queue<int> Q;
	int counter=0;
	Q.push(V);
	cout << "BFS:  ";
	while(!Q.empty())
	{
		V = Q.front();  Q.pop();
		if(!visited[V-CONST])
		{
       			visited[V-CONST] = true;
       			for(int i = 0; i < Vertex; i++) 
			{
				if(AdjacencyMatrix[V-CONST][i] && !visited[i]) 
					Q.push(i+CONST);
				counter++;
			}
         		cout << V << " ";
		}
	} 
	cout << endl << "ILOSC POWTRZEN ITERACJI: " << counter << endl;
}


void Graph::AddEdge(char V1, char V2)
{
	AdjacencyMatrix[V1-CONST][V2-CONST] = AdjacencyMatrix[V2-CONST][V1-CONST] = Manhattan(graph[V1 - CONST], graph[V2 - CONST]);;
}

void Graph::DelEdge(int V1, int V2)
{
	AdjacencyMatrix[V1-CONST][V2-CONST] = AdjacencyMatrix[V2-CONST][V1-CONST] = 0;
}

bool Graph::IsEdge(char V1, char V2)
{
	if(AdjacencyMatrix[V1-CONST][V2-CONST] != 0 && AdjacencyMatrix[V2-CONST][V1-CONST] != 0) return true;
	else return false;
}

void Graph::Neighbourhood(char V)
{
	cout << left << setw(3) << "V";
	for(int i=0; i<Vertex; i++) 
		cout << left << setw(3) << static_cast<char>(CONST+i);
	cout << endl;
	cout << left << setw(3) << V;
	for(int i=0; i<Vertex; i++)
	{
		cout << left << setw(3) << AdjacencyMatrix[V-CONST][i];
	}
	cout << endl << endl;
}

