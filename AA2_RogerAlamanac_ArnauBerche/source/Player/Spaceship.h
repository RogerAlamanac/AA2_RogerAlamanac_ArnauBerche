#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
class Spaceship : public Player, ImageObject
{
public:
	Spaceship(Vector2 pos, Vector2 startVelocity) : ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(384.f, 96.f), 1) {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
		ImageObject::physics->AddForce(startVelocity);
	}
	~Spaceship();
	void Movement() override;
	void Attack() override;
};

