#pragma once
#include "ReiaEngine/Scene.h"
#include "ReiaEngine/UI.h"

class MainScene : public Scene
{
public:
    MainScene() {
        points.Anchor = TOP_LEFT;

        points.Position.X = 10;
        points.Position.Y = 10;

        Renderer.AddObject(&points);
    }
private:
    Text points;
};

