#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class AIMenu : public CCLayer {
protected:
    bool init() override;

public:
    static AIMenu* create();
};
