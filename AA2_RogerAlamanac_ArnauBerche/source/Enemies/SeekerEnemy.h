#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Player/Player.h"
class SeekerEnemy : public ImageObject, Enemy
{
private:
    float rangeToSeek;
    Object* target;
    std::string pattern;
    size_t patternIndex = 0; 
    float timeToMove = 3.f;
    float currentTimeToMove;
    float timeSinceLastMove = 0.0f; 
public:
    void SetPattern(const std::string& p) { pattern = p; }
    SeekerEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, float _rangeToSeek, bool _loops, Player* player, std::string path) : ImageObject(path, Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        rangeToSeek = _rangeToSeek;
        target = dynamic_cast<Object*>(player);
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    };
	~SeekerEnemy();
	void BaseMovement() override;
    float CalculateDistance(const Vector2& pos1, const Vector2& pos2) {
        float dx = pos1.x - pos2.x;
        float dy = pos1.y - pos2.y;
        return sqrt(dx * dx + dy * dy);
    }

    Vector2 DirectionToPlayer(){
        Vector2 direction = target->GetTransform()->position - transform->position;
        float length = CalculateDistance(transform->position, target->GetTransform()->position);
        if (length != 0) {
            direction.Normalize();
        }
        return direction;
    };

    void Update() override;

    void MoveAccordingToPattern(int direction) {
        switch (direction) {
        case 0:  break;
        case 1:  GetTransform()->position.x = GetTransform()->position.x + movementSpeed;
            break;
        case 2: GetTransform()->position = GetTransform()->position + Vector2(movementSpeed, -movementSpeed);
            break;
        case 3:  GetTransform()->position.y -= movementSpeed;
            break;
        case 4: GetTransform()->position = GetTransform()->position + Vector2(-movementSpeed, -movementSpeed);
            break;
        case 5:  GetTransform()->position.x -= movementSpeed;
            break;
        case 6:  GetTransform()->position = GetTransform()->position + Vector2(-movementSpeed, movementSpeed);
            break;
        case 7:  GetTransform()->position.y += movementSpeed;
            break;
        case 8:  GetTransform()->position = GetTransform()->position + Vector2(movementSpeed, movementSpeed);
            break;
        }
    }

};

