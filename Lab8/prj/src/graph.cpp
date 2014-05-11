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
	AdjacencyMatrix = new int*[MaxVertexAmount];
	for(int i=0; i<MaxVertexAmount; i++)
		AdjacencyMatrix[i] = new int[MaxVertexAmount];
		for(int i=0; i<MaxVertexAmount; i++)
			for(int j=0; j<MaxVertexAmount; j++)
				AdjacencyMatrix[i][j]=0;
}

void Graph::Print() 
{
	cout << left << setw(4) << "V";
	for(int i=0; i<Vertex; i++) 
		cout << left << setw(3) << i;
	cout << endl;
	for(int i=0; i<Vertex; i++)
	{
		cout << left << i << setw(3) << ":";
		for(int j=0; j<Vertex; j++) 
		{
			cout << left << setw(3) << AdjacencyMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Graph::AddEdge(int V1, int V2, int C)
{
	AdjacencyMatrix[V1][V2] = AdjacencyMatrix[V2][V1] = C;
}

void Graph::DelEdge(int V1, int V2)
{
	AdjacencyMatrix[V1][V2] = AdjacencyMatrix[V2][V1] = 0;
}

bool Graph::IsEdge(int V1, int V2)
{
	if(AdjacencyMatrix[V1][V2] != 0 && AdjacencyMatrix[V2][V1] != 0) return true;
	else return false;
}

void Graph::Neighbourhood(int V)
{
	cout << left << setw(3) << "V";
	for(int i=0; i<Vertex; i++) 
		cout << left << setw(3) << i;
	cout << endl;
	cout << V << ": ";
	for(int i=0; i<Vertex; i++)
	{
		cout << left << setw(3) << AdjacencyMatrix[V][i];
	}
	cout << endl << endl;
}

int Graph::Load(string NazwaPliku)
{
	int V1, V2, C;
	ifstream StrmWe;
	StrmWe.open(NazwaPliku.c_str());
	if(!StrmWe.is_open()) 
	{
		cerr << "!!! Plik nie zostal otwarty" << endl; 
		return 1;
	}
	StrmWe>>Vertex >> Edge;
	while(!StrmWe.eof()) {
		StrmWe>>V1>>V2>>C;
		if (StrmWe.fail()) {
			StrmWe.clear();
			StrmWe.ignore(numeric_limits<int>::max( ),'\n');
		} 
		else { 
			AddEdge(V1,V2,C);
		}
	}
	StrmWe.close();
	return 0;
}

void Graph::DFS(int V1) 
{
	bool *visited = new bool[Vertex];
	for(int i=0; i<Vertex; i++) 
		visited[i] = false;
	stack<int> S;
	S.push(V1);
	cout << "DFS:  ";
	while(!S.empty())
	{
		V1 = S.top();  S.pop();
		if(!visited[V1])
     			{
         			visited[V1] = true;
         			for(int i = 0; i < Vertex; i++) 
				if(AdjacencyMatrix[V1][i] && !visited[i]) 
					S.push(i);
         			cout << V1 << " ";
     			}
	} 
	cout << endl << endl;
}

void Graph::BFS(int V1)
{
	bool *visited = new bool[Vertex];
	for(int i=0; i<Vertex; i++) 
		visited[i] = false;
	queue<int> Q;
	Q.push(V1);
	cout << "BFS:  ";
	while(!Q.empty())
	{
		V1 = Q.front();  Q.pop();
		if(!visited[V1])
		{
       			visited[V1] = true;
       			for(int i = 0; i < Vertex; i++) 
				if(AdjacencyMatrix[V1][i] && !visited[i]) 
					Q.push(i);
         			cout << V1 << " ";
		}
	} 
	cout << endl << endl;
}
