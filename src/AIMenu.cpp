#include "AIMenu.hpp"
#include "AISystem.hpp"

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

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto bg = CCLayerColor::create(ccc4(0, 0, 0, 180));
    this->addChild(bg);

    auto title = CCLabelBMFont::create(
        "AI Level Generator PRO",
        "bigFont.fnt"
    );

    title->setPosition(
        ccp(winSize.width / 2, winSize.height / 2 + 100)
    );

    this->addChild(title);

    m_input = TextInput::create(
        220.f,
        "Enter AI Prompt"
    );

    m_input->setPosition(
        ccp(winSize.width / 2, winSize.height / 2 + 40)
    );

    this->addChild(m_input);

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

    generateBtn->setPosition(ccp(0, 20));
    closeBtn->setPosition(ccp(0, -20));

    menu->setPosition(
        ccp(
            winSize.width / 2,
            winSize.height / 2 - 40
        )
    );

    this->addChild(menu);

    return true;
}

void AIMenu::onGenerate(CCObject*) {
    std::string prompt = m_input->getString();

    AISystem::generate(prompt);

    FLAlertLayer::create(
        "AI",
        "Prompt executed.",
        "OK"
    )->show();
}

void AIMenu::onClose(CCObject*) {
    CCDirector::sharedDirector()->popScene();
}
