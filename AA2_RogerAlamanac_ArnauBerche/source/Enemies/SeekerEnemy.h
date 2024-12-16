#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
class SeekerEnemy : public ImageObject, Enemy
{
private:
    float rangeToSeek;
public:
    SeekerEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, float _rangeToSeek, bool _loops) :
        ImageObject("resources/basicenemy.png", Vector2(0.f, 0.f), Vector2(180.f, 180.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {

        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        rangeToSeek = _rangeToSeek;
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    };
	~SeekerEnemy();
	void BaseMovement() override;
    float CalculateDistance(const Vector2& pos1, const Vector2& pos2) {
        float dx = pos1.x - pos2.x;
        float dy = pos1.y - pos2.y;
        return sqrt(dx * dx + dy * dy);
    }

    // Método auxiliar para calcular la dirección normalizada del enemigo hacia el jugador
    Vector2 CalculateDirection(const Vector2& from, const Vector2& to) {
        Vector2 direction = { to.x - from.x, to.y - from.y };
        float length = sqrt(direction.x * direction.y + direction.y * direction.y);
        if (length != 0) {
            direction.x /= length;
            direction.y /= length;
        }
        return direction;
    }
};

