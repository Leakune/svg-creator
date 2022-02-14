//
// Created by Ludovic FAVIER on 14/02/2022.
//

#include "FileManager.h"
#include <string>
#include <iostream>
#include <fstream>

FileManager::FileManager(std::string nameFile): name(nameFile) {}

void FileManager::writeFile() {
    std::ofstream MyFile(name);
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile.close();
}