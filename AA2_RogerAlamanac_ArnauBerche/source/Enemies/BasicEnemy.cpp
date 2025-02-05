#include "BasicEnemy.h"

void BasicEnemy::BaseMovement()
{
}

void BasicEnemy::Update()
{
	timeSinceLastMove += (float)TIME.GetDeltaTime();

	if (!pattern.empty()) {
		int direction = pattern[patternIndex] - '0'; 
		MoveAccordingToPattern(direction);
		if (timeSinceLastMove >= 0.5f) {
			patternIndex = (patternIndex + 1) % pattern.size();
			timeSinceLastMove = 0.0f;
		}
	}
	Object::Update();

}
