//
// Created by Ludovic FAVIER on 14/02/2022.
//

#ifndef SVG_CREATOR_FILEMANAGER_H
#define SVG_CREATOR_FILEMANAGER_H

#include <string>
#include <iostream>
#include <fstream>

class FileManager {
    public:
        FileManager();
        void writeFile(std::string name);
        void create(std::string name);
        void loadFile(std::string name);
        void saveFile(std::string name);

};


#endif //SVG_CREATOR_FILEMANAGER_H
