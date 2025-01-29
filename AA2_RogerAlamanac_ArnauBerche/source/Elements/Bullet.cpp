#include "Bullet.h"

void Bullet::Update()
{
	Object::Update();
	timeSinceFire += TIME.GetDeltaTime();
	if (timeSinceFire >= timeToBeDestroyed) {
		Destroy();
	}
}

void Bullet::Render()
{
	Object::Render();
}
