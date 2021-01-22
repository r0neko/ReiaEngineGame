#include "Game.h"

int Game::Start(int argc, char** argv) {
	if (gfxITX != nullptr) {
		WARN_LOG("Game::Start was called, but there is a Graphics Instance already created!");
		return 1;
	}

	INFO_LOG("ReiaEngine - built on %s at %s\n", __DATE__, __TIME__);

	if (gfxITX == nullptr) {
#ifdef GS_OPENGL
		gfxITX = new GLSubsystem();
#endif
	}

	if (gfxITX->Init(argc, argv) != 0) {
		ERROR_LOG("failed to initialise a graphics subsystem instance");
		return -1;
	}

	gfxITX->Start();

	return 0;
}