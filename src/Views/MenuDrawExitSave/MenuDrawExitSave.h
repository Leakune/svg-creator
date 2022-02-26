//
// Created by Ludovic FAVIER on 26/02/2022.
//

#ifndef SVG_CREATOR_MENUDRAWEXITSAVE_H
#define SVG_CREATOR_MENUDRAWEXITSAVE_H


#include "../../Utils/FileManager/FileManager.h"

class MenuDrawExitSave {
    FileManager fm;
    public:
        MenuDrawExitSave();
        void launch();
        void askNameFileToSave();
        void setNameFileToSave(std::string&);
};


#endif //SVG_CREATOR_MENUDRAWEXITSAVE_H
