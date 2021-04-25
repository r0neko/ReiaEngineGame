#pragma once
#include "ReiaEngine/Game.h"

class DDB_Game: public Game
{
public:
    virtual int Start(int argc, char** argv);
};

extern DDB_Game GameInstance;