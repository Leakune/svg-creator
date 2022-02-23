//
// Created by Ludovic FAVIER on 07/02/2022.
//

#ifndef SVG_CREATOR_DRAW_H
#define SVG_CREATOR_DRAW_H

#include <string>
#include <map>
#include "../../Utils/FileManager.h"

class MenuDraw {
    FileManager fm;
    std::map<int, std::string> casesMapDraw;
    public:
        MenuDraw();
        void launch();
        void displayWelcomeMessage();
        void displayCasesChoicesDraw();
        void setSelectionCaseChoiceDraw(int&);
        bool handleSelectionCaseChoiceDraw(int&);
        void handleDrawRectangle();
        void handleDrawPolyline();
        void handleDrawLine();
        void handleDrawCircle();
        void loadDrawing();
        void displayDrawing();
};


#endif //SVG_CREATOR_DRAW_H
