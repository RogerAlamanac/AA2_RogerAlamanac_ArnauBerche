#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
class Spaceship : public ImageObject, public Player
{
public:
	float fireCooldown = 1.f;
	float timeSinceLastFire = 0.f;

	Spaceship(Vector2 pos) : ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "PLAYER"), Player() {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
	}
	~Spaceship();
	void Movement() override;
	void Attack() override;
	void ReceiveDamage() override;
	void Update() override;
};

