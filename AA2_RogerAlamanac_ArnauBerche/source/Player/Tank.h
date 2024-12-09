#pragma once
#include "Player.h"
class Tank : public Player
{
public:
	Tank();
	~Tank();
	void Movement() override;
	void Attack() override;
};

