#pragma once
#include<SDL.h>;
#include "Object.h"
#include "Scene.h"
class Game
{

public:
	Game() = default;
	void Init();
	void Update();
	void Render();
	void Release();

};

