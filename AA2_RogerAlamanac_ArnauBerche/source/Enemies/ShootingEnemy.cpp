#include "ShootingEnemy.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"

void ShootingEnemy::BaseMovement()
{

}

void ShootingEnemy::Shoot()
{
    if (currentTimeToShoot >= timeToShoot) {
        if (!pattern.empty()) {
            int direction = pattern[patternIndex] - '0';  // Get the current direction from the pattern
            Vector2 shootDirection;

            // Convert direction index to movement vector
            switch (direction) {
            case 0: shootDirection = Vector2(0, 0); break;                       // No movement
            case 1: shootDirection = Vector2(1, 0); break;                       // Right
            case 2: shootDirection = Vector2(1, -1); break;                      // Up-Right
            case 3: shootDirection = Vector2(0, -1); break;                      // Up
            case 4: shootDirection = Vector2(-1, -1); break;                     // Up-Left
            case 5: shootDirection = Vector2(-1, 0); break;                      // Left
            case 6: shootDirection = Vector2(-1, 1); break;                      // Down-Left
            case 7: shootDirection = Vector2(0, 1); break;                       // Down
            case 8: shootDirection = Vector2(1, 1); break;                       // Down-Right
            default: shootDirection = Vector2(0, -1); break;                     // Default to Up
            }

            shootDirection.Normalize();  // Normalize the direction to avoid speed issues

            SPAWN.SpawnObject(new Bullet(ImageObject::transform->position,
                100, shootDirection * 5, false));  // Shoot in the direction of movement
        }
        currentTimeToShoot = 0;  // Reset shooting timer
    }
}

void ShootingEnemy::Update()
{
	timeSinceLastMove += (float)TIME.GetDeltaTime();

	if (!pattern.empty()) {
		int direction = pattern[patternIndex] - '0';
		MoveAccordingToPattern(direction);
		if (timeSinceLastMove >= 0.5f) {
			patternIndex = (patternIndex + 1) % pattern.size();
			timeSinceLastMove = 0.0f;
		}
	}
	Object::Update();
	currentTimeToMove += (float)TIME.GetDeltaTime();
	currentTimeToShoot += (float)TIME.GetDeltaTime();
	Shoot();
}
