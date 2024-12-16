#pragma once
#include "Scene.h"
#include "../Player/Player.h"
#include "../Player/Spaceship.h"
#include "../Player/Tank.h"
#include "../Player/Swatter.h"
class Gameplay : public Scene {
private:
	int game;
	bool enemySpawned = false;
	Player* player;
public:
	Gameplay(int type) : game(type) {
		switch (type) {
		case 0: player = new Spaceship(Vector2(100, 700));
			break;
		case 1: player = new Tank(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), 100);
			break;
		case 2: player = new Swatter(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2));
			break;
		}
	};
	void OnEnter() override;
	void Update() override;
	void OnExit() override;
	void Render() override;
	void SpawnObjectRandomly();
};