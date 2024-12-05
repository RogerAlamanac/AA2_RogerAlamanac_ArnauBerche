#pragma once
#include<SDL.h>;
#include "../Object/Object.h"
#include "../Scenes/Scene.h"
class Game
{

public:
	Game() = default;
	void Init();
	void Update();
	void Render();
	void Release();

};

