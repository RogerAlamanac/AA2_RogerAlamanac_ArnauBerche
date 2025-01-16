#pragma once
#include "Enemy.h"
#include "../Object/ImageObject.h"
#include "../Renderers/RenderManager.h"
class BasicEnemy : public ImageObject, Enemy
{
private:
    std::string pattern; // Patrón de movimiento (0-8)
    size_t patternIndex = 0; // Índice actual del patrón
    float timeSinceLastMove = 0.0f; // Tiempo acumulado
public:
    bool isKilled = false;
    void SetPattern(const std::string& p) { pattern = p; }
    BasicEnemy(Vector2 pos, float _movementSpeed, int _health, int _damage, bool _loops) :
        ImageObject("resources/images/basicenemy.png", Vector2(0.f, 0.f), Vector2(180.f, 180.f), 0, "ENEMY"), Enemy(_health, _damage, _loops) {


        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::RIGHT);
        pathPattern.push(Directions::DOWN);
        pathPattern.push(Directions::LEFT);
        transform->position = pos;
        movementSpeed = _movementSpeed;
        ImageObject::transform->scale = Vector2(1.f, 1.f);
    }
    ~BasicEnemy();

    void BaseMovement() override;
    void Update() override;
    Vector2 GetPosition() { return transform->position; }
    bool IsKilled() { return isKilled; }

    void MoveAccordingToPattern(int direction) {
        switch (direction) {
        case 0: /* Quieto */ break;
        case 1: /* Derecha */ GetTransform()->position.x = GetTransform()->position.x + movementSpeed;
            break;
        case 2: /* Arriba-Derecha */ GetTransform()->position = GetTransform()->position + Vector2(movementSpeed, -movementSpeed); 
            break;
        case 3: /* Arriba */ GetTransform()->position.y -= movementSpeed; 
            break;
        case 4: /* Arriba-Izquierda */ GetTransform()->position = GetTransform()->position + Vector2(-movementSpeed, -movementSpeed); 
            break;
        case 5: /* Izquierda */ GetTransform()->position.x -= movementSpeed;
            break;
        case 6: /* Abajo-Izquierda */ GetTransform()->position = GetTransform()->position + Vector2(-movementSpeed, movementSpeed);
            break;
        case 7: /* Abajo */ GetTransform()->position.y += movementSpeed; 
            break;
        case 8: /* Abajo-Derecha */ GetTransform()->position = GetTransform()->position + Vector2(movementSpeed, movementSpeed);
            break;
        }
    }
};

