#pragma once
#include "Enemy.h"
class ExplodingEnemy : public Enemy 
{
public:
	ExplodingEnemy();
	~ExplodingEnemy();
	void BaseMovement() override;
};

