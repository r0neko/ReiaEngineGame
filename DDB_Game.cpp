#include "DDB_Game.h"

int DDB_Game::Start(int argc, char** argv) {
	DEBUG_LOG("DDB_Game::Start\n");

	SetWindowTitle((char*) "Distrugatorul de Bule");
	SetScreenResolution(VectorI2(800, 600), false, true);

	//SceneManager.LoadScene(MainMenuScene);

	StartGameLoop();

	Game::Stop();

	return 0;
}