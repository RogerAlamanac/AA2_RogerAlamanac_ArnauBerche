#pragma once
#include "../Object/Object.h"
class Explosion : public Object
{
private:
	Vector2 rangeToPush;
public:
	Explosion();
	~Explosion();
	void Update() override;
	void PushElement(Vector2 forceToAdd, Object* target);
};

