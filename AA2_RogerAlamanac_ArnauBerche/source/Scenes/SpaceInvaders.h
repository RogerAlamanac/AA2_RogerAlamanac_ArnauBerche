#pragma once
#include "Gameplay.h"
class SpaceInvaders : public Gameplay
{
private:
	bool enemySpawned = false;
public:
	SpaceInvaders() = default;
	void OnEnter() override;
	void Update() override;
	void OnExit() override;
	void Render() override;
	void SpawnObjectRandomly();
};

