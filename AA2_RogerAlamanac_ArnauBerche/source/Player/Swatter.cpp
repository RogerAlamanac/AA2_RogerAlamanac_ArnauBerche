#include "Swatter.h"
#include "../InputManager/InputManager.h"
#include <iostream>

void Swatter::Update() {
	
	switch (currentState) {
	case SwatterState::MOVING:
		std::cout << "IsMoving" << std::endl;
		if (IM.GetLeftClick()) {
			currentState = SwatterState::ATTACKING;
			stateStartTime = (float)TIME.GetElapsedTime();
		}
		else {
			Movement();
		}
		break;

	case SwatterState::ATTACKING:
		std::cout << "IsAttacking" << std::endl;
		break;

	case SwatterState::STUNNED:
		std::cout << "IsStunned" << std::endl;
		if (TIME.GetElapsedTime() - stateStartTime >= 2.0f) {
			currentState = SwatterState::MOVING;
		}
		break;
	}

	Object::Update();
}

void Swatter::Attack()
{
}

void Swatter::Movement() {
	int mouseX = IM.GetMouseX();
	int mouseY = IM.GetMouseY();
	Vector2 mousePosition = Vector2((float)mouseX, (float)mouseY);

	Vector2 direction = mousePosition - transform->position;

	float distanceSquared = direction.x * direction.x + direction.y * direction.y;

	if (distanceSquared < 1.0f) {
		return;
	}

	direction.Normalize();

	float maxSpeed = 1000.0f;
	float deltaTime = (float)TIME.GetDeltaTime();
	Vector2 velocity = direction * maxSpeed * deltaTime;

	if (velocity.x * velocity.x + velocity.y * velocity.y > distanceSquared) {
		transform->position = mousePosition;
	}
	else {
		transform->position = transform->position + velocity;
	}
}

void Swatter::ReceiveDamage()
{
}

void Swatter::OnCollisionEnter(Object* other) {
	if (other->tag == "ENEMY") {
		if (currentState == SwatterState::ATTACKING) {
			other->Destroy();
		}
		else if (currentState == SwatterState::STUNNED) {
			lives--;
		}
	}
	else {
		if (currentState == SwatterState::ATTACKING)
		{
			currentState = SwatterState::STUNNED;
		}
	}
}