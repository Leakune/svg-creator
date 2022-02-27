//
// Created by Ludovic FAVIER on 26/02/2022.
//

#ifndef SVG_CREATOR_MENUDRAWEXIT_H
#define SVG_CREATOR_MENUDRAWEXIT_H

#include <string>
#include <map>
#include "../../Utils/FileManager/FileManager.h"
#include "../MenuDrawExitSave/MenuDrawExitSave.h"

class MenuDrawExit {
    MenuDrawExitSave menuDrawExitSave;
    std::map<int, std::string> casesMapDrawExit;

    public:
        MenuDrawExit();
        void launch();
        void displaySaveMessage();
        void displayCasesChoicesDrawExit();
        void setSaveOption(std::string&);
        void handleSaveOption(std::string&);
};


#endif //SVG_CREATOR_MENUDRAWEXIT_H
