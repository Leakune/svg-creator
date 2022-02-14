//
// Created by Ludovic FAVIER on 14/02/2022.
//

#ifndef SVG_CREATOR_FILEMANAGER_H
#define SVG_CREATOR_FILEMANAGER_H

#include <string>
#include <iostream>
#include <fstream>

class FileManager {
    std::string name;
    public:
        FileManager(std::string nameFile);
        void writeFile();
};


#endif //SVG_CREATOR_FILEMANAGER_H
