#pragma once
#include "Scene.h"
#include "../Player/Player.h"
class Gameplay : public Scene {
private:
	int game;
	bool enemySpawned = false;
public:
	Gameplay(int type) : game(type) {};
	void OnEnter() override;
	void Update() override;
	void OnExit() override;
	void Render() override;
	void SpawnObjectRandomly();
};