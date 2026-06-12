#include <Geode/Geode.hpp>
#include "AIMenu.hpp"
#include "AISystem.hpp"
using namespace geode::prelude;

AIMenu* AIMenu::create() {
    auto ret = new AIMenu();

    if (ret && ret->init(m_input = TextInput::create(
    220.f,
    "Enter AI Prompt"
);

m_input->setPosition(
    winSize.width / 2,
    winSize.height / 2 + 20
);

addChild(m_input);)) {
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

    // Background
    auto bg = CCLayerColor::create(
        ccc4(0, 0, 0, 180)
    );
    this->addChild(bg);

    // Title
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

void AIMenu::onGenerate(CCObject* sender) {
    log::info("Generate button clicked!");
}

void AIMenu::onClose(CCObject* sender) {
    CCDirector::sharedDirector()->popScene();
void AIMenu::onGenerate(CCObject*) {

    auto prompt =
        m_input->getString();

    AISystem::generate(prompt);

    FLAlertLayer::create(
        "AI",
        "Prompt executed.",
        "OK"
    )->show();
}
