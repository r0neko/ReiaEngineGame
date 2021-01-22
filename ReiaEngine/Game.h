#pragma once

#ifndef GAME_H
#define GAME_H

#include "GraphicsSubsystem.h"
#include "cLogger.h"

class Game
{
public:
	int Start(int argc, char** argv);
private:
#ifdef GS_OPENGL
	GLSubsystem* gfx_ss_itx = nullptr;
#else
	GraphicsSubsystem* gfx_ss_itx = nullptr;
#endif
};

#endif