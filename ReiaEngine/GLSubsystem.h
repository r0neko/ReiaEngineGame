#pragma once
#include "GraphicsSubsystem.h"
#include "cLogger.h"

class GLSubsystem :
    public GraphicsSubsystem
{
public:
    int Init(int argc, char** argv) {
        INFO_LOG("GLSubsystem says HI!");
        return 0;
    }
};

