#pragma once
#include "Scene.h"

class GameplaySpaceInvaders : public Scene {
private:
	bool enemySpawned = false;
	int amountEnemies = 20;

public:
	GameplaySpaceInvaders() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};