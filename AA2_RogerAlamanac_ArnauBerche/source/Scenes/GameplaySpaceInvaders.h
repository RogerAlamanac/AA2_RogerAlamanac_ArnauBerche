#pragma once
#include "Scene.h"
#include "../UI/Score.h"

class GameplaySpaceInvaders : public Scene {
private:
	bool enemySpawned = false;
	int amountEnemies = 20;
	int currentScore = 0;
	Score* score;
	TextObject* score1;
public:
	GameplaySpaceInvaders() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};