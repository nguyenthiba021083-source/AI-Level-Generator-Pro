#pragma once

#include <Geode/ui/Popup.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class AIMenu : public Popup<> {
protected:
    TextInput* m_input;

    bool setup() override;

public:
    static AIMenu* create();

    void onGenerate(CCObject*);
    void onClose(CCObject*);
};
