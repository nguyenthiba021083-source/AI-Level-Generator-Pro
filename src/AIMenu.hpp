#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class AIMenu : public CCLayer {
protected:
    bool init() override;

    void onGenerate(CCObject*);
    void onClose(CCObject*);

public:
    static AIMenu* create();
};
