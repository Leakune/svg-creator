//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "Draw.h"
#include <iostream>

void Draw::displayWelcomeMessage() {
    std::cout << "In Draw !" << std::endl;
}

void Draw::launch() {
    displayWelcomeMessage();
}
