#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Renderers/RenderManager.h"
#include "../Player/Player.h"

class AimingEnemy : public ImageObject, public Enemy
{
private:
    Object* target;
    float timeToShoot = 4.f;
    float timeToMove = 3.f;
    float timeToReturnMoving = 3.f;
    float currentTimeToMove = 0.0f;
    float currentTimeToShoot = 0.0f;
    std::string pattern;
    size_t patternIndex = 0;
    Vector2 velocity = Vector2(0, 0);
    Vector2 currentPosition;

    enum class EnemyState {
        Moving,
        PreparingToShoot,
        Shooting
    };

    EnemyState state = EnemyState::Moving;
    float timePreparingToShoot = 1.0f;
    float currentPreparingTime = 0.0f;

public:
    void SetPattern(const std::string& p) { pattern = p; }
    AimingEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, bool _loops, Player* _target, std::string path)
        : ImageObject(path, Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "ENEMY"),
        Enemy(_health, _damage, _loops) {
        target = dynamic_cast<Object*>(_target);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    };
    ~AimingEnemy();

    void BaseMovement() override;
    void Shoot();
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
    };

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

        currentPosition = GetTransform()->position;

        if (currentPosition.x < 0 || currentPosition.x > RM->WINDOW_WIDTH) {
            velocity.x = -velocity.x;
        }
        if (currentPosition.y < 0 || currentPosition.y > RM->WINDOW_HEIGHT) {
            velocity.y = -velocity.y;
        }
        ImageObject::physics->SetVelocity(velocity);
    }
};


