#pragma once
#include "../Object/ImageObject.h"
class Bullet : public ImageObject //CLASE ELEMENTS NO FA FALTA
{
private:
	float timeToLive;
	int damage;
public:
	Bullet(Vector2 initialPos, Vector2 velocity) : ImageObject("resources/b.png", Vector2(0.f, 0.f), Vector2(553.f, 535.f), 0) {
		transform->position = initialPos;
		transform->scale = Vector2(0.1f,0.1f);
		physics->AddTorque(500.f);
		physics->AddForce(velocity);
	}
	~Bullet();
	void Update() override;
};

