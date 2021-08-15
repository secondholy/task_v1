#include "Conveyor.h"

Conveyor::Conveyor(const std::string& cfgName, const std::string& dataName, const std::string& outputName) {
	file = new FileIO(cfgName, dataName, outputName);
	X = file->getAtom(std::string("X"));


	add = new VecAdd();
	scalMul = new ScalarMult();
	mulMat = new MatMultMat();


	root = new ScalarMultHandler();
	two = new VecAddHandler();
	three = new MatMultMatHandler();

	root->add(two);
	root->add(three);
}

void Conveyor::doCalculations() {
	file->getCommand(command_str, data_str, pos_flag);
	do {
		Atom arg = file->getAtom(data_str);
		if(std::stoi(pos_flag)){
			std::swap(X, arg);
		}
		//std::cout << X << arg;
		root->handle(command_str, X, arg);
		//std::cout << X;
		file->getCommand(command_str, data_str, pos_flag);
	} while (command_str != "" || data_str != "");
	file->write(X);
	std::cout << X;
}


Conveyor::~Conveyor() {
	delete add;
	delete scalMul;
	delete mulMat;

	delete three;
	delete two;
	delete root;
	
	delete file;
}