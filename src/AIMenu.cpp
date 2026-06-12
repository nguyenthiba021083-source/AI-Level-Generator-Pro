#include <Geode/Geode.hpp>
#include "AIMenu.hpp"

using namespace geode::prelude;

AIMenu* AIMenu::create() {
    auto ret = new AIMenu();

    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool AIMenu::init() {
    if (!CCLayer::init())
        return false;

    auto winSize =
        CCDirector::sharedDirector()->getWinSize();

    // Background tối
    auto bg = CCLayerColor::create(
        ccc4(0, 0, 0, 180)
    );
    this->addChild(bg);

    // Tiêu đề
    auto title =
        CCLabelBMFont::create(
            "AI Level Generator PRO",
            "bigFont.fnt"
        );

    title->setPosition(
        winSize.width / 2,
        winSize.height / 2 + 80
    );

    this->addChild(title);

    // Generate Button
    auto generateLabel =
        CCLabelBMFont::create(
            "Generate",
            "goldFont.fnt"
        );

    auto generateBtn =
        CCMenuItemLabel::create(
            generateLabel,
            this,
            menu_selector(AIMenu::onGenerate)
        );

    // Close Button
    auto closeLabel =
        CCLabelBMFont::create(
            "Close",
            "goldFont.fnt"
        );

    auto closeBtn =
        CCMenuItemLabel::create(
            closeLabel,
            this,
            menu_selector(AIMenu::onClose)
        );

    auto menu = CCMenu::create();
    menu->addChild(generateBtn);
    menu->addChild(closeBtn);

    generateBtn->setPosition(
        ccp(0, 20)
    );

    closeBtn->setPosition(
        ccp(0, -20)
    );

    menu->setPosition(
        ccp(
            winSize.width / 2,
            winSize.height / 2
        )
    );

    this->addChild(menu);

    return true;
}

void AIMenu::onGenerate(CCObject*) {
    FLAlertLayer::create(
        "AI Generator",
        "Generate button clicked!",
        "OK"
    )->show();
}

void AIMenu::onClose(CCObject*) {
    CCDirector::sharedDirector()->popScene();
}
