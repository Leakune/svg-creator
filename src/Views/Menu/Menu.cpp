//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "Menu.h"
#include <iostream>

void Menu::displayWelcomeMessage(){
    std::cout << "Welcome Menu !" << std::endl;
}

Menu::Menu(): drawview(Draw()) {
    casesMap[0] = "Draw new shapes";
    casesMap[1] = "Load shapes";
    casesMap[2] = "Exit";
}

bool Menu::handleCaseChoice() {
    for (const auto& [key, value] : casesMap) {
        std::cout << key << ": " << value << std::endl;
    }
    std::cout << "Enter your action: " << std::endl << ">>";
    int indexCaseSelected;
    do{
        std::cin >> indexCaseSelected;
    }while(!(0 < indexCaseSelected || indexCaseSelected < casesMap.size()));
    if(indexCaseSelected == 0){
        drawview.launch();
        return false;
    }
    else if(indexCaseSelected == 1){
        std::cout << "Load shapes selected";
        return false;
    }
    else if(indexCaseSelected == 2){
        return true;
    }
}

void Menu::launch() {
    bool isModeMenuExit = false;

    while(!isModeMenuExit){
        displayWelcomeMessage();
        isModeMenuExit = handleCaseChoice();
    }

}
