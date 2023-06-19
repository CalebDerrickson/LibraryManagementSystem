#pragma once
#include <fstream>
#include "Library.h"
#include <vector>
#include <sstream>
class FileManager{
    public:

        FileManager();
        ~FileManager();


        void readFile(std::string fileName);
    private:

        std::ifstream _inFile;        
        std::string _line;
        std::string _value;
        std::vector<std::string> _buffer;

        
        std::vector<std::vector<std::string>> _bookContents;
        //just read in for now
        //std::ofstream _outFile;
};