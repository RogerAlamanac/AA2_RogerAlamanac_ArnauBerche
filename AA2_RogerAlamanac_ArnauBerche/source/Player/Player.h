#pragma once
#include "../Object/Object.h"

class Player : public Object {
private:
	int health;
public:
	Player() = default;
	virtual void Movement() = 0;
	virtual void Attack() = 0;
};