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
    MyFile.seekp(-6, std::ios::end);
    MyFile << content;
    MyFile.close();
}
void FileManager::create(std::string name){
    std::ofstream file(name, std::ios::out | std::ios::trunc);  //stream declaration and file opening
    if(file){
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n"
                "<svg width=\"391\" height=\"391\" viewBox=\"-70.5 -70.5 391 391\" xmlns=\"http://www.w3.org/2000/svg\">\n";
        file.close();
    }
    else
        std::cerr << "Error opening the file" << std::endl;
}

void FileManager::loadFile(std::string name){

}
void FileManager::saveFile(std::string name){

}

void FileManager::removeEndTagSvg(std::string fileName) {
    int size, sizeWithoutEndSvg;
    std::string endTagSvgString = "</svg>";
    char* buffer;

    std::ifstream file(fileName, std::ios::in|std::ios::ate);
    size = file.tellg();
    sizeWithoutEndSvg = size - endTagSvgString.length();

    buffer = new char [sizeWithoutEndSvg];
    file.seekg(0, std::ios::beg);
    file.read(buffer, sizeWithoutEndSvg);
    file.close();

    std::this_thread::sleep_for(250ms); //wait file to finish read content before writing

    std::ofstream newFile(fileName,std::ios::trunc);
    newFile.write(buffer, sizeWithoutEndSvg);
    newFile.close();

    delete[] buffer;
}
