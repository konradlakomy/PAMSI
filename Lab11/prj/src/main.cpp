#include "integral.hh"
#include <iostream>
#include <string>
using namespace std;

/*!
 * \file
 * \brief Modul glowny programu.
 *
 *  Plik zawiera opis funkcji main programu.
 */

int main() {

  ArithmExpr* expr1 = new Add( new Add( new Mult ( new Const(8.0, 0) , new Sin(new Var(0) , 0), 0) , new Mult ( new Const(12.0, 0) , new Cos(new Var(0) , 0 ) , 0 ) ,0 ) , new Mult( new Const(5.0, 0) , new Add( new Const(3.0, 0) , new Power( new Var(0) , 2.0 , 0 ) , 0 ) , 0 ) , 0  );
  	expr1->eval(); cout << "\n"; 

	cout << "-----------------------------------------------------------------" << endl;

	ArithmExpr* expr2 = new Add ( new Mult ( new Const(5.0 , 0 ) , new Add( new Power(new Var(0) , -3.0 , 0) , new Mult( new Const(8.0 , 0) , new Power( new Var(0) , 5.0 , 0 ) , 0 ) , 0 ), 0 ) , new Mult ( new Const(2.0 , 0) , new Power ( new Add ( new Var(0) , new Const(1.0 , 0 ) , 0 ) , 4.0 , 0 ) , 0 ) , 0 ); 
	expr2->eval(); cout << "\n";

	return 0;
}
