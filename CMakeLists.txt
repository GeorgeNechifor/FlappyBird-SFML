cmake_minimum_required(VERSION 3.26)
project(TetrisGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(TetrisGame main.cpp
        GameTemplate.h
        Bird.h
        Bird.h
        Pipes.h

)

set(SFML_DIR "C:\\GamesCpp\\lib\\sfml\\GCC 13.1.0 MinGW (SEH) - 64-bit\\SFML\\lib\\cmake\\SFML")
target_link_libraries(TetrisGame sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6 REQUIRED graphics network audio window system)