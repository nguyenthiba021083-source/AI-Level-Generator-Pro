#include "AIMenu.hpp"

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

    auto label =
        CCLabelBMFont::create(
            "AI Level Generator PRO",
            "bigFont.fnt"
        );

    label->setPosition(
        winSize.width / 2,
        winSize.height / 2 + 60
    );

    addChild(label);

    return true;
}
