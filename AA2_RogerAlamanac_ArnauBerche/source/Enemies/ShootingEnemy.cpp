#include "ShootingEnemy.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"
void ShootingEnemy::BaseMovement()
{
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

void ShootingEnemy::Shoot()
{
	if (currentTimeToShoot >= timeToShoot) {
		SPAWN.SpawnObject(new Bullet(ImageObject::transform->position, 
			100, DirectionToVector(pathPattern.front())*5, false));
		currentTimeToShoot = 0;
	}
}

void ShootingEnemy::Update()
{
	Object::Update();
	currentTimeToMove += TIME.GetDeltaTime();
	currentTimeToShoot += TIME.GetDeltaTime();
	BaseMovement();
	Shoot();
}
