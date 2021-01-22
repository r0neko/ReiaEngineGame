#include "DDB_Game.h"

int DDB_Game::Start(int argc, char** argv) {
	int ret = Game::Start(argc, argv); // call base startup
	if (ret != 0) return ret;

	INFO_LOG("wow i'm in DDB GAME!");

	return 0;
}