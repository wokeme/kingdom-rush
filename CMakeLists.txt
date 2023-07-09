cmake_minimum_required(VERSION 3.25)
project(start4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(start4
        common.cpp
        common.h
        gamewindow.cpp
        gamewindow.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mybottom.cpp
        mybottom.h)
