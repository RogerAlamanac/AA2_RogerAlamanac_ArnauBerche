#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
class Tank : public ImageObject,  Player
{
private:
	PlayerDirections currentDirection;
	float movementSpeed;
public:
	Tank(Vector2 pos, float velocity) : ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(384.f, 96.f), 0), Player() {
		currentDirection = PlayerDirections::NONE;
		movementSpeed = velocity;
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
	}
	~Tank();
	void Movement() override;
	float DirectionToAim();
	void Attack() override;
	void Update() override;
};

