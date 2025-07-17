cmake_minimum_required(VERSION 3.28)
project(Feurgame-App LANGUAGES CXX)

import(Feurgame-Lib)

add_executable(
    ${PROJECT_NAME}
    src/Feurgame-App/${PROJECT_NAME}.cpp

    src/Feurgame-App/ChooseMap.cpp
    src/Feurgame-App/ChoosePlayer.cpp
    src/Feurgame-App/Game.cpp
    src/Feurgame-App/Home.cpp
    src/Feurgame-App/PlayersForm.cpp

    src/Feurgame-App/Widgets/Buttons.cpp
    src/Feurgame-App/Widgets/Texts.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} Feurgame-Lib)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
