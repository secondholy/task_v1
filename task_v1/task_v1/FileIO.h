#pragma once
#include <iostream>
#include <fstream>
#include "Atom.h"
#include <string>
#include <exception>

class FileIO {
private:
    std::ifstream cfg;
    std::ifstream data;
    std::ofstream out;
public:
    FileIO();
    FileIO(const std::string& cfgName, const std::string& dataName, const std::string& outputName);
    ~FileIO();
    void write(const Atom& atom);
    void getCommand(std::string& commLine, std::string& dataLine, std::string& pos);
    Atom getAtom(std::string name);
};