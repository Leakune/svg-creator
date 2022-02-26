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
        void writeFile(std::string, std::string);
        void writeFileWithBuffer(std::string, int, char*);
        void createFileWithSvgHeader(std::string);
        void loadFile(std::string);
        void saveFile(std::string, std::string);
        void removeEndTagSvg(std::string);
        int getSizeContentFile(std::string);
        void copyContentFileToBuffer(std::string, int, char*);
};


#endif //SVG_CREATOR_FILEMANAGER_H
