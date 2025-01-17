#include "Swatter.h"
#include "../InputManager/InputManager.h"
#include <iostream>

void Swatter::Update() {
	
	switch (currentState) {
	case SwatterState::MOVING:
		std::cout << "IsMoving" << std::endl;
		if (IM.GetLeftClick()) {
			currentState = SwatterState::ATTACKING;
			stateStartTime = TIME.GetElapsedTime();
		}
		else {
			Movement();
		}
		break;

	case SwatterState::ATTACKING:
		std::cout << "IsAttacking" << std::endl;
		currentState = SwatterState::STUNNED;
		stateStartTime = TIME.GetElapsedTime();
		break;

	case SwatterState::STUNNED:
		std::cout << "IsStunned" << std::endl;
		std::cout << TIME.GetElapsedTime() << std::endl;
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
	float mouseX = IM.GetMouseX();
	float mouseY = IM.GetMouseY();
	Vector2 mousePosition = Vector2(mouseX, mouseY);

	Vector2 direction = mousePosition - transform->position;

	float distanceSquared = direction.x * direction.x + direction.y * direction.y;

	if (distanceSquared < 1.0f) {
		return;
	}

	direction.Normalize();

	float maxSpeed = 1000.0f;
	float deltaTime = TIME.GetDeltaTime();
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
	if (currentState == SwatterState::MOVING) { return; }
	
	if (currentState == SwatterState::ATTACKING) {
		currentState = SwatterState::MOVING;
		if (other->tag == "ENEMY") {
			std::cout << "DestroyNow" << std::endl;
			other->Destroy();
		}
		else if (other->tag == "BG") {
			std::cout << "BG" << std::endl;
			currentState = SwatterState::STUNNED;
		}
	}
	else if (currentState == SwatterState::STUNNED) {
		lives--;
	}



	// if (Bullet* bullet = dynamic_cast<Bullet*>(other)) {
	// 	if (!bullet->IsFriendly()) {
	// 		lives--;
	// 	}
	// }
}