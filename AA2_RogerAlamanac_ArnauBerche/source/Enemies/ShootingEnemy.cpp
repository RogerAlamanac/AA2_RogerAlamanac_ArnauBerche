#include "ShootingEnemy.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"
void ShootingEnemy::BaseMovement()
{
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

void ShootingEnemy::Shoot()
{
	if (currentTime >= timeToShoot) {
		SPAWN.SpawnObject(new Bullet(ImageObject::transform->position - Vector2(0, ImageObject::transform->size.y / 2), 
			100, Vector2(ImageObject::transform->position.x, ImageObject::transform->position.y - 100)));
	}
}

void ShootingEnemy::Update()
{
	Object::Update();
	currentTime = TIME.GetDeltaTime();
	BaseMovement();
	Shoot();
}
