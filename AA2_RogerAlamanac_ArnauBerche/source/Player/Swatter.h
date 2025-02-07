#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
#include "../Enemies/BasicEnemy.h"
class Swatter : public ImageObject, public Player
{
private:
	enum class SwatterState { MOVING, ATTACKING, STUNNED };
	SwatterState currentState = SwatterState::MOVING;

	bool enemyhit = false;
	float stateStartTime = 0.0f;

	float attackCooldown = 0.5f;
	float lastAttackTime = -attackCooldown;

	float DMGCooldown = 1.0f;
	float timeSinceDMG;

	int lifes = 3;
	int score = 0;

	
public:
	Swatter(Vector2 pos, int _lifes) : ImageObject("resources/images/Swater/Player/Swatter.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "PLAYER"), Player() {
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

