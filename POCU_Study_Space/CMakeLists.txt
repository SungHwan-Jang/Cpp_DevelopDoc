cmake_minimum_required(VERSION 3.26)
project(POCU_Study_Space)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}  "C:\\Qt\\6.6.2\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC  ON)

set(QT_VERSION 6)

include_directories("C:\\Qt\\6.6.2\\mingw_64\\include\\QtWidgets")

add_executable(POCU_Study_Space main.cpp
        section3_output/3_output.cpp
        section3_output/3_output.h)
