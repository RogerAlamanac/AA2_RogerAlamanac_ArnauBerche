#pragma once
#include "Player.h"
class Swatter : public Player
{
	Swatter();
	~Swatter();
	void Movement() override;
	void Attack() override;
};

