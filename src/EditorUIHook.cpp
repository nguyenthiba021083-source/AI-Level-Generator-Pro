#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/binding/LevelEditorLayer.hpp>

#include "AIMenu.hpp"
#include "EditorLayerBridge.hpp"

using namespace geode::prelude;

class $modify(EditorUIHook, EditorUI) {
public:
    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer))
            return false;

        // Save editor pointer for AI system
        EditorLayerBridge::editor = editorLayer;

        auto sprite =
            CCSprite::createWithSpriteFrameName(
                "GJ_plusBtn_001.png"
            );

        if (!sprite)
            return true;

        auto btn =
            CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(EditorUIHook::onAIButton)
            );

        btn->setScale(0.8f);
        btn->setPosition(ccp(-160.f, 90.f));

        if (m_buttonMenu)
            m_buttonMenu->addChild(btn);

        log::info("AI Button Added");

        return true;
    }

    void onAIButton(CCObject*) {
        auto popup = AIMenu::create();

        if (popup) {
            CCDirector::sharedDirector()
                ->getRunningScene()
                ->addChild(popup, 9999);

            log::info("AI Menu Opened");
        }
    }
};
