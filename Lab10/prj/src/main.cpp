#include "lcs.hh"

/*!
 * \file
 * \brief Modul glowny programu.
 *
 *  Plik zawiera opis funkcji main programu.
 */

int main()
{
	LongestCommonSubsequence L1, L2;
	L1.AddSequence("ALIBABA" , "KALIMALBA");
	L1.PrintLoadedSequence();	
	L1.LCS();
	L1.PrintSubsequence();
	L1.PrintTable();

	L2.AddSequence("LABRADOR" , "RABARBAR");
	L2.PrintLoadedSequence();	
	L2.LCS();
	L2.PrintSubsequence();
	L2.PrintTable();
	
	return 0;
}
