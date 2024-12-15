#pragma once
#include "Enemy.h"
class AimingEnemy : public Enemy
{
private:
	float timeToStopMoving;
	float timeStopped;
public:
	AimingEnemy();
	~AimingEnemy();
	void BaseMovement() override;
	void Shoot();
};

