#pragma once
#include "../Object/Object.h"

class Enemy : public Object {
private:
	int health;
	int damage;
	std::string pathPattern;
public:
	Enemy(int _health, int _damage) : health(_health), damage(_damage), 
		Object(" ", Vector2(0.f, 0.f), Vector2(1.f, 1.f), 0) {}
	virtual void Movement() = 0;
	void Update() override;
};