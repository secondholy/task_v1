#pragma once

#include "Atom.h"

class Operator {
public:
	Operator();
	virtual ~Operator(){}
	virtual Atom action(Atom arg1, Atom arg2) = 0;
};

class ScalarMult : public Operator {
	Atom action(Atom arg1, Atom arg2);
};

class VecAdd : public Operator {
	Atom action(Atom arg1, Atom arg2);
};

class MatMultMat : public Operator {
	Atom action(Atom arg1, Atom arg2);
};