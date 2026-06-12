#include "AISystem.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

#include <algorithm>
#include <string>

using namespace geode::prelude;

void AISystem::generate(std::string prompt) {
    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        log::error("LevelEditorLayer not found!");
        return;
    }

    // Convert prompt to lowercase
    std::string cmd = prompt;

    std::transform(
        cmd.begin(),
        cmd.end(),
        cmd.begin(),
        [](unsigned char c) {
            return std::tolower(c);
        }
    );

    // Remove trailing spaces
    while (!cmd.empty() && std::isspace(cmd.back())) {
        cmd.pop_back();
    }

    // Remove leading spaces
    while (!cmd.empty() && std::isspace(cmd.front())) {
        cmd.erase(cmd.begin());
    }

    if (cmd == "spike" || cmd == "1 spike") {
    log::info("Generate 1 spike");

    auto obj = editor->createObject(
        8,
        cocos2d::CCPoint(0.f, 0.f),
        false
    );

    if (obj) {
        editor->addObject(obj);
        log::info("Spike placed");
    }
}

    else if (
        cmd == "cube" ||
        cmd == "cube section"
    ) {
        log::info("Generate cube");

        // TODO:
        // cube gameplay section
    }

    else if (
        cmd == "portal" ||
        cmd == "add portal"
    ) {
        log::info("Generate portal");

        // TODO:
        // portal object
    }

    else if (
        cmd == "wave" ||
        cmd == "wave section"
    ) {
        log::info("Generate wave");

        // TODO:
        // wave portal + gameplay
    }

    else if (
        cmd == "ship" ||
        cmd == "ship section"
    ) {
        log::info("Generate ship");

        // TODO:
        // ship portal + gameplay
    }

    else if (
        cmd == "auto level" ||
        cmd == "autolevel
