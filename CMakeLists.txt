cmake_minimum_required(VERSION 3.21)

project(AILevelGeneratorPro)

find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorUIHook.cpp
    src/AIMenu.cpp
    src/AISystem.cpp
)

setup_geode_mod(${PROJECT_NAME})
