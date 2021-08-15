#pragma once

#include <iostream>

class Atom {
public:
	float** matrix;
	size_t m; //количество строк
	size_t n; //количество столбцов

	Atom();
	Atom(int _m, int _n);
	Atom(float scalar);
	Atom(const Atom& atom);
	~Atom();

	Atom operator=(const Atom& atom);
	friend std::ostream& operator<< (std::ostream& out, const Atom& atom);
};