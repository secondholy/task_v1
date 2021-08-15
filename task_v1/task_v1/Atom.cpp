#include "Atom.h"

Atom::Atom() {
	m = 0;
	n = 0;
	matrix = nullptr;
}

Atom::Atom(float scalar) {
	m = 1;
	n = 1;
	matrix = new float* [m];
	matrix[0] = new float;
	matrix[0][0] = scalar;
}

Atom::Atom(int _m, int _n) {
	n = _n;
	m = _m;
	matrix = new float* [m];

	for (int i = 0; i < m; i++) {
		matrix[i] = new float[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
}


Atom::Atom(const Atom& atom){
	m = atom.m;
	n = atom.n;

	matrix = new float* [m];

	for (int i = 0; i < m; i++) {
		matrix[i] = new float[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = atom.matrix[i][j];
		}
	}
}

Atom::~Atom() {
	if (n > 0) {
		for (int i = 0; i < m; i++) {
			delete[] matrix[i];
		}
	}

	if (m > 0) {
		delete[] matrix;
	}
}

Atom Atom::operator=(const Atom& atom) {
	if (n > 0) {
		for (int i = 0; i < m; i++) {
			delete[] matrix[i];
		}
	}

	if (m > 0) {
		delete[] matrix;
	}

	m = atom.m;
	n = atom.n;

	matrix = new float* [m];

	for (int i = 0; i < m; i++) {
		matrix[i] = new float[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = atom.matrix[i][j];
		}
	}
	return *this;
}


std::ostream& operator<< (std::ostream& out, const Atom& atom) {
	for (int i = 0; i < atom.m; i++) {
		for (int j = 0; j < atom.n; j++) {
			out << atom.matrix[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}