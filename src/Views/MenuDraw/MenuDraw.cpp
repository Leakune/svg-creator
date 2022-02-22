//
// Created by Ludovic FAVIER on 07/02/2022.
//

#include "MenuDraw.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

const bool IS_NOT_QUITING_DRAW = false;
const bool IS_QUITING_DRAW = true;

MenuDraw::MenuDraw(): fm(FileManager()) {
    casesMapDraw[0] = "Draw a rectangle";
    casesMapDraw[1] = "Draw a circle";
    casesMapDraw[2] = "Draw a segment";
    casesMapDraw[3] = "Draw a polygon";
    casesMapDraw[4] = "Display drawing";
    casesMapDraw[5] = "Exit";
}

void MenuDraw::launch() {
    bool isModeDrawQuit = IS_NOT_QUITING_DRAW;
    int indexCaseDrawSelected;

    displayWelcomeMessage();

    while(!isModeDrawQuit){
        displayCasesChoicesDraw();
        setSelectionCaseChoiceDraw(indexCaseDrawSelected);
        isModeDrawQuit = handleSelectionCaseChoiceDraw(indexCaseDrawSelected);
    }
}

void MenuDraw::displayWelcomeMessage() {
    std::cout << "In MenuDraw !" << std::endl;
}

void MenuDraw::displayCasesChoicesDraw() {
    for (const auto& [key, value] : casesMapDraw) {
        std::cout << key << ": " << value << std::endl;
    }
    std::cout << "Enter your action: " << std::endl;
}

void MenuDraw::setSelectionCaseChoiceDraw(int& indexCaseSelected) {
    std::string getLine;
    std::cout << ">>";
    std::getline(std::cin, getLine);
    try{
        indexCaseSelected = std::stoi(getLine);
        if(!(0 <= indexCaseSelected && indexCaseSelected < casesMapDraw.size())){
            std::cout << "selection is not included in cases choice" << std::endl;
            setSelectionCaseChoiceDraw(indexCaseSelected);
        }
    } catch(std::invalid_argument e){
        std::cout << "selection should be integer" << std::endl;
        setSelectionCaseChoiceDraw(indexCaseSelected);
    }
}

bool MenuDraw::handleSelectionCaseChoiceDraw(int &indexCaseDrawSelected) {
    switch ( indexCaseDrawSelected ) {
        case 0: // draw rectangle

            handleDrawRectangle();
            // write tmp in svg
            return IS_NOT_QUITING_DRAW;
        case 1:
            std::cout << "TODO draw circle" << std::endl;
            return IS_NOT_QUITING_DRAW;
        case 2:
            std::cout << "TODO draw segment" << std::endl;
            return IS_NOT_QUITING_DRAW;
        case 3:
            std::cout << "TODO draw polygon" << std::endl;
            return IS_NOT_QUITING_DRAW;
        case 4:
            displayDrawing();
            return IS_NOT_QUITING_DRAW;
        case 5:
            std::cout << "TODO display menu exit (save or not)" << std::endl;
            return IS_QUITING_DRAW;
        default:
            return IS_NOT_QUITING_DRAW;
    }
}

void MenuDraw::loadDrawing() {
    #ifdef _WIN32
    ShellExecute(NULL, "open", "..\\Ressources\\Drawings\\test.svg",
                NULL, NULL, SW_SHOWNORMAL);
    #elif __linux__
    system("xdg-open ../Ressources/Drawings/test.svg");
    #else
    system("open ../Ressources/Drawings/test.svg");
    #endif

}

void MenuDraw::handleDrawRectangle() {
    std::string x, y, width, height, strokeWidth, fill, color;
    std::string content;

    std::cout << "Origin X of rectangle" << std::endl;
    std::getline(std::cin, x);
    std::cout << "Origin Y of rectangle" << std::endl;
    std::getline(std::cin, y);
    std::cout << "Width of rectangle" << std::endl;
    std::getline(std::cin, width);
    std::cout << "Height of rectangle" << std::endl;
    std::getline(std::cin, height);
    std::cout << "Width of the strokes" << std::endl;
    std::getline(std::cin, strokeWidth);
    std::cout << "Fill of rectangle" << std::endl;
    std::getline(std::cin, fill);
    std::cout << "Color of rectangle" << std::endl;
    std::getline(std::cin, color);

    content = "<rect x=\"" + x + "\" y=\"" + y + "\" width=\"" + width + "\" height=\"" +  height + "\" fill=\"" + fill + "\" stroke-width=\"" + strokeWidth + "\" stroke=\"" + color +"\" />\n";

    fm.writeFile("temp.svg", content);
}

void MenuDraw::displayDrawing() {
    std::string content = "</svg>";
    fm.writeFile("temp.svg", content);

    #ifdef _WIN32
        ShellExecute(NULL, "open", "temp.svg",
                    NULL, NULL, SW_SHOWNORMAL);
    #elif __linux__
        system("xdg-open ./temp.svg");
    #else
        system("open ./temp.svg");
    #endif
}
