#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(AIEditorUI, EditorUI) {
    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer))
            return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto sprite =
            CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");

        auto btn = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(AIEditorUI::onAIButton)
        );

        auto menu = CCMenu::create();
        menu->addChild(btn);

        menu->setPosition(
            winSize.width - 50.f,
            winSize.height - 100.f
        );

        this->addChild(menu);

        return true;
    }

    void onAIButton(CCObject*) {
        FLAlertLayer::create(
            "AI Level Generator",
            "AI Button Working!",
            "OK"
        )->show();
    }
};
