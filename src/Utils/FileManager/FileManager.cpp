//
// Created by Ludovic FAVIER on 14/02/2022.
//

#include "FileManager.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

FileManager::FileManager(){}

void FileManager::writeFile(std::string name, std::string content) {
    std::ofstream MyFile(name, std::ios::out | std::ios::app);
    if(MyFile){
        MyFile << content;
        MyFile.close();
    }
    else std::cerr << "Error opening the file" << std::endl;

}
void FileManager::writeFileWithBuffer(std::string fileName, int size, char* buffer) {
    std::ofstream newFile(fileName,std::ios::trunc);
    if(newFile){
        newFile.write(buffer, size);
        newFile.close();
    }
    else std::cerr << "Error opening the file" << std::endl;

}

void FileManager::createFileWithSvgHeader(std::string name){
    std::ofstream file(name, std::ios::out | std::ios::trunc);  //stream declaration and file opening
    if(file){
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
                "<svg width=\"1000\" height=\"1000\" viewBox=\"-70.5 -70.5 1000 1000\" xmlns=\"http://www.w3.org/2000/svg\">\n";
        file.close();
    }
    else std::cerr << "Error opening the file" << std::endl;
}

void FileManager::loadFile(std::string name){

}
void FileManager::saveFile(std::string fileNameTemp, std::string fileNameToBeSaved){
    int size;
    char* buffer;

    size = getSizeContentFile(fileNameTemp);
    buffer = new char [size];

    copyContentFileToBuffer(fileNameTemp, size, buffer);

    writeFileWithBuffer(fileNameToBeSaved, size, buffer);

    writeFile(fileNameToBeSaved, "</svg>");

    delete[] buffer;
}

void FileManager::copyContentFileToBuffer(std::string fileName, int size, char * buffer) {
    std::ifstream file(fileName, std::ios::in);
    if(file) {
        file.read(buffer, size);
        file.close();
    }
    else std::cerr << "Error opening the file" << std::endl;
}
int FileManager::getSizeContentFile(std::string fileName) {
    int size;
    std::ifstream file(fileName, std::ios::in|std::ios::ate);
    if(file) {
        size = file.tellg();
        file.close();
        return size;
    }
    else std::cerr << "Error opening the file" << std::endl;

    return 0;
}

void FileManager::removeEndTagSvg(std::string fileName) {
    int size, sizeWithoutEndSvg;
    std::string endTagSvgString = "</svg>";
    char* buffer;

    size = getSizeContentFile(fileName);
    sizeWithoutEndSvg = size - endTagSvgString.length();
    buffer = new char [sizeWithoutEndSvg];

    copyContentFileToBuffer(fileName, sizeWithoutEndSvg, buffer);

    std::this_thread::sleep_for(250ms); //wait file to finish read content before writing

    writeFileWithBuffer(fileName, sizeWithoutEndSvg, buffer);

    delete[] buffer;
}

