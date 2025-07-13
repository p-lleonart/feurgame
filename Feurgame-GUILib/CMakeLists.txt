cmake_minimum_required(VERSION 3.28)
project(Feurgame-GUILib LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(
    ${PROJECT_NAME} STATIC
    src/Feurgame-GUILib/BaseEventHandler.cpp
    src/Feurgame-GUILib/Layout.cpp
    src/Feurgame-GUILib/LayoutHandler.cpp
    src/Feurgame-GUILib/Widget.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PUBLIC SFML::Graphics)
