//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "Draw.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

const bool IS_NOT_QUITING_DRAW = false;
const bool IS_QUITING_DRAW = true;

void Draw::displayWelcomeMessage() {
    std::cout << "In Draw !" << std::endl;
}

void Draw::launch() {
    bool isModeDrawQuit = IS_NOT_QUITING_DRAW;

    while(!isModeDrawQuit){
        displayWelcomeMessage();
        isModeDrawQuit = IS_QUITING_DRAW;
    }
}

void Draw::loadDrawing() {
    #ifdef _WIN32
    ShellExecute(NULL, "open", "http://dreamincode.net",
                NULL, NULL, SW_SHOWNORMAL);
    #else
    system("open ../Ressources/Drawings/test.svg");
    #endif

}
