#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
class Ranking : public Scene {
private:

public:
	Ranking() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};