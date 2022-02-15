//
// Created by Ludovic FAVIER on 14/02/2022.
//

#include "FileManager.h"
#include <string>
#include <iostream>
#include <fstream>

FileManager::FileManager(){}

void FileManager::writeFile(std::string name) {
    std::ofstream MyFile(name);
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile.close();
}
void FileManager::create(std::string name){
    std::ofstream file(name, std::ios::out | std::ios::trunc);  //stream declaration and file opening

    if(file){
        file << "test";
        file.close();
    }
    else
        std::cerr << "Erreur à l'ouverture !" << std::endl;
}

void FileManager::loadFile(std::string name){

}
void FileManager::saveFile(std::string name){

}
