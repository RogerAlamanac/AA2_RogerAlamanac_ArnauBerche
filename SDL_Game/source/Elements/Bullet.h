#pragma once
#include "../Object/Object.h"
class Bullet : public Object //CLASE ELEMENTS NO FA FALTA
{
private:
	float timeToLive;
	int damage;
public:
	Bullet();
	~Bullet();
	void Update() override;
};

