//
// Created by Ludovic FAVIER on 07/02/2022.
//

#ifndef SVG_CREATOR_DRAW_H
#define SVG_CREATOR_DRAW_H

#include <string>
#include <map>
class MenuDraw {
    std::map<int, std::string> casesMapDraw;
    public:
        MenuDraw();
        void launch();
        void displayWelcomeMessage();
        void displayCasesChoicesDraw();
        void setSelectionCaseChoiceDraw(int&);
        bool handleSelectionCaseChoiceDraw(int&);
        void loadDrawing();
};


#endif //SVG_CREATOR_DRAW_H
