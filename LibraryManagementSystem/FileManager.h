#pragma once
#include <fstream>
#include "Library.h"
#include <vector>
#include <sstream>

class FileManager {
public:

    FileManager();
    ~FileManager();


    void readFile(std::string fileName);

    std::vector<std::vector<std::string>> getContents() { return _contentsVector; }

private:

    std::vector<std::vector<std::string>> _contentsVector;

};
