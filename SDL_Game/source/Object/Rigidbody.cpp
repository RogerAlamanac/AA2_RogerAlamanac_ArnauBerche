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
    //1. Update velocity
    velocity = velocity + acceleration * dt;
    angularVelocity = angularVelocity + angularAcceleration * dt;
    //2. Update DRAG
    velocity = velocity * (1.0f / (1.0f + dt * linearDrag));
    angularVelocity = angularVelocity * (1.0f / (1.0f + dt * angularDrag));

    //3. Update position
    transform->position = transform->position + velocity * dt;
    transform->rotation = transform->rotation + angularVelocity * dt;

    //4. Reset acceleration
    acceleration = Vector2();
    angularAcceleration = 0.0f;

    //5. Check Collision
    for (AABB* col : colliders) {
        col->SetTopLeft(transform->position);
    }

}


