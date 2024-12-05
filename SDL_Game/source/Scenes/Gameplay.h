#pragma once
#include "Scene.h"
#include "../InputManager/TimeManager.h"
#include "../Spawner/Spawner.h"

class Gameplay : public Scene {

public:
	Gameplay() = default;
	void OnEnter() override;
	void Update() override;
	void OnExit() override;
	void Render() override;
	void SpawnObjectRandomly();
};