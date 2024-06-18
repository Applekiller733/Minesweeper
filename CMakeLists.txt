cmake_minimum_required(VERSION 3.27)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/msvc2019_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Minesweeper main.cpp
        Domain/Square.cpp
        Domain/Square.h
        Domain/Square.h
        Repository/Repository.cpp
        Repository/Repository.h
        Repository/Repository.h
        GUI/GUI.cpp
        GUI/GUI.h
        GUI/GUI.h)
target_link_libraries(Minesweeper
        Qt::Core
        Qt::Gui
        Qt::Widgets
)