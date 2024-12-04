#pragma once
#include "Scene.h"
#include "TimeManager.h"
#include "Spawner.h"

class Gameplay : public Scene {

public:
	Gameplay() = default;
	void OnEnter() override;
	void Update() override;
	void OnExit() override;
	void Render() override;
	void SpawnObjectRandomly();
};