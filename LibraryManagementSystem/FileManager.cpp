#include "FileManager.h"
#include <iostream>
FileManager::FileManager(){


}

FileManager::~FileManager(){

}

void FileManager::readFile(std::string fileName){

    _inFile.open(fileName);

    if(!_inFile.is_open()){
        std::cout<<" File "<< fileName <<" failed to open!\n";
        return;
    }

    while(std::getline(_inFile, _line)){

        _buffer.clear();

        std::stringstream str(_line);

        while(std::getline(str, _value, ';')){
            _buffer.push_back(_value);
        }
        _bookContents.push_back(_buffer);
        
    }

    std::cout<< "File "<< fileName<< "has been successfully read. Closing "<< fileName <<"...\n";
    _inFile.close();
}
