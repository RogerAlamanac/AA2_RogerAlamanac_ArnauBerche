#include "BasicEnemy.h"

void BasicEnemy::BaseMovement()
{
	ImageObject::physics->SetVelocity(DirectionToVector(pathPattern.front()) * movementSpeed);

	switch (pathPattern.front())
	{
	case Directions::DOWN:
		if ((int)transform->position.y % (int)transform->size.y/2 == 0 && (int)transform->position.y/2 != 0) {
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

void BasicEnemy::Update()
{
	timeSinceLastMove += TIME.GetDeltaTime();

	// Solo mover si ha pasado 1 segundo
	if (timeSinceLastMove >= 1.0f) {
		if (!pattern.empty()) {
			int direction = pattern[patternIndex] - '0'; // Convertir carácter a número
			MoveAccordingToPattern(direction);

			// Avanzar al siguiente paso del patrón
			patternIndex = (patternIndex + 1) % pattern.size();
		}

		// Reiniciar el temporizador
		timeSinceLastMove = 0.0f;
	}

	Object::Update();

}
