cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp Shop.h Shop.cpp Item.cpp Item.h shopDetails.cpp shopDetails.h shopStock.cpp shopStock.h Action.cpp Action.h )