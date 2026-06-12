#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class AIMenu : public CCLayer {
protected:
    TextInput* m_input;

public:
    static AIMenu* create();

    bool init() override;

    void onGenerate(CCObject*);
    void onClose(CCObject*);
};
