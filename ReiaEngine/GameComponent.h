#pragma once
#include "Vector2.h"

class GameComponent
{
public:
	Vector2 Position;
	Vector2 Scale;

	GameComponent() : Position(0, 0), Scale(1, 1) {}
};

