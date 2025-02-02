#include "Bullet.h"

void Bullet::Update()
{
	Object::Update();
	timeSinceFire += (float)TIME.GetDeltaTime();
	if (timeSinceFire >= timeToBeDestroyed) {
		Destroy();
	}
}

void Bullet::Render()
{
	Object::Render();
}
