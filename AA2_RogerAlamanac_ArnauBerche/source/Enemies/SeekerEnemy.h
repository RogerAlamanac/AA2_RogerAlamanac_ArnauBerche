#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Player/Player.h"
#include "../Renderers/RenderManager.h"

class SeekerEnemy : public ImageObject, public Enemy
{
private:
    float rangeToSeek;
    Object* target;
    std::string pattern;
    size_t patternIndex = 0;
    float timeSinceLastMove = 0.0f;
    Vector2 velocity = Vector2(0, 0);
    Vector2 currentPosition;
    bool isAttacking = false;

public:
    bool isKilled = false;
    void SetPattern(const std::string& p) { pattern = p; }
    SeekerEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, float _rangeToSeek, bool _loops, Player* player, std::string path)
        : ImageObject(path, Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        transform->position = pos;
        movementSpeed = _movementSpeed;
        rangeToSeek = _rangeToSeek;
        target = dynamic_cast<Object*>(player);
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    }

    ~SeekerEnemy();

    void BaseMovement() override;
    void Update() override;

    float CalculateDistance(const Vector2& pos1, const Vector2& pos2) {
        float dx = pos1.x - pos2.x;
        float dy = pos1.y - pos2.y;
        return sqrt(dx * dx + dy * dy);
    }

    Vector2 DirectionToPlayer() {
        Vector2 direction = target->GetTransform()->position - transform->position;
        float length = CalculateDistance(transform->position, target->GetTransform()->position);
        if (length != 0) {
            direction.Normalize();
        }
        return direction;
    }

    void MoveTowardsPlayer() {
        Vector2 direction = DirectionToPlayer();
        ImageObject::physics->SetVelocity(direction * movementSpeed);
    }

    void AttackPlayer() {

    }

    Vector2 GetPosition() { return transform->position; }
    bool IsKilled() { return isKilled; }

    void MoveAccordingToPattern(int direction) {
        switch (direction) {
        case 0: velocity = Vector2(0, 0); break;
        case 1: velocity = Vector2(movementSpeed, 0); break;
        case 2: velocity = Vector2(movementSpeed, -movementSpeed); break;
        case 3: velocity = Vector2(0, -movementSpeed); break;
        case 4: velocity = Vector2(-movementSpeed, -movementSpeed); break;
        case 5: velocity = Vector2(-movementSpeed, 0); break;
        case 6: velocity = Vector2(-movementSpeed, movementSpeed); break;
        case 7: velocity = Vector2(0, movementSpeed); break;
        case 8: velocity = Vector2(movementSpeed, movementSpeed); break;
        }

        currentPosition = GetTransform()->position + velocity;

        if (currentPosition.x < 0 || currentPosition.x > RM->WINDOW_WIDTH) {
            velocity.x = -velocity.x;
        }
        if (currentPosition.y < 0 || currentPosition.y > RM->WINDOW_HEIGHT) {
            velocity.y = -velocity.y;
        }
        ImageObject::physics->SetVelocity(velocity);
    }
};


