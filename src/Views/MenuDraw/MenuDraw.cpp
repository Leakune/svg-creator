//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "MenuDraw.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

const bool IS_NOT_QUITING_DRAW = false;
const bool IS_QUITING_DRAW = true;

void MenuDraw::displayWelcomeMessage() {
    std::cout << "In MenuDraw !" << std::endl;
}

void MenuDraw::launch() {
    bool isModeDrawQuit = IS_NOT_QUITING_DRAW;

    while(!isModeDrawQuit){
        displayWelcomeMessage();
        isModeDrawQuit = IS_QUITING_DRAW;
    }
}

void MenuDraw::loadDrawing() {
    #ifdef _WIN32
    ShellExecute(NULL, "open", "..\\Ressources\\Drawings\\test.svg",
                NULL, NULL, SW_SHOWNORMAL);
    #else
    system("open ../Ressources/Drawings/test.svg");
    #endif

}
