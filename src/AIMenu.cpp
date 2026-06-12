#include "AIMenu.hpp"
#include "AISystem.hpp"

#include <Geode/Geode.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

AIMenu* AIMenu::create() {
    auto ret = new AIMenu();

    if (ret && ret->initAnchored(300.f, 220.f)) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool AIMenu::setup() {
    this->setTitle("AI Level Generator PRO");

    m_input = TextInput::create(
        220.f,
        "Enter AI Prompt"
    );

    m_input->setPosition(
        ccp(
            m_size.width / 2,
            m_size.height / 2 + 20.f
        )
    );

    m_mainLayer->addChild(m_input);

    auto generateLabel =
        CCLabelBMFont::create(
            "Generate",
            "goldFont.fnt"
        );

    auto generateBtn =
        CCMenuItemSpriteExtra::create(
            generateLabel,
            this,
            menu_selector(AIMenu::onGenerate)
        );

    generateBtn->setPosition(
        ccp(
            m_size.width / 2,
            m_size.height / 2 - 20.f
        )
    );

    m_buttonMenu->addChild(generateBtn);

    auto closeLabel =
        CCLabelBMFont::create(
            "Close",
            "goldFont.fnt"
        );

    auto closeBtn =
        CCMenuItemSpriteExtra::create(
            closeLabel,
            this,
            menu_selector(AIMenu::onClose)
        );

    closeBtn->setPosition(
        ccp(
            m_size.width / 2,
            m_size.height / 2 - 60.f
        )
    );

    m_buttonMenu->addChild(closeBtn);

    return true;
}

void AIMenu::onGenerate(CCObject*) {
    std::string prompt = m_input->getString();

    if (prompt.empty()) {
        FLAlertLayer::create(
            "AI",
            "Please enter a prompt.",
            "OK"
        )->show();

        return;
    }

    AISystem::generate(prompt);

    FLAlertLayer::create(
        "AI",
        "Prompt executed.",
        "OK"
    )->show();
}

void AIMenu::onClose(CCObject*) {
    Popup<>::onClose(nullptr);
}
