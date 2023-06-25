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

    std::string line;
    std::string value;
    std::vector<std::string> buffer;

    while(std::getline(_inFile, line)){

        buffer.clear();

        std::stringstream str(line);

        while(std::getline(str, value, ';')){
            buffer.push_back(value);
        }
        _bookContents.push_back(buffer);
        
    }

    std::cout<< "File "<< fileName << "has been successfully read. Closing "<< fileName <<"...\n";
    _inFile.close();
}
