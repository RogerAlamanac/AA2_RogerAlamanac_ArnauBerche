#pragma once
#include "Scene.h"

class GameplayTanks : public Scene {
private:
	bool enemySpawned = false;
	int amountEnemies = 20;
public:
	GameplayTanks() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};