#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Renderers/RenderManager.h"
class BasicEnemy : public ImageObject, Enemy
{
public:
	BasicEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, bool _loops) : 
        ImageObject("resources/basicenemy.png", Vector2(0.f, 0.f), Vector2(180.f, 180.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    }
	~BasicEnemy();

    //void OnCollisionEnter(Object* other) override {
    //    Destroy();
    //}
    void BaseMovement() override;
	void Update() override;
    Vector2 GetPosition() { return transform->position; }
};

