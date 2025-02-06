#include "Swatter.h"
#include "../InputManager/InputManager.h"
#include <iostream>

void Swatter::Update() {
    Object::Update();

    float currentTime = (float)TIME.GetElapsedTime();

    switch (currentState) {
    case SwatterState::MOVING:
        std::cout << "IsMoving" << std::endl;

        if (IM.GetLeftClick() && currentTime - lastAttackTime >= attackCooldown) {
            currentState = SwatterState::ATTACKING;
            enemyhit = false;
            lastAttackTime = currentTime;
        }
        else {
            Movement();
        }
        break;

    case SwatterState::ATTACKING:
        std::cout << "IsAttacking" << std::endl;
        Attack();

        if (enemyhit) {
            currentState = SwatterState::MOVING;
        }
        else {
            currentState = SwatterState::STUNNED;
            stateStartTime = currentTime;
            std::cout << "No enemy hit! Swatter is stunned." << std::endl;
        }
        break;

    case SwatterState::STUNNED:
        std::cout << "IsStunned" << std::endl;
        if (currentTime - stateStartTime >= 2.0f) {
            std::cout << "Recovered from stun!" << std::endl;
            currentState = SwatterState::MOVING;
        }
        break;
    }
}


void Swatter::Attack() {

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
	if (other->tag == "ENEMY" && currentState == SwatterState::ATTACKING) {
		other->Destroy();
		enemyhit = true;
		std::cout << "Enemy hit during attack!" << std::endl;
	}
}