//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "Menu.h"
#include "../MenuNameFile/MenuNameFile.h"
#include <iostream>
#include <stdexcept>

const bool IS_NOT_QUITING_MENU = false;
const bool IS_QUITING_MENU = true;

Menu::Menu(): drawview(MenuDraw()), menuNameFile(MenuNameFile()), fm(FileManager()) {
    casesMap[0] = "Draw a new drawing";
    casesMap[1] = "Load a drawing";
    casesMap[2] = "Exit";
}

void Menu::launch() {
    bool isModeMenuQuit = false;
    int indexCaseSelected;

    while(!isModeMenuQuit){
        displayWelcomeMessage();
        displayCasesChoices();
        setSelectionCaseChoice(indexCaseSelected);
        isModeMenuQuit = handleSelectionCaseChoice(indexCaseSelected);
    }
}

void Menu::displayWelcomeMessage(){
    std::cout << "Welcome Menu !" << std::endl;
}

void Menu::displayCasesChoices() {
    for (const auto& [key, value] : casesMap) {
        std::cout << key << ": " << value << std::endl;
    }
    std::cout << "Enter your action: " << std::endl;
}

void Menu::setSelectionCaseChoice(int& indexCaseSelected){
    std::string getLine;
    std::cout << ">>";
    std::getline(std::cin, getLine);
    try{
        indexCaseSelected = std::stoi(getLine);
        if(!(0 <= indexCaseSelected && indexCaseSelected < casesMap.size())){
            std::cout << "selection is not included in cases choice" << std::endl;
            displayCasesChoices();
            setSelectionCaseChoice(indexCaseSelected);
        }
    } catch(std::invalid_argument e){
        std::cout << "selection should be integer" << std::endl;
        displayCasesChoices();
        setSelectionCaseChoice(indexCaseSelected);
    }
}

bool Menu::handleSelectionCaseChoice(int& indexCaseSelected) {
    fm.createFileWithSvgHeader("temp.svg");
    switch ( indexCaseSelected ) {
        case 0:
            //création d'un nouveau svg
            drawview.launch();
            return IS_NOT_QUITING_MENU;
        case 1:
            std::cout << "Load shapes selected" << std::endl;
            if(menuNameFile.nameFileToLoad() == 0)
                drawview.launch();
            return IS_NOT_QUITING_MENU;
        case 2:
            std::cout << "Quiting the menu..." << std::endl;
            return IS_QUITING_MENU;
        default:
            return IS_NOT_QUITING_MENU;
    }
}

