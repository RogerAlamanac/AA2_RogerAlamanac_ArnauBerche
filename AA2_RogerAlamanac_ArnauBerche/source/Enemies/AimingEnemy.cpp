#include "AimingEnemy.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"

void AimingEnemy::BaseMovement() {}

void AimingEnemy::Shoot() {
    SPAWN.SpawnObject(new Bullet(ImageObject::transform->position - Vector2(0, ImageObject::transform->size.y / 2),
        100, DirectionToPlayer() * 2, false));
}

void AimingEnemy::Update() {
    float deltaTime = (float)TIME.GetDeltaTime();

    switch (state) {
    case EnemyState::Moving:
        currentTimeToMove += deltaTime;
        currentTimeToShoot += deltaTime;

        if (!pattern.empty()) {
            int direction = pattern[patternIndex] - '0';
            MoveAccordingToPattern(direction);

            if (currentTimeToMove >= 0.5f) {
                patternIndex = (patternIndex + 1) % pattern.size();
                currentTimeToMove = 0.0f;
            }
        }

        if (currentTimeToShoot >= timeToShoot) {
            velocity = Vector2(0, 0);  // Stop the enemy
            ImageObject::physics->SetVelocity(velocity);
            currentPreparingTime = 0.0f;
            state = EnemyState::PreparingToShoot;
        }
        break;

    case EnemyState::PreparingToShoot:
        currentPreparingTime += deltaTime;
        if (currentPreparingTime >= timePreparingToShoot) {
            state = EnemyState::Shooting;
        }
        break;

    case EnemyState::Shooting:
        Shoot();
        currentTimeToShoot = 0.0f;  // Reset shooting timer
        state = EnemyState::Moving; // Resume moving after shooting
        break;
    }

    Object::Update();  // Ensure base update is called
}