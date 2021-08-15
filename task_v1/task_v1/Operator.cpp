#include "Operator.h"

Operator::Operator() {}

Atom ScalarMult::action(Atom arg1, Atom arg2) {
	float sum = 0;
	if (arg1.n == 1 && arg2.n == 1 && arg1.m == arg2.m) {
		for (int i = 0; i < arg1.m; i++) {
			sum += arg1.matrix[i][0] * arg2.matrix[i][0];
		}
		return Atom(sum);
	}
	throw std::logic_error("Vectors match size only!");
	return Atom();
}

Atom VecAdd::action(Atom arg1, Atom arg2) {
	if (arg1.n == 1 && arg2.n == 1 && arg1.m == arg2.m) {
		Atom res = Atom(arg1.m, arg1.n);
		for (int i = 0; i < arg1.m; i++) {
			res.matrix[i][0] = arg1.matrix[i][0] + arg2.matrix[i][0];
		}
		return res;
	}
	throw std::logic_error("Vectors match size only!");
	return Atom();
}

Atom MatMultMat::action(Atom arg1, Atom arg2) {
	if (arg1.n == arg2.m) {
		Atom res = Atom(arg1.m, arg2.n);
		for (int i = 0; i < arg1.m; i++) {
			for (int j = 0; j < arg2.n; j++) {
				for (int k = 0; k < arg1.n; k++) {
					res.matrix[i][j] += arg1.matrix[i][k] * arg2.matrix[k][j];
				}
			}
		}
		return res;
	}
	throw std::logic_error("Wrong size!");
	return Atom();
}
