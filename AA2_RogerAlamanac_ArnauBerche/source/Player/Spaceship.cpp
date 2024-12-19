#include "Spaceship.h"
#include "../InputManager/InputManager.h"
#include "../Elements/Bullet.h"
#include "../Spawner/Spawner.h"
#include "../InputManager/TimeManager.h"

void Spaceship::Movement()
{
    InputManager& input = IM;

    if (ImageObject::transform->position.x > 0 + transform->size.x/2) {
        if (input.GetEvent(SDLK_a, DOWN) || input.GetEvent(SDLK_a, HOLD)) {
            ImageObject::transform->position.x -= 5.f;
        }
    }
    if (ImageObject::transform->position.x < RM->WINDOW_WIDTH - transform->size.x/2) {
        if (input.GetEvent(SDLK_d, DOWN) || input.GetEvent(SDLK_d, HOLD)) {
            ImageObject::transform->position.x += 5.f;
        }
    }



}

void Spaceship::Attack()
{
    InputManager& input = IM;

    if (input.GetEvent(SDLK_SPACE, HOLD) && timeSinceLastFire >= fireCooldown) {
        SPAWN.SpawnObject(new Bullet(ImageObject::transform->position,500,Vector2(0,-1), true));
       timeSinceLastFire = 0.f;
    }
}

void Spaceship::ReceiveDamage()
{
}

void Spaceship::Update()
{
    Object::Update();
    timeSinceLastFire += TIME.GetDeltaTime();
    Movement();
    Attack();
}
