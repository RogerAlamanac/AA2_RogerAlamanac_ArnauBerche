#pragma once
#include "../Object/Object.h"
#include "../Player/Player.h"
#include <vector>
#include <string>


#define MAX_LIFES 3
class Scene {
protected:
	Player* player;
	std::vector<Object> ui;
	std::vector<Object*> _objects;

	bool needsDefault = true;

public:
	std::vector<std::vector<std::string>> imagesToUse;
	int currentScene = 0;

public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update();
	virtual void Render();

	void ClearITU();
};