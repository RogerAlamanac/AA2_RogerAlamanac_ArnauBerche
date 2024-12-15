#include "Spaceship.h"
#include "../InputManager/InputManager.h"
#include "../Elements/Bullet.h"
#include "../Spawner/Spawner.h"
#include "../InputManager/TimeManager.h"

void Spaceship::Movement()
{
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
    InputManager& input = IM;

    if (input.GetEvent(SDLK_SPACE, DOWN) && timeSinceLastFire >= fireCooldown) {
        SPAWN.SpawnObject(new Bullet(ImageObject::transform->position - Vector2(0,ImageObject::transform->size.y/2), Vector2(0, -500)));
        timeSinceLastFire = 0.f;
    }
}

void Spaceship::Update()
{
    Object::Update();
    timeSinceLastFire += TIME.GetDeltaTime();
    Movement();
    Attack();
}
