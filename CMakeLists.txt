#Specifies the minimum required version of CMake.
#It is set to the version of CMake bundled in CLion (always one of the newest versions available).
cmake_minimum_required(VERSION 3.21)

#Defines the project name according to what we provided during project creation.
project(svg_creator)

#Sets the CMAKE_CXX_STANDARD variable to the value of 17, as we selected when creating the project.
set(CMAKE_CXX_STANDARD 17)

#Adds the svg_creator executable target which will be built from main.cpp.
add_executable(svg_creator main.cpp ./src/Views/Menu/Menu.cpp ./src/Views/MenuDraw/MenuDraw.cpp ./src/Views/MenuNameFile/MenuNameFile.cpp src/Common/FileManager/FileManager.cpp src/Views/MenuDrawExit/MenuDrawExit.cpp src/Views/MenuDrawExit/MenuDrawExit.h src/Common/Utils/Utils.cpp src/Common/Utils/Utils.h src/Views/MenuDrawExitSave/MenuDrawExitSave.cpp src/Views/MenuDrawExitSave/MenuDrawExitSave.h)
