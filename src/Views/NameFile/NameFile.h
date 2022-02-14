//
// Created by Ludovic FAVIER on 14/02/2022.
//

#ifndef SVG_CREATOR_NAMEFILE_H
#define SVG_CREATOR_NAMEFILE_H
#include <string>

class NameFile {
    public:
    NameFile();
    void launch();
    void create(std::string name);
    std::string askNameFile();
    void loadFile(std::string name);
    void saveFile(std::string name);
};


#endif //SVG_CREATOR_NAMEFILE_H
