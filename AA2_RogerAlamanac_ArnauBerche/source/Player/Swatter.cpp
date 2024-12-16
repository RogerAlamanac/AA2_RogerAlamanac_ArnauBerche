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
        if (currentTime - stuckTime >= 5.0f) {
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


    // Ensure the player does not go off the screen
    if (transform->position.x < 0) {
        transform->position.x = 0;
    }
    else if (transform->position.x > RM->WINDOW_WIDTH - transform->size.x) {
        transform->position.x = RM->WINDOW_WIDTH - transform->size.x;
    }

    if (transform->position.y < 0) {
        transform->position.y = 0;
    }
    else if (transform->position.y > RM->WINDOW_HEIGHT - transform->size.y) {
        transform->position.y = RM->WINDOW_HEIGHT - transform->size.y;
    }

    // Ensure the player always faces upper left (-1, -1)
    ImageObject::transform->rotation = -90.0f;  // Set rotation to face upper left
}

void Swatter::Attack() {
    InputManager& input = IM;

    if (input.GetEvent(SDL_BUTTON_LEFT, DOWN) && !isStuck) {

        if (!IsFlyHit()) {
            isStuck = true;
            stuckTime = currentTime; 
        }
        else {
            //destruir enemy
           
        }
    }
}

bool Swatter::IsFlyHit() {

    // for (const auto& fly : flies) {
    //     if (CheckCollision(fly)) {
    //         return true;
    //     }
    // }
    return false;
}


void Swatter::ReceiveDamage()
{
}

void Swatter::Update()
{
    Object::Update();
    currentTime = TIME.GetDeltaTime();
    Movement();
    if (isStuck && (currentTime - stuckTime >= 5.0f)) {
        isStuck = false;
    }
    Attack();
}

bool Swatter::CheckCollision(const Vector2& swatterPos, const Vector2& targetPos, float size)
{
    float dx = swatterPos.x - targetPos.x;
    float dy = swatterPos.y - targetPos.y;
    return std::sqrt(dx * dx + dy * dy) < size;
}
