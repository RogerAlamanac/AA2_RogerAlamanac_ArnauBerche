#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Renderers/RenderManager.h"
class ShootingEnemy : public ImageObject, Enemy
{
private:
	float timeToShoot = 4.f;
	float timeToMove = 3.f;
	float currentTimeToMove;
	float currentTimeToShoot;
    std::string pattern;
    size_t patternIndex = 0;
    float timeSinceLastMove = 0.0f;
    Vector2 velocity = Vector2(0, 0);
    Vector2 currentPosition;
public:
    void SetPattern(const std::string& p) { pattern = p; }
	ShootingEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, bool _loops, std::string path) : ImageObject(path, Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::UP);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    };
	~ShootingEnemy();
	void BaseMovement() override;
	void Shoot();
    void Update() override;
    void MoveAccordingToPattern(int direction) {

        switch (direction) {
        case 0: velocity = Vector2(0, 0);
            break;
        case 1: velocity = Vector2(movementSpeed, 0);
            break;
        case 2: velocity = Vector2(movementSpeed, -movementSpeed);
            break;
        case 3: velocity = Vector2(0, -movementSpeed);
            break;
        case 4: velocity = Vector2(-movementSpeed, -movementSpeed);
            break;
        case 5: velocity = Vector2(-movementSpeed, 0);
            break;
        case 6: velocity = Vector2(-movementSpeed, movementSpeed);
            break;
        case 7: velocity = Vector2(0, movementSpeed);
            break;
        case 8: velocity = Vector2(movementSpeed, movementSpeed);
            break;
        }

       currentPosition = GetTransform()->position;


        if (currentPosition.x < 0 || currentPosition.x  > RM->WINDOW_WIDTH) {
            velocity.x = -velocity.x;
        }
        if (currentPosition.y < 0 || currentPosition.y  > RM->WINDOW_HEIGHT) {
            velocity.y = -velocity.y;
        }
        ImageObject::physics->SetVelocity(velocity);
    }
};

