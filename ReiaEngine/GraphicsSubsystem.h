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

	void Update() {}

	int Init(int argc, char** argv) {
		ERROR_LOG("GraphicsSubsystem's Init called!");
		return -1;
	};

	void Start() {}

	void JoinThread() {}

	void SetScreenResolution(VectorI2 NewResolution, bool FullScreen = false, bool WindowedMode = true) {
		ScreenResolution = NewResolution;
		isFullScreen = FullScreen;
		isWindowed = WindowedMode;
	};

	bool IsFullScreen() {
		return isFullScreen;
	}

	void SetWindowTitle(char* NewTitle) {}

protected:
	VectorI2 ScreenResolution;
	bool isFullScreen = false;
	bool isWindowed = false;
};

#ifdef GS_OPENGL
#include "GLSubsystem.h"
#endif