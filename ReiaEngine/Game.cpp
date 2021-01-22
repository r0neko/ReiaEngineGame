#include "Game.h"

int Game::Start(int argc, char** argv) {
	if (gfx_ss_itx != nullptr) {
		WARN_LOG("Game::Start was called, but there is a Graphics Instance already created!");
		return 1;
	}

	INFO_LOG("ReiaEngine - built on %s at %s\n", __DATE__, __TIME__);

	if (gfx_ss_itx == nullptr) {
#ifdef GS_OPENGL
		gfx_ss_itx = new GLSubsystem();
#endif
	}

	if (gfx_ss_itx->Init(argc, argv) != 0) {
		ERROR_LOG("failed to initialise a graphics subsystem instance");
		return -1;
	}

	return 0;
}