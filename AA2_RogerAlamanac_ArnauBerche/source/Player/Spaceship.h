#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
#include "../Elements/Bullet.h"
class Spaceship : public ImageObject, public Player
{
private:
	int lifes;
	int score = 0;
public:
	
	float fireCooldown = 1.f;
	float timeSinceLastFire = 0.f;
	float timeToStartHolding = 0.2f;

	Spaceship(Vector2 pos, int _lifes) : ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "PLAYER"), Player() {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);

		lifes = _lifes;
	}
	~Spaceship();
	void Movement() override;
	void Attack() override;
	void ReceiveDamage() override;
	void Update() override;
	inline int GetCurrentLifes() override { return lifes; }
	inline int GetCurrentScore() override { return score; }
};

