#include "Tank.h"
#include "../InputManager/InputManager.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"

void Tank::Movement()
{
	ImageObject::physics->SetVelocity(DirectionToVector(body->currentDirection) * movementSpeed);
    InputManager& input = IM;

	if (ImageObject::transform->position.x < 0 - transform->size.x) {
		ImageObject::transform->position.x = RM->WINDOW_WIDTH + transform->size.x / 2;
	}
	else if (ImageObject::transform->position.x > RM->WINDOW_WIDTH + transform->size.x) {
		ImageObject::transform->position.x = 0 - transform->size.x / 2;
	}

	if (ImageObject::transform->position.y < 0 - transform->size.y) {
		ImageObject::transform->position.y = RM->WINDOW_HEIGHT + transform->size.y / 2;
	}
	else if (ImageObject::transform->position.y > RM->WINDOW_HEIGHT + transform->size.y) {
		ImageObject::transform->position.y = 0 - transform->size.y / 2;
	}

	//Check Diagonal
	if ((input.GetEvent(SDLK_a, DOWN) && input.GetEvent(SDLK_w, DOWN))
		|| (input.GetEvent(SDLK_a, HOLD) && input.GetEvent(SDLK_w, HOLD))) {
		body->currentDirection = PlayerDirections::UPERLEFT;
		ImageObject::transform->rotation = -45.f;
		return;
	}
	if ((input.GetEvent(SDLK_d, DOWN) && input.GetEvent(SDLK_w, DOWN))
		|| (input.GetEvent(SDLK_d, HOLD) && input.GetEvent(SDLK_w, HOLD))) {
		body->currentDirection = PlayerDirections::UPERRIGHT;
		ImageObject::transform->rotation = 45.f;
		return;
	}
	if ((input.GetEvent(SDLK_d, DOWN) && input.GetEvent(SDLK_s, DOWN))
		|| (input.GetEvent(SDLK_d, HOLD) && input.GetEvent(SDLK_s, HOLD))) {
		body->currentDirection = PlayerDirections::DOWNRIGHT;
		ImageObject::transform->rotation = 135.f;
		return;
	}
	if ((input.GetEvent(SDLK_a, DOWN) && input.GetEvent(SDLK_s, DOWN))
		|| (input.GetEvent(SDLK_a, HOLD) && input.GetEvent(SDLK_s, HOLD))) {
		body->currentDirection = PlayerDirections::DOWNLEFT;
		ImageObject::transform->rotation = -135.f;
		return;
	}

	//Chack Noraml
    if (input.GetEvent(SDLK_a, DOWN) || input.GetEvent(SDLK_a, HOLD)) {
		body->currentDirection = PlayerDirections::LEFT;
        ImageObject::transform->rotation = -90.f;
        return;
    }
    if (input.GetEvent(SDLK_w, DOWN) || input.GetEvent(SDLK_w, HOLD)) {
		body->currentDirection = PlayerDirections::UP;
        ImageObject::transform->rotation = 0.f;
		return;
    }
    if (input.GetEvent(SDLK_d, DOWN) || input.GetEvent(SDLK_d, HOLD)) {
		body->currentDirection = PlayerDirections::RIGHT;
        ImageObject::transform->rotation = 90.f;
		return;
    }
    if (input.GetEvent(SDLK_s, DOWN) || input.GetEvent(SDLK_s, HOLD)) {
		body->currentDirection = PlayerDirections::DOWN;
        ImageObject::transform->rotation = 180.f;
		return;
    }

	body->currentDirection = PlayerDirections::NONE;


}


void Tank::Attack()
{
	InputManager& input = IM;
	if (input.GetLeftClick() && body->timeSinceLastFire >= body->fireCooldown) {


		Vector2 bulletSpawnPosition = ImageObject::transform->position + CalculateOfset();
		// Spawn the bullet
		SPAWN.SpawnObject(new Bullet(bulletSpawnPosition, 500, DirectionToAim(CalculateOfset())));
		body->timeSinceLastFire = 0.f;
	}
}

Vector2 Tank::CalculateOfset()
{
	//Math to make the bullet spawn at the tip of the canon

	float rotationAngle = canon->GetTransform()->rotation; // Needs to be swaped by Canon later;
	float radians = rotationAngle * (M_PI / 180.0f);

	Vector2 rotatedOffset(
		canon->relativeOffset.x * cos(radians) - canon->relativeOffset.y * sin(radians),
		canon->relativeOffset.x * sin(radians) + canon->relativeOffset.y * cos(radians)
	);

	return rotatedOffset;	
}


Vector2 Tank::DirectionToAim(Vector2 relativeOffset) {
	InputManager& input = IM;
	Vector2 adjustedPosition = canon->GetTransform()->position + relativeOffset;
	Vector2 direction;

	direction.x = input.GetMouseX() - adjustedPosition.x;
	direction.y = input.GetMouseY() - adjustedPosition.y;

	direction.Normalize();
	return direction;
}
void Tank::ReceiveDamage() {

}
void Tank::Update()
{
    Object::Update();
	body->timeSinceLastFire += TIME.GetDeltaTime();
    Movement();
	Attack();

	body->SetPosition(transform->position);
	body->SetRotation(transform->rotation);

	canon->SetPosition(transform->position);
	Vector2 aim = DirectionToAim(CalculateOfset());
	float angle = atan2(aim.y, aim.x) * 180.0f / M_PI;
	canon->SetRotation(angle + 90);
}
