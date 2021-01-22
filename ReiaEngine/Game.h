#pragma once

#ifndef GAME_H
#define GAME_H

#include "GraphicsSubsystem.h"
#include "cLogger.h"

class Game
{
public:
	int Start(int argc, char** argv);

	void SetWindowTitle(char* title) {
		gfxITX->SetWindowTitle(title);
	}

	void SetScreenResolution(VectorI2 NewResolution, bool FullScreen = false, bool WindowedMode = true) {
		gfxITX->SetScreenResolution(NewResolution, FullScreen, WindowedMode);
	}

	void JoinGFXThread() {
		gfxITX->JoinThread();
	}
private:
#ifdef GS_OPENGL
	GLSubsystem* gfxITX = nullptr;
#else
	GraphicsSubsystem* gfxITX = nullptr;
#endif
};

#endif