#include "AISystem.hpp"
#include "EditorLayerBridge.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

void AISystem::generate(std::string prompt) {
    auto editor = EditorLayerBridge::editor;

    if (!editor) {
        log::error("LevelEditorLayer not found!");
        return;
    }

    if (prompt == "spike") {
        log::info("Generate 1 spike");
    }
    else if (prompt == "10 spikes") {
        log::info("Generate 10 spikes");
    }
    else if (prompt == "cube") {
        log::info("Generate cube");
    }
    else if (prompt == "portal") {
        log::info("Generate portal");
    }
    else if (prompt == "wave") {
        log::info("Generate wave");
    }
    else {
        log::info("Unknown command: {}", prompt);
    }
}
