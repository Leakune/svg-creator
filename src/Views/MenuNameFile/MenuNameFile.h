//
// Created by Ludovic FAVIER on 14/02/2022.
//

#ifndef SVG_CREATOR_NAMEFILE_H
#define SVG_CREATOR_NAMEFILE_H
#include <string>
#include "../../Common/FileManager/FileManager.h"

class MenuNameFile {
    FileManager fm;
    bool isLoad;
    public:
        MenuNameFile();
        void nameFileToSave();
        int nameFileToLoad();
        void setNameFile(std::string&);
};


#endif //SVG_CREATOR_NAMEFILE_H
