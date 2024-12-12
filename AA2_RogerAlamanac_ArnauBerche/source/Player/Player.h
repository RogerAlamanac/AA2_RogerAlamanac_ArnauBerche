#pragma once
#include "../Object/Object.h"

class Player {
private:
	int health;
public:
	Player() = default;
	virtual void Movement() = 0;
	virtual void Attack() = 0;
};