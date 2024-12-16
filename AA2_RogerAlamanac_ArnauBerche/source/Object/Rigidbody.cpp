#include "Rigidbody.h"

bool Rigidbody::CheckCollision(const Rigidbody* other) 
{
    for (AABB* myCol : colliders) {
        for (AABB* otherCol : other->colliders) {
            if (myCol->CheckOverlappingAABB(otherCol)) {
                return true;
            }
        }
    }
    return false;
}

bool Rigidbody::CheckOverlappingPoint(const Vector2& point) const
{
    for (AABB* myCol : colliders) {
        if (myCol->CheckOverlappingPoint(point)) {
            return true;
        }
    }
    return false;
}

void Rigidbody::Update(float dt)
{
    velocity = velocity + acceleration * dt;
    angularVelocity = angularVelocity + angularAcceleration * dt;

    velocity = velocity * (1.0f / (1.0f + dt * linearDrag));
    angularVelocity = angularVelocity * (1.0f / (1.0f + dt * angularDrag));


    transform->position = transform->position + velocity * dt;
    transform->rotation = transform->rotation + angularVelocity * dt;


    acceleration = Vector2();
    angularAcceleration = 0.0f;


    Vector2 offset = (Vector2(-transform->size.x, -transform->size.y) / 2.0f) * transform->scale;

    for (AABB* col : colliders) {
        col->SetTopLeft(transform->position + offset);
        col->SetSize(transform->size * transform->scale);
    }

}


