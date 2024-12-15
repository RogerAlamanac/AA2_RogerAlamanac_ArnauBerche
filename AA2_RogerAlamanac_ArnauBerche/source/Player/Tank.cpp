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
		SPAWN.SpawnObject(new Bullet(ImageObject::transform->position - Vector2(0, ImageObject::transform->size.y / 2), Vector2(input.GetMouseX(), input.GetMouseY())));
	}
}

float Tank::DirectionToAim() {
    InputManager& input = IM;

	float directionX = input.GetMouseX() - transform->position.x;
	float directionY = input.GetMouseY() - transform->position.y;
	float angle = atan2(directionY, directionX) * 180.0f;
	transform->rotation = angle;
    return transform->rotation;
}

void Tank::Update()
{
    Object::Update();
    Movement();
	Attack();
}
