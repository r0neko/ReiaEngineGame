#include "DDB_Game.h"

DDB_Game GameInstance; // init the game instance, cuz we defined a global variable of the game instance in DDB_Game.h

int main(int argc, char** argv) {
	return GameInstance.Run(argc, argv); // we can run the game now!
}