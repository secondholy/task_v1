#include "FileIO.h"



FileIO::FileIO(const std::string& cfgName, const std::string& dataName, const std::string& outputName) {
	cfg.open(cfgName);
	data.open(dataName);
	out.open(outputName);
}

FileIO::FileIO(){}

FileIO::~FileIO(){
	if (cfg.is_open()) {
		cfg.close();
	}
	if (data.is_open()) {
		data.close();
	}
	if (out.is_open()) {
		out.close();
	}
}

void FileIO::getCommand(std::string& commLine, std::string& dataLine, std::string& pos) {
	if (cfg.is_open() && !cfg.eof()) {
		cfg >> commLine >> dataLine >> pos;
	}
	else {
		commLine = "";
		dataLine = "";
		pos = "";
	}
}


Atom FileIO::getAtom(std::string name) {
	bool notFound = true;
	if (!data.is_open()) {
		throw std::logic_error("File closed!");
	}
	while (notFound) {
		std::string str;
		getline(data, str);

		if (str == name) {
			getline(data, str);
			size_t m = (size_t)std::stoi(str);
			getline(data, str);
			size_t n = (size_t)std::stoi(str);
			Atom atom = Atom(m, n);

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					data >> str;
					atom.matrix[i][j] = std::stof(str);
				}
			}
			notFound = false;
			data.seekg(0, data.beg);
			return atom;
		}
		if (str == "") {
			break;
		}
	}
	throw std::out_of_range("No such string!");
	return Atom();
}

void FileIO::write(const Atom& atom) {
	if (!out.is_open()) {
		throw std::logic_error("File closed!");
	}
	std::string message;
	message += "res\n" + std::to_string(atom.m) + "\n" + std::to_string(atom.n) + "\n";
	for (int i = 0; i < atom.m; i++) {
		for (int j = 0; j < atom.n; j++) {
			message += std::to_string(atom.matrix[i][j]) + " ";
		}
	}
	out << message;
}