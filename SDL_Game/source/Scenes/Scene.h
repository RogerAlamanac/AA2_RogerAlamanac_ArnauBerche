#pragma once
#include "../Object/Object.h"
#include <vector>

class Scene {
protected:
	std::vector<Object> ui;
	std::vector<Object*> _objects;
public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update();
	virtual void Render();
};