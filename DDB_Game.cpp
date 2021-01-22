#include "DDB_Game.h"

int DDB_Game::Start(int argc, char** argv) {
	int ret = Game::Start(argc, argv); // call base startup
	INFO_LOG("Game::Start finished: ret %i\n", ret);
	if (ret != 0) return ret;

	SetWindowTitle((char*) "Bubble Destroyer - ReiaEngine");
	SetScreenResolution(VectorI2(1920, 1080));

	JoinGFXThread();

	return 0;
}