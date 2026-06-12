cmake_minimum_required(VERSION 3.21)

project(AILevelGeneratorPro)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}

    src/main.cpp
    src/EditorUIHook.cpp
)
