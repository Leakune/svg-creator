//
// Created by Ludovic FAVIER on 07/02/2022.
//
#ifndef SVG_CREATOR_MENU_H
#define SVG_CREATOR_MENU_H


#include <map>

#include "../MenuDraw/MenuDraw.h"
#include "../MenuNameFile/MenuNameFile.h"
#include "../../Utils/FileManager/FileManager.h"

class Menu {
    MenuDraw drawview;
    MenuNameFile namefile;
    FileManager fm;
    std::map<int, std::string> casesMap;
    public:
        Menu();
        void launch();
        void displayWelcomeMessage();
        void displayCasesChoices();
        void setSelectionCaseChoice(int&);
        bool handleSelectionCaseChoice(int&);

};


#endif //SVG_CREATOR_MENU_H
