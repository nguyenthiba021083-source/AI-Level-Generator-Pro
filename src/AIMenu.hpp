#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class AIMenu : public CCLayer {
public:
    static AIMenu* create();

    bool init() override;

    void onGenerate(CCObject* sender);
    void onClose(CCObject* sender);
};
