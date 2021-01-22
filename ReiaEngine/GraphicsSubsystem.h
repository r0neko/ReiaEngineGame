#pragma once

#ifndef GS_OPENGL
#error ReiaEngine couldn't be compiled, because there are no graphics subsystems defined! Please compile ReiaEngine with GS_OPENGL(for OpenGL Subsystem).
#endif

#include "VectorI2.h"
#include "cLogger.h"

class GraphicsSubsystem
{
public:
	GraphicsSubsystem() : ScreenResolution(800, 600) {}

	void Update();
	int Init(int argc, char** argv) {
		ERROR_LOG("GraphicsSubsystem's Init called!");
		return -1;
	};

	void SetScreenResolution(VectorI2 NewResolution, bool FullScreen = false) {
		ScreenResolution = NewResolution;
		isFullScreen = FullScreen;
	};

	bool IsFullScreen() {
		return isFullScreen;
	}

	void SetWindowTitle(char* NewTitle);

private:
	VectorI2 ScreenResolution;
	bool isFullScreen = false;
};

#ifdef GS_OPENGL
#include "GLSubsystem.h"
#endif