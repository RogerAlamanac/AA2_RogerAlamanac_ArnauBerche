#include "Swatter.h"
#include "../InputManager/InputManager.h"
#include <iostream>

void Swatter::Attack()
{
}

void Swatter::Movement()
{
}

void Swatter::ReceiveDamage()
{
}

void Swatter::Update(){
    InputManager& input = IM;
    Object::Update();

    if (currentState == SwatterState::MOVING) {
        Vector2 movementVector = Vector2(input.GetMouseX(), input.GetMouseY()) - transform->position;
        if (GetRigidBody()->CheckOverlappingPoint(Vector2(input.GetMouseX(), input.GetMouseY())))
        {
            physics->SetLinearDrag(2);
            return;
        }
        else
        {
            physics->SetLinearDrag(0);
        }

        movementVector.Normalize();
        physics->AddForce(movementVector * movementMultiplyer);
        if (input.GetLeftClick()) {
            currentState = SwatterState::ATTACKING;
        }
    }
    else if (currentState == SwatterState::ATTACKING) {
        currentState = SwatterState::STUNNED;
        currentStunTime = 0.0f;
    }
    else if (currentState == SwatterState::STUNNED) {
        currentStunTime += TIME.GetDeltaTime();
        physics->SetVelocity(Vector2(0, 0));
        if (currentStunTime >= maxStunTime)
            currentState = SwatterState::MOVING;
    }


    
}
void Swatter::OnCollisionEnter(Object* other)
{
    if (currentState == SwatterState::MOVING)
        return;

    if (other->tag == "ENEMY")
    {
        if (currentState == SwatterState::ATTACKING) {
            other->Destroy();
            currentState = SwatterState::MOVING;
        }
    }
}

