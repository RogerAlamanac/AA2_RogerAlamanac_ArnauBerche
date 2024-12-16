#pragma once
#include "Scene.h"

class GameplaySplat : public Scene {
private:
	bool enemySpawned = false;
	int amountEnemies = 20;
public:
	GameplaySplat() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;

};