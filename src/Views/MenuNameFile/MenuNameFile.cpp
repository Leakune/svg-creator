//
// Created by Ludovic FAVIER on 14/02/2022.
//

#include "MenuNameFile.h"
#include <iostream>
#include <string>

MenuNameFile::MenuNameFile(): fm(FileManager()), isLoad(isLoad) {}

const int MIN_FILE_NAME_LENGTH = 1;
const int MAX_FILE_NAME_LENGTH = 14;

void MenuNameFile::nameFileToSave() {
    std::string name;
    std::cout << "Enter the name file to save:" << std::endl;
    setNameFile(name);
    fm.saveFile("temp.svg", name);
}

int MenuNameFile::nameFileToLoad() {
    std::string name;
    std::cout << "Enter the name file to load:" << std::endl;
    setNameFile(name);
    return fm.loadFile(name);
}

void MenuNameFile::setNameFile(std::string &nameFile) {
    std::string getLine;
    std::cout << ">>";
    std::getline(std::cin, getLine);

    //Error
    if(!(MIN_FILE_NAME_LENGTH <= getLine.length() && getLine.length() <= MAX_FILE_NAME_LENGTH)){
        std::cout << "name file length must be between " << MIN_FILE_NAME_LENGTH << " and " << MAX_FILE_NAME_LENGTH << std::endl;
        setNameFile(nameFile);
        return;
    }

    //Success
    nameFile = getLine;
}

