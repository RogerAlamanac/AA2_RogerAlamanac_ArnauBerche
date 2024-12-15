#include "SeekerEnemy.h"

void SeekerEnemy::BaseMovement()
{
	if (rangeToSeek > 100.f) {
		ImageObject::physics->SetVelocity(DirectionToVector(pathPattern.front()) * movementSpeed);
		switch (pathPattern.front())
		{
		case Directions::DOWN:
			if ((int)transform->position.y % (int)transform->size.y / 2 == 0 && (int)transform->position.y / 2 != 0) {
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
			}
			break;
		case Directions::RIGHT:
			if ((int)transform->position.x >= RM->WINDOW_WIDTH - (int)transform->size.x / 2)
			{
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
			}
			break;
		case Directions::LEFT:
			if ((int)transform->position.x <= (int)transform->size.x / 2)
			{
				Directions d = pathPattern.front();
				pathPattern.pop();
				if (Loops())
				{
					pathPattern.push(d);
				}
			}
			break;
		default:
			break;
		}
	}
	else {

	}
}
