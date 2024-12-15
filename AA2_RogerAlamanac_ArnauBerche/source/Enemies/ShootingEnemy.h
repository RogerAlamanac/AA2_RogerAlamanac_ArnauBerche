#pragma once
#include "Enemy.h"
class ShootingEnemy : public Enemy
{
private:
	float timeToShoot;
	float currentTime;
public:
	ShootingEnemy();
	~ShootingEnemy();
	void BaseMovement() override;
	void Shoot();
};

