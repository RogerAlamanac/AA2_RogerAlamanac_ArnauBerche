#include "Swatter.h"
#include "../InputManager/InputManager.h"


Vector2 Swatter::DirectionToAim(Vector2 relativeOffset)
{
	InputManager& input = IM;
	Vector2 adjustedPosition = transform->position + relativeOffset;
	Vector2 direction;

	direction.x = input.GetMouseX() - adjustedPosition.x;
	direction.y = input.GetMouseY() - adjustedPosition.y;

	direction.Normalize();
	return direction;
}

void Swatter::Movement()
{
    InputManager& input = IM;
    if (isStuck) {
        if (currentTime - stuckTime >= 1.0f) {
            isStuck = false;
        }
        else {
            return;
        }
    }
    Vector2 direction;
    Vector2 adjustedPosition = transform->position;
    direction.x = input.GetMouseX() - adjustedPosition.x;
    direction.y = input.GetMouseY() - adjustedPosition.y;

    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 0.0001f) {
        return; 
    }

    direction.Normalize();

    if (distance < maxVelocity) {
        ImageObject::physics->SetVelocity(direction * distance);
    }
    else {
        ImageObject::physics->SetVelocity(direction * maxVelocity);
    }
}

void Swatter::Attack()
{
}

void Swatter::ReceiveDamage()
{
}

void Swatter::Update()
{
    Object::Update();
    currentTime = TIME.GetDeltaTime();
    Movement();
}

bool Swatter::CheckCollision(const Vector2& swatterPos, const Vector2& targetPos, float size)
{
    float dx = swatterPos.x - targetPos.x;
    float dy = swatterPos.y - targetPos.y;
    return std::sqrt(dx * dx + dy * dy) < size;
}
