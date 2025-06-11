cmake_minimum_required(VERSION 3.28)
project(FeurGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(
    ${PROJECT_NAME}
    src/${PROJECT_NAME}.cpp

    src/App/Home.cpp
    src/App/PlayersForm.cpp

    src/App/Widgets/Buttons.cpp
    src/App/Widgets/Texts.cpp

    src/Lib/BaseEventHandler.cpp
    src/Lib/Layout.cpp
    src/Lib/LayoutHandler.cpp
    src/Lib/Widget.cpp

    src/Game/Army.cpp
    src/Game/ArmyFactory.cpp
    src/Game/Box.cpp
    src/Game/Game.cpp
    src/Game/IO.cpp
    src/Game/Map.cpp
    src/Game/Player.cpp
    src/Game/Region.cpp
    src/Game/UnitStrategy.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)
