#include "AimingEnemy.h"
#include "../Spawner/Spawner.h"
#include "../Elements/Bullet.h"
void AimingEnemy::BaseMovement()
{
	if(!IsStopped()){
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
			}
		case Directions::UP:
			if (currentTimeToMove >= timeToMove) {
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
	else 
	{
		Shoot();
	}
}
bool AimingEnemy::IsStopped(){
	return currentTimeToMove >= timeToStopMoving;
}
void AimingEnemy::Shoot()
{
	if (currentTimeToShoot >= timeToShoot) {
		SPAWN.SpawnObject(new Bullet(ImageObject::transform->position - Vector2(0, ImageObject::transform->size.y / 2), 
			100, DirectionToPlayer() * 2, false));
		currentTimeToMove = 0;
		currentTimeToShoot = 0;
	}
	
}

void AimingEnemy::Update()
{
	Object::Update();
	if (target == nullptr) { return;  }
	currentTimeToMove += TIME.GetDeltaTime();
	currentTimeToShoot += TIME.GetDeltaTime();
	BaseMovement();
}
