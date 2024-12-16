#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
#include "../Enemies/BasicEnemy.h"
class Swatter : public ImageObject, public Player
{
private:
	float currentTime;
	float stuckTime;
	const float maxVelocity = 200.0f;
	bool isStuck = false;
public:
	Swatter(Vector2 pos) : ImageObject("resources/Swatter.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "PLAYER"), Player() {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
		stuckTime = 0;
		currentTime = 0;
	};
	~Swatter() {};
	Vector2 DirectionToAim(Vector2 relativeOffset);
	void Movement() override;
	void Attack() override;
	bool IsFlyHit();
	void ReceiveDamage() override;
	void Update() override;
	bool CheckCollision(const Vector2& swatterPos, const Vector2& targetPos, float size);
};

