#include "SeekerEnemy.h"

void SeekerEnemy::BaseMovement()
{
	if (CalculateDistance(transform->position, target->GetTransform()->position) > rangeToSeek) {
		ImageObject::physics->SetVelocity(DirectionToVector(pathPattern.front()) * movementSpeed);
		switch (pathPattern.front())
		{
		case Directions::DOWN:
			if (currentTimeToMove >= timeToMove) {
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
				currentTimeToMove = 0;
			}
			break;
		case Directions::RIGHT:
			if (currentTimeToMove >= timeToMove) {
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
				currentTimeToMove = 0;
			}
			break;
		case Directions::LEFT:
			if (currentTimeToMove >= timeToMove) {
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
				currentTimeToMove = 0;
			}
		case Directions::UP:
			if (currentTimeToMove >= timeToMove) {
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
				currentTimeToMove = 0;
			}
			break;
		default:
			break;
		}
	}
	else {
		ImageObject::physics->SetVelocity(DirectionToPlayer() * movementSpeed);
	}
}

void SeekerEnemy::Update(){
	Object::Update();
	currentTimeToMove += TIME.GetDeltaTime();
	BaseMovement();
}
