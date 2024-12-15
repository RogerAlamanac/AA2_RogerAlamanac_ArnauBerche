#include "Tank.h"
#include "../InputManager/InputManager.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"

void Tank::Movement()
{
	ImageObject::physics->SetVelocity(DirectionToVector(currentDirection) * movementSpeed);
    InputManager& input = IM;

	//Check Diagonal
	if ((input.GetEvent(SDLK_a, DOWN) && input.GetEvent(SDLK_w, DOWN))
		|| (input.GetEvent(SDLK_a, HOLD) && input.GetEvent(SDLK_w, HOLD))) {
		currentDirection = PlayerDirections::UPERLEFT;
		ImageObject::transform->rotation = -45.f;
		return;
	}
	if ((input.GetEvent(SDLK_d, DOWN) && input.GetEvent(SDLK_w, DOWN))
		|| (input.GetEvent(SDLK_d, HOLD) && input.GetEvent(SDLK_w, HOLD))) {
		currentDirection = PlayerDirections::UPERRIGHT;
		ImageObject::transform->rotation = 45.f;
		return;
	}
	if ((input.GetEvent(SDLK_d, DOWN) && input.GetEvent(SDLK_s, DOWN))
		|| (input.GetEvent(SDLK_d, HOLD) && input.GetEvent(SDLK_s, HOLD))) {
		currentDirection = PlayerDirections::DOWNRIGHT;
		ImageObject::transform->rotation = 135.f;
		return;
	}
	if ((input.GetEvent(SDLK_a, DOWN) && input.GetEvent(SDLK_s, DOWN))
		|| (input.GetEvent(SDLK_a, HOLD) && input.GetEvent(SDLK_s, HOLD))) {
		currentDirection = PlayerDirections::DOWNLEFT;
		ImageObject::transform->rotation = -135.f;
		return;
	}

	//Chack Noraml
    if (input.GetEvent(SDLK_a, DOWN) || input.GetEvent(SDLK_a, HOLD)) {
        currentDirection = PlayerDirections::LEFT;
        ImageObject::transform->rotation = -90.f;
        return;
    }
    if (input.GetEvent(SDLK_w, DOWN) || input.GetEvent(SDLK_w, HOLD)) {
		currentDirection = PlayerDirections::UP;
        ImageObject::transform->rotation = 0.f;
		return;
    }
    if (input.GetEvent(SDLK_d, DOWN) || input.GetEvent(SDLK_d, HOLD)) {
		currentDirection = PlayerDirections::RIGHT;
        ImageObject::transform->rotation = 90.f;
		return;
    }
    if (input.GetEvent(SDLK_s, DOWN) || input.GetEvent(SDLK_s, HOLD)) {
		currentDirection = PlayerDirections::DOWN;
        ImageObject::transform->rotation = 180.f;
		return;
    }

	currentDirection = PlayerDirections::NONE;
}


void Tank::Attack()
{
	InputManager& input = IM;
	if (input.GetLeftClick()) {
		//Math to make the bullet spawn at the tip of the canon
		Vector2 playerPosition = ImageObject::transform->position;

		float rotationAngle = ImageObject::transform->rotation; // Needs to be swaped by Canon later;
		float radians = rotationAngle * (M_PI / 180.0f);

		Vector2 relativeOffset(0, -ImageObject::transform->size.y / 2);

		Vector2 rotatedOffset(
			relativeOffset.x * cos(radians) - relativeOffset.y * sin(radians),
			relativeOffset.x * sin(radians) + relativeOffset.y * cos(radians)
		);
		Vector2 bulletSpawnPosition = playerPosition + rotatedOffset;

		// Spawn the bullet
		SPAWN.SpawnObject(new Bullet(bulletSpawnPosition, 500, DirectionToAim(relativeOffset)));
	}
}

Vector2 Tank::DirectionToAim(Vector2 relativeOffset) {
	InputManager& input = IM;
	Vector2 adjustedPosition = transform->position + relativeOffset;
	Vector2 direction;

	// Calculate direction to the mouse
	direction.x = input.GetMouseX() - adjustedPosition.x;
	direction.y = input.GetMouseY() - adjustedPosition.y;

	// Normalize the direction vector
	direction.Normalize();
	return direction;
}

void Tank::Update()
{
    Object::Update();
    Movement();
	Attack();
}
