#include <Geode/modify/EditorUI.hpp>
#include <Geode/ui/GeodeUI.hpp>

#include "AIMenu.hpp"

using namespace geode::prelude;#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

#include "AIMenu.hpp"

using namespace geode::prelude;

class $modify(EditorUIHook, EditorUI) {

    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer))
            return false;

        auto sprite =
            CCSprite::createWithSpriteFrameName(
                "GJ_plusBtn_001.png"
            );

        auto btn =
            CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(EditorUIHook::onAIButton)
            );

        btn->setPosition(
            ccp(-160.f, 90.f)
        );

        if (m_buttonMenu)
            m_buttonMenu->addChild(btn);

        return true;
    }

    void onAIButton(CCObject*) {

        auto scene = CCScene::create();

        scene->addChild(
            AIMenu::create()
        );

        CCDirector::sharedDirector()
            ->pushScene(scene);
    }
};
