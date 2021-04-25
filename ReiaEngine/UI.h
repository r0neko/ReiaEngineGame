#pragma once
#include "Vector2.h"

enum Anchor {
	NONE,
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT,
	CENTER_LEFT,
	CENTER,
	CENTER_RIGHT
};

class UISprite {
public:
	int zIndex = 0;
	Vector2 Position;
	Vector2 Size;
	Anchor Anchor;
	virtual void Render();
};

#include "Text.h"