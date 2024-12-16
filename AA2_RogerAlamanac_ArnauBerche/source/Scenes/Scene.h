#pragma once
#include "../Object/Object.h"
#include "../Player/Player.h"
#include <vector>

class Scene {
protected:
	Player* player;
	std::vector<Object> ui;
	std::vector<Object*> _objects;
public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update();
	virtual void Render();
};