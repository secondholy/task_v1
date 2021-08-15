#include "Handlers.h"

BaseHandler::BaseHandler() {
	next = nullptr;
}

void BaseHandler::setNext(BaseHandler* n) {
	next = n;
}

void BaseHandler::add(BaseHandler* n) {
	if (next) {
		next->add(n);
	}
	else {
		next = n;
	}
}

void BaseHandler::handle(std::string str, Atom& x, const Atom& arg2) {
	if (next != nullptr) {
		next->handle(str, x, arg2);
	}
	else {
		std::cout << "Invalid operator";
	}
}



ScalarMultHandler::ScalarMultHandler() {
	op = new ScalarMult();
}

ScalarMultHandler::~ScalarMultHandler() {
	delete op;
}

void ScalarMultHandler::handle(std::string str, Atom& x, const Atom& arg2) {
	if (str != "scal_mult_vec") {
		BaseHandler::handle(str, x, arg2);
	}
	else {
		x = op->action(x, arg2);
	}
}




VecAddHandler::VecAddHandler() {
	op = new VecAdd();
}

VecAddHandler::~VecAddHandler() {
	delete op;
}

void VecAddHandler::handle(std::string str, Atom& x, const Atom& arg2) {
	if (str != "vec_add_vec") {
		BaseHandler::handle(str, x, arg2);
	}
	else {
		x = op->action(x, arg2);
	}
}




MatMultMatHandler::MatMultMatHandler() {
	op = new MatMultMat();
}

MatMultMatHandler::~MatMultMatHandler() {
	delete op;
}

void MatMultMatHandler::handle(std::string str, Atom& x, const Atom& arg2) {
	if (str != "mat_mul_mat") {
		BaseHandler::handle(str, x, arg2);
	}
	else {
		x = op->action(x, arg2);
	}
}