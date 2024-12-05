#pragma once
#include "Enemy.h"
class SeekerEnemy : public Enemy
{
public:
	SeekerEnemy();
	~SeekerEnemy();
	void Movement() override;
};

