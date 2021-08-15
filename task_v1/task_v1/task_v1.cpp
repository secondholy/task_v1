#include <iostream>
#include "Conveyor.h"

int main() {
	std::string config_str;
	std::string data_str;
	std::string output_str = "output.dat";
	std::cout << "Choose conveyor:\n1 - f1, not 1 - f2\n";
	int type;
	std::cin >> type;
	if (type == 1) {
		std::cout << "You chose 1-st conveyor. Input data: f1.cfg and matrix_data.dat, output data: output.dat. Output:\n\n";
		config_str = "f1.cfg";
		data_str = "matrix_data.dat";
	}
	else {
		std::cout << "You chose 2-nd conveyor. Input data: f2.cfg and matrix_data_2.dat, output data: output.dat. Output:\n\n";
		config_str = "f2.cfg";
		data_str = "matrix_data_2.dat";
	}
	Conveyor conv = Conveyor(config_str, data_str, output_str);
	conv.doCalculations();
	return 0;
}