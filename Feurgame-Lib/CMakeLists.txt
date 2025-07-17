cmake_minimum_required(VERSION 3.28)
project(Feurgame-Lib LANGUAGES CXX)

import(Feurgame-GUILib)

add_library(
    ${PROJECT_NAME} STATIC
    src/Feurgame-Lib/Army.cpp
    src/Feurgame-Lib/ArmyFactory.cpp
    src/Feurgame-Lib/Box.cpp
    src/Feurgame-Lib/Display.cpp
    src/Feurgame-Lib/Game.cpp
    src/Feurgame-Lib/IO.cpp
    src/Feurgame-Lib/Map.cpp
    src/Feurgame-Lib/Player.cpp
    src/Feurgame-Lib/Region.cpp
    src/Feurgame-Lib/UnitStrategy.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} Feurgame-GUILib)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib
)
