#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
#include "../Enemies/BasicEnemy.h"
class Swatter : public ImageObject, public Player
{
private:
	enum class SwatterState { MOVING, ATTACKING, STUNNED };
	SwatterState currentState;
	
	const float stopThreshold = 5.0f;
	const float movementMultiplyer = 100.0f;
	
	const float maxStunTime = 2.0f;
	float currentStunTime = 0.0f;

	int lifes;
	int score = 0;
	
public:
	Swatter(Vector2 pos, int _lifes) : ImageObject("resources/images/Swatter/Swatter.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "PLAYER"), Player() {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
		lifes = _lifes;
	};
	~Swatter() {};
	void Attack() override;
	void Movement() override;
	void ReceiveDamage() override;
	void Update() override;
	void OnCollisionEnter(Object* other) override;
	inline int GetCurrentLifes() override { return lifes; }
	inline int GetCurrentScore() override { return score; }
};

