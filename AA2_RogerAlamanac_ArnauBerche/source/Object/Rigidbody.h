#pragma once
#include "AABB.h"
#include "Transform.h"
#include <vector>
class Rigidbody {
private:
    std::vector<AABB*> colliders;
    Transform* transform;
    Vector2 velocity;
    float angularVelocity;
    Vector2 acceleration;
    float angularAcceleration;
    float linearDrag;
    float angularDrag;

public:

    Rigidbody(Transform* _transform)
        : transform(_transform), velocity (Vector2()), acceleration(Vector2()),
        angularVelocity(0.0f), angularAcceleration(0.0f), 
        linearDrag(0.0f), angularDrag(0.0f) {}


    ~Rigidbody() {
        for (AABB* collider : colliders) {
            delete collider;
        }
    }

    inline void AddCollider(AABB* collider) {colliders.push_back(collider);}
    bool CheckCollision(const Rigidbody* other);
    bool CheckOverlappingPoint(const Vector2& point) const; 
    void Update(float dt);
    inline void AddForce(const Vector2& force) { acceleration = acceleration + force; }
    inline void AddTorque(float amount) { angularAcceleration += amount; }
    inline Vector2 const GetVelocity() {return velocity;}
    inline void SetVelocity(const Vector2& _velocity) { this->velocity = _velocity; }
    inline void SetLinearDrag(float _linearDrag) { this->linearDrag = _linearDrag; }
    inline void SetAngularDrag(float _angularDrag) { this->angularDrag = _angularDrag; }
};
