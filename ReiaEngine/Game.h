#pragma once

#ifndef GAME_H
#define GAME_H

#include "GraphicsSubsystem.h"
#include "cLogger.h"

class Game
{
public:
	GraphicsSubsystem* gfxITX = nullptr;

	int Run(int argc, char** argv);

	virtual int Start(int argc, char** argv);
	void Stop();

	void SetWindowTitle(char* title) {
		gfxITX->SetWindowTitle(title);
	}

	void SetScreenResolution(VectorI2 NewResolution, bool FullScreen = false, bool WindowedMode = true) {
		gfxITX->SetScreenResolution(NewResolution, FullScreen, WindowedMode);
	}

	void StartGameLoop() {
		while (gfxITX->Available()) {
			gfxITX->ProcessFrame();
		}
	}
};

#endif