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
    std::cout << "Enter your action: " << std::endl;
    int indexCaseSelected = -1;
    do{
        std::cout << ">>";
        std::cin >> indexCaseSelected;
    }while(!(0 <= indexCaseSelected && indexCaseSelected < casesMap.size()));
    if(indexCaseSelected == 0){
        drawview.launch();
        return false;
    }
    else if(indexCaseSelected == 1){
        std::cout << "Load shapes selected" << std::endl;
        return false;
    }
    else if(indexCaseSelected == 2){
        std::cout << "Exiting the application..." << std::endl;
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
