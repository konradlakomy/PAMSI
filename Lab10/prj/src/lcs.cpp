#include "lcs.hh"

/*!
 * \file
 * \brief Opis modułu odpowiedzialnego za implementacje algorytmu NWP.
 *
 *  Plik zawiera opisy metod odpowiedzialnych za wykonywanie operacji  
 *  niezbędnych do wyznaczenia najdłuższego wspólnego podciągu.
 */
	

void LongestCommonSubsequence::AddSequence(string sequence1, string sequence2)
{
	x = sequence1;
	y = sequence2;
	m=x.length();
	n=y.length();

}

int LongestCommonSubsequence::LCS()
{
	int i,j;
  	L = new int * [m + 1];
  	for(i = 0; i <= m; i++) 
		L[i] = new int[n + 1];

  	for(i = 0; i <= m; i++) 
		L[i][0] = 0;
	
  	for(j = 0; j <= n; j++) 
		L[0][j] = 0;

	for(i = 0; i < m; i++)
    		for(j = 0; j < n; j++)
      			if(x[i] == y[j])
        			L[i + 1][j + 1] = 1 + L[i][j];
      			else
        			L[i + 1][j + 1] = max(L[i + 1][j],L[i][j + 1]);
	return L[m][n];
}

void LongestCommonSubsequence::PrintLoadedSequence()
{
	cout << "Sequence 1: " << x << endl;
	cout << "Sequence 2: " << y << endl << endl;
}

void LongestCommonSubsequence::PrintTable()
{
	cout << "Table: " << endl << endl;
	cout << left << setw(3) << " " << setw(3) << "0";
	for(int i=0; i<n; i++)
		cout << left << setw(3) << y[i];
	cout << endl;
	cout << left << setw(3) << "0";
	for(int i=0; i<=m; i++)
	{	
		if(i>=1)
			cout << left << setw(3) << x[i-1];
		for(int j=0; j<=n; j++)
		{
			cout << left << setw(3) << L[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void LongestCommonSubsequence::PrintSubsequence()
{  
	subseq = ""; 
	int i=m-1; 
	int j=n-1;
  	while((i >= 0) && (j >= 0))
    		if(x[i] == y[j])
    		{
      			subseq = x[i] + subseq;
      			i--; 
			j--;
    		}
    		else if(L[i + 1][j] > L[i][j + 1]) 
			j--;
    		else 
			i--;
  		cout << "Result: " << subseq << " | Length: " << L[m][n] << endl << endl;
}


