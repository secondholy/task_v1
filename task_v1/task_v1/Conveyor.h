#pragma once
#include "Atom.h"
#include "FileIO.h"
#include "Handlers.h"
#include "Operator.h"
#include <string>

class Conveyor {
private:
	Atom X;
	FileIO* file;

	std::string command_str;
	std::string data_str;
	std::string pos_flag;

	Operator* add;
	Operator* scalMul;
	Operator* mulMat;

	ScalarMultHandler* root;
	VecAddHandler* two;
	MatMultMatHandler* three;
public:
	Conveyor(const std::string& cfgName, const std::string& dataName, const std::string& outputName);
	~Conveyor();
	void doCalculations();
};