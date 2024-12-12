#include "Spaceship.h"
#include "../InputManager/InputManager.h"

void Spaceship::Movement()
{
    Object::Update();
    InputManager& input = IM;

    if (input.GetEvent(SDLK_a, DOWN) || input.GetEvent(SDLK_a, HOLD)) {
        ImageObject::transform->position.x -= 5.f;
    }
    if (input.GetEvent(SDLK_d, DOWN) || input.GetEvent(SDLK_d, HOLD)) {
        ImageObject::transform->position.x += 5.f;
    }
}

void Spaceship::Attack()
{

}

void Spaceship::Update()
{
    Movement();
}
