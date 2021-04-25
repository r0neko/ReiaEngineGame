#include "Game.h"

int Game::Run(int argc, char** argv) {
	int ret = Game::Start(argc, argv); // call base startup
	INFO_LOG("Game::Start finished: ret %i\n", ret);
	if (ret != 0) return ret;

	return this->Start(argc, argv);
}

int Game::Start(int argc, char** argv) {
	if (gfxITX != nullptr) {
		WARN_LOG("Game::Start was called, but there is a Graphics Instance already created!\n");
		return 1;
	}

#if _DEBUG
	DEBUG_LOG("ReiaEngine [DEBUG VERSION] - built on %s at %s\n", __DATE__, __TIME__);
#else 
	DEBUG_LOG("ReiaEngine Release - built on %s at %s\n", __DATE__, __TIME__);
#endif

	if (gfxITX == nullptr) {
#ifdef GS_OPENGL
		gfxITX = new GLSubsystem();
#endif
	}

	if (gfxITX->Init(argc, argv) != 0) {
		ERROR_LOG("failed to initialise a graphics subsystem instance\n");
		return -1;
	}

	gfxITX->Start();

	return 0;
}

void Game::Stop() {
	INFO_LOG("Game::Stop called!\n");

	if (gfxITX != nullptr) {
		INFO_LOG("Stopping Graphics Subsystem...\n");
		gfxITX->Stop();
		INFO_LOG("Stopped Graphics Subsystem!\n");
	}
#ifdef _DEBUG
	else {
		WARN_LOG("Game::gfxITX = NULL!\n");
	}
#endif
}