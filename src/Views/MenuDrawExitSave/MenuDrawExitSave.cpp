//
// Created by Ludovic FAVIER on 26/02/2022.
//

#include "MenuDrawExitSave.h"
#include <string>

const int MIN_FILE_NAME_LENGTH = 1;
const int MAX_FILE_NAME_LENGTH = 14;

MenuDrawExitSave::MenuDrawExitSave(): fm(FileManager()) {

}

void MenuDrawExitSave::launch() {
    std::string nameFile;

    askNameFileToSave();
    setNameFileToSave(nameFile);
    fm.saveFile("temp.svg", nameFile);
}

void MenuDrawExitSave::askNameFileToSave() {
    std::cout << "Name the file to save:" << std::endl;
}

void MenuDrawExitSave::setNameFileToSave(std::string &nameFile) {
    std::string getLine;
    std::cout << ">>";
    std::getline(std::cin, getLine);

    //Error
    if(!(MIN_FILE_NAME_LENGTH <= getLine.length() && getLine.length() <= MAX_FILE_NAME_LENGTH)){
        std::cout << "name file length must be between " << MIN_FILE_NAME_LENGTH << " and " << MAX_FILE_NAME_LENGTH << std::endl;
        setNameFileToSave(nameFile);
        return;
    }

    //Success
    nameFile = getLine;
}
