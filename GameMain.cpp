#include "DDB_Game.h"

int main(int argc, char** argv) {
	DDB_Game game; // initializere instanta joc
	return game.Start(argc, argv); // rulare joc
}