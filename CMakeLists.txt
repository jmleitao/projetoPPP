cmake_minimum_required(VERSION 3.13)
project(Projeto C)

set(CMAKE_C_STANDARD 99)

add_executable(Projeto main.c Headers/structs.h structs.c files.c Headers/files.h functions.c Headers/functions.h StudentsList.c Headers/StudentsList.h PlacesList.c Headers/PlacesList.h PointsOfInterestList.c Headers/PointsOfInterestList.h Menus.c Headers/Menus.h)
