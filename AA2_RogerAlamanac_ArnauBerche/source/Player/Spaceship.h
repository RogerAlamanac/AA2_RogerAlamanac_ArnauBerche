#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
class Spaceship : public ImageObject, Player
{
public:
	Spaceship(Vector2 pos) : ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(384.f, 96.f), 0) {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
	}
	~Spaceship();
	void Movement() override;
	void Attack() override;
	void Update() override;
};

