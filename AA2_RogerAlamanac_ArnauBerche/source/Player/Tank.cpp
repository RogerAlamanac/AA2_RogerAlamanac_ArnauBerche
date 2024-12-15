#include "Tank.h"
#include "../InputManager/InputManager.h"

void Tank::Movement()
{
    InputManager& input = IM;

    if (input.GetEvent(SDLK_a, DOWN) || input.GetEvent(SDLK_a, HOLD)) {
        ImageObject::transform->position.x -= 5.f;
    }

    if ((input.GetEvent(SDLK_a, DOWN) && input.GetEvent(SDLK_w, DOWN)) 
        || (input.GetEvent(SDLK_a, HOLD) && input.GetEvent(SDLK_w, HOLD))) {
        ImageObject::transform->position.x -= 5.f;
        ImageObject::transform->position.y -= 5.f;
    }

    if (input.GetEvent(SDLK_w, DOWN) || input.GetEvent(SDLK_d, HOLD)) {
        ImageObject::transform->position.y -= 5.f;
    }

    if ((input.GetEvent(SDLK_d, DOWN) && input.GetEvent(SDLK_w, DOWN))
        || (input.GetEvent(SDLK_d, HOLD) && input.GetEvent(SDLK_w, HOLD))) {
        ImageObject::transform->position.x += 5.f;
        ImageObject::transform->position.y -= 5.f;
    }

    if (input.GetEvent(SDLK_d, DOWN) || input.GetEvent(SDLK_d, HOLD)) {
        ImageObject::transform->position.x += 5.f;
    }

    if ((input.GetEvent(SDLK_d, DOWN) && input.GetEvent(SDLK_s, DOWN))
        || (input.GetEvent(SDLK_d, HOLD) && input.GetEvent(SDLK_s, HOLD))) {
        ImageObject::transform->position.x += 5.f;
        ImageObject::transform->position.y += 5.f;
    }
  
    if (input.GetEvent(SDLK_s, DOWN) || input.GetEvent(SDLK_s, HOLD)) {
        ImageObject::transform->position.y += 5.f;
    }

    if ((input.GetEvent(SDLK_a, DOWN) && input.GetEvent(SDLK_s, DOWN))
        || (input.GetEvent(SDLK_a, HOLD) && input.GetEvent(SDLK_s, HOLD))) {
        ImageObject::transform->position.x -= 5.f;
        ImageObject::transform->position.y += 5.f;
    }
}

void Tank::Update()
{
    Movement();
}
