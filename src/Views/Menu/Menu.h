//
// Created by Ludovic FAVIER on 07/02/2022.
//
#ifndef SVG_CREATOR_MENU_H
#define SVG_CREATOR_MENU_H


#include <map>

#include "../MenuDraw/MenuDraw.cpp"

class Menu {
    MenuDraw drawview;
    std::map<int, std::string> casesMap;
    public:
        Menu();
        void launch();
        void displayWelcomeMessage();
        void displayCasesChoices();
        void getSelectionCaseChoice(int&);
        bool handleSelectionCaseChoice(int&);

};


#endif //SVG_CREATOR_MENU_H
