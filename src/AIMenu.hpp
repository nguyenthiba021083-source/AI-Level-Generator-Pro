#pragma once

#include <Geode/Geode.hpp>
#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class AIMenu : public CCLayer {
protected:
    TextInput* m_input = nullptr;

public:
    static AIMenu* create();

    bool init() override;

    void onGenerate(CCObject*);
    void onClose(CCObject*);
};
