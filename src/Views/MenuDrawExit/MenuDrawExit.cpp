//
// Created by Ludovic FAVIER on 26/02/2022.
//

#include "MenuDrawExit.h"
#include "../../Common/Utils/Utils.h"
#include <iostream>
#include <algorithm>

const bool IS_NOT_QUITING_DRAW = false;
const bool IS_QUITING_DRAW = true;

MenuDrawExit::MenuDrawExit(): menuNameFile(MenuNameFile()) {
    casesMapDrawExit[0] = "Yes";
    casesMapDrawExit[1] = "No";
}

void MenuDrawExit::launch() {
    std::string saveOption;

    displaySaveMessage();
    displayCasesChoicesDrawExit();
    setSaveOption(saveOption);
    handleSaveOption(saveOption);
}

void MenuDrawExit::displaySaveMessage() {
    std::cout << "Do you want to save your file?" << std::endl;
}

void MenuDrawExit::displayCasesChoicesDrawExit() {
    std::cout << "(";
    for (const auto& [key, value] : casesMapDrawExit) {
        std::cout << value;
        if(key != casesMapDrawExit.size() - 1){
            std::cout <<"/";
        }
    }
    std::cout << ")" << std::endl;
}

void MenuDrawExit::setSaveOption(std::string &saveOption) {
    std::string getLine;
    std::cout << ">>";
    std::getline(std::cin, getLine);

    for (const auto& [key, value] : casesMapDrawExit) {
        if(Utils::stringsAreEqualsCaseInsensitive(getLine, const_cast<std::string &>(value))){
            //Success
            saveOption = Utils::convertStringToLowerCase(getLine);
            return;
        }
    }
    //Error
    std::cout << "selection is not included in cases choice" << std::endl;
    setSaveOption(saveOption);

}

void MenuDrawExit::handleSaveOption(std::string &saveOption) {
    //save case
    if(saveOption == Utils::convertStringToLowerCase(casesMapDrawExit[0])){
        std::cout << "save selected" << std::endl;
        menuNameFile.nameFileToSave();
        return;
    }

    //leave without save case
    else if(saveOption == Utils::convertStringToLowerCase(casesMapDrawExit[1])){
        std::cout << "exit without save selected" << std::endl;
    }else{
        return;
    }

}


