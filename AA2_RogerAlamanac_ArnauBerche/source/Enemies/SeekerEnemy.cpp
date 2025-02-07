#include "SeekerEnemy.h"


void SeekerEnemy::BaseMovement() {
    if (CalculateDistance(transform->position, target->GetTransform()->position) > rangeToSeek) {
        MoveTowardsPlayer();
        isAttacking = false;
    }
    else {
        ImageObject::physics->SetVelocity(Vector2(0, 0));  // Stop moving when in range
        isAttacking = true;
    }
}

void SeekerEnemy::Update() {
    timeSinceLastMove += (float)TIME.GetDeltaTime();

    if (!pattern.empty()) {
        int direction = pattern[patternIndex] - '0';
        MoveAccordingToPattern(direction);
        if (timeSinceLastMove >= 0.5f) {
            patternIndex = (patternIndex + 1) % pattern.size();
            timeSinceLastMove = 0.0f;
        }
    }

    BaseMovement();

    if (isAttacking && timeSinceLastMove >= 0.5f) {
        AttackPlayer();
        timeSinceLastMove = 0.0f;
    }

    Object::Update();
}
