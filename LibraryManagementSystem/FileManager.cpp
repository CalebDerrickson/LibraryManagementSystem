#include "FileManager.h"
#include <iostream>

 
FileManager::FileManager(){


}


FileManager::~FileManager(){

}


void FileManager::readFile(std::string fileName){

    
    std::ifstream inFile;
    inFile.open(fileName);

    if(!inFile.is_open()){
        std::cout<<"File "<< fileName <<" failed to open!\n";
        return;
    }

    std::string line;
    std::string value;
    std::vector<std::string> buffer;

    while(std::getline(inFile, line)){

        buffer.clear();

        std::stringstream str(line);

        while(std::getline(str, value, ';')){
            buffer.push_back(value);
        }
        _contentsVector.push_back(buffer);
        
    }

    std::cout<< "File "<< fileName << "has been successfully read. Closing "<< fileName <<"...\n";
    inFile.close();
}



