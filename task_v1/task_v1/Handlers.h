#pragma once

#include <string>
#include <iostream>
#include "Atom.h"
#include "Operator.h"

class BaseHandler {
public:
	BaseHandler* next;
	void setNext(BaseHandler* n);
	void add(BaseHandler* n);
	BaseHandler();
	virtual ~BaseHandler(){}
	virtual void handle(std::string str, Atom& x, const Atom& arg2);
};


class ScalarMultHandler : public BaseHandler {
public:
	ScalarMultHandler();
	~ScalarMultHandler();
	void handle(std::string str, Atom& x, const Atom& arg2);
private:
	Operator* op;
};

class VecAddHandler : public BaseHandler {
public:
	VecAddHandler();
	~VecAddHandler();
	void handle(std::string str, Atom& x, const Atom& arg2);
private:
	Operator* op;
};

class MatMultMatHandler : public BaseHandler {
public:
	MatMultMatHandler();
	~MatMultMatHandler();
	void handle(std::string str, Atom& x, const Atom& arg2);
private:
	Operator* op;
};