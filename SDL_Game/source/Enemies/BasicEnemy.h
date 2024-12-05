#pragma once
#include "Enemy.h"
class BasicEnemy : public Enemy
{
public:
	BasicEnemy();
	~BasicEnemy();
	void Movement() override;
};

