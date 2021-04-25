#pragma once
#include "UI.h"
#include <vector>

class SceneRenderer {
public:
	void AddObject(UISprite* obj) {
		Sprites.push_back(obj);
	}

	void Render() {
		for (int i = 0; i < Sprites.size(); i++) {
			Sprites[i]->Render();
		}
	}
private:
	vector<UISprite*> Sprites;
};