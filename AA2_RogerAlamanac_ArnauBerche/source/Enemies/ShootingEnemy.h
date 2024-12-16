#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Renderers/RenderManager.h"
class ShootingEnemy : public ImageObject, Enemy
{
private:
	float timeToShoot = 5.f;
	float currentTime;
public:
	ShootingEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, bool _loops) :
        ImageObject("resources/basicenemy.png", Vector2(0.f, 0.f), Vector2(180.f, 180.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    };
	~ShootingEnemy();
	void BaseMovement() override;
	void Shoot();
    void Update() override;
};

