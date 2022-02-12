//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "Draw.h"
#include <iostream>

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
    system("open ../Ressources/Drawings/test.svg");
}
