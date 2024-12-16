#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Renderers/RenderManager.h"
#include "../Player/Player.h"

class AimingEnemy : public ImageObject, public Enemy
{
private:
	Object* target;

	float timeToStopMoving = 5.f;
	float timeStopped;

	float timeToShoot = 4.f;
	float timeToMove = 3.f;
	float currentTimeToMove;
	float currentTimeToShoot;

public:
	AimingEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, bool _loops, Player* player) :
        ImageObject("resources/basicenemy.png", Vector2(0.f, 0.f), Vector2(180.f, 180.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
		target = dynamic_cast<Object*>(player);
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    };
	~AimingEnemy();

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
	void BaseMovement() override;
	void Shoot();
    bool IsStopped();
	void Update() override;
};

