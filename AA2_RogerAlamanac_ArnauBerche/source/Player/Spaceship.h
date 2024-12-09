#pragma once
#include "Player.h"
class Spaceship : public Player
{
public:
	Spaceship();
	~Spaceship();
	void Movement() override;
	void Attack() override;
};

