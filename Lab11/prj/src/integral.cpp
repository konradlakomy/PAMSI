#include "integral.hh"

/*!
 * \file
 * \brief Opis modułu zawierającego obiekty umożliwiające liczenie całek.
 * 
 * Plik zawiera deklaracje klas oraz metod odpowiedzialnych za wykonywanie podstawowych operacji na całkach.
 *
 */

Const::Const(double x, int s):
	val(x) , state(s) { if(state == 1 ) cout << val << endl; }

ArithmExpr* Const::eval() {
	return new Mult(new Const(val, 1), new Var(1) , 1);
}

string Const::toString() {
	ostringstream s;
	s << val;
	return s.str();
}

int Const::type() {
	return 0;
}


Var::Var(int x):
	state(x) {if(state == 1) cout << "x" << endl;};

ArithmExpr* Var::eval() {
	return new Power(new Var(1), 2.0, 1);
}

string Var::toString() {
	return "x";
}

int Var::type() {
	return 1;
}


Add::Add(ArithmExpr* leftOperand, ArithmExpr* rightOperand , int x):
	arg1(leftOperand), arg2(rightOperand) , state(x) { if(state==1) cout << toString() << endl; }

ArithmExpr* Add::eval() {
	if ((arg1->type() == 7) || (arg2->type() == 7))
		return new Nothing();
	return new Add(arg1->eval(), arg2->eval(), 1);
}

string Add::toString() {
	return "(" + arg1->toString() + ") + (" + arg2->toString() + ")";
}

int Add::type() {
	return 2;
}


Mult::Mult(ArithmExpr* leftOperand, ArithmExpr* rightOperand , int x):
	arg1(leftOperand), arg2(rightOperand), state(x) { if(state==1) cout <<toString() << endl; };

ArithmExpr* Mult::eval() {
	if (arg1->type() > arg2->type())
		swap(arg1, arg2);

	if ((arg1->type() == 0) && (arg2->type() == 1))
		return new Mult(arg1, new Power(new Var(1), 2.0, 1) , 1);
	if ((arg1->type() == 1) && (arg2->type() == 1))
		return new Power(new Var(1), 3.0, 1);
	if (arg1->type() == 0)
		cout << arg1->toString() << endl;
		return new Mult(arg1, arg2->eval() , 1);
	return new Nothing();
}

string Mult::toString() {
	return "(" + arg1->toString() + ") * (" + arg2->toString() + ")";
}

int Mult::type() {	
	return 3;
}


Power::Power(ArithmExpr* leftOperand, double rightOperand , int x):
	arg1(leftOperand), arg2(rightOperand) , state(x) { if (state==1) cout << toString() << endl; };
 
ArithmExpr* Power::eval() {
	if (arg1->type() == 0)
		return new Nothing(); 
	if (arg1->type() == 1) {
			cout << "(1/" << arg2 + 1.0 << ")" << endl;
			cout << "(" << arg1->toString() << ") ^ " << arg2 + 1.0 << endl;
	
		return new Power(new Var(0), arg2 + 1.0 , 1);
	}
	if (arg1->type() == 2) {
		cout << "(1/" << arg2 + 1.0 << ")" << endl;
		cout << "(" << arg1->toString() << ") ^ " << arg2 + 1.0 << endl;
		return new Power(arg1, arg2 + 1.0 , 1);
	}
	return new Nothing();
}

string Power::toString() {
	ostringstream s;
	if(state == 0) { s << "(" << arg1->toString() << ") ^ " << arg2;}
	else {

	s << "(1/";
	s << arg2;
	s << ") * (" << arg1->toString() << ") ^ ";
	s << arg2;
	}
	return s.str();
}

int Power::type() {
	return 4;
}


Sin::Sin(ArithmExpr* operand, int s):
	arg(operand) , state(s) { if(state == 1) cout << toString() << endl; };

ArithmExpr* Sin::eval() {
	if (arg->type() == 0)
		return new Mult(new Sin(arg, 1), new Var(1) , 1);
	if (arg->type() == 1)
		return new Mult(new Const(-1.0 , 1), new Cos(new Var(0), 1) , 1);
	return new Nothing();
}

string Sin::toString() {
	return "sin(" + arg->toString() + ")";
}

int Sin::type() {
	return 5;
}

Cos::Cos(ArithmExpr* operand, int s ):
	arg(operand) , state(s) { if(state==1) cout << toString() << endl; };

ArithmExpr* Cos::eval() {
	if (arg->type() == 0)
		return new Mult(new Cos(arg , 1), new Var(1) , 1);
	if (arg->type() == 1)
		return new Sin(new Var(0), 1);
	return new Nothing();
}

string Cos::toString() {
	return "cos(" + arg->toString() + ")";
}

int Cos::type() {
	return 6;
}


Nothing::Nothing() { };

ArithmExpr* Nothing::eval() {
	return this;
}

string Nothing::toString() {
	return "cannot compute";
}

int Nothing::type() {
	return 7;
}
