cmake_minimum_required(VERSION 3.15)
project(teo_proyecto)

set(CMAKE_CXX_STANDARD 14)

add_executable(teo_proyecto main.cpp detautomata.h revautomata.h transition.h state.h lib.h equivalencia.h brozozowski.h bettermatrix.h minafd.h)