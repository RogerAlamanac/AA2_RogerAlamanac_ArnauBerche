#pragma once
#include "../Object/ImageObject.h"
class Bullet : public ImageObject //CLASE ELEMENTS NO FA FALTA
{
private:
	//float timeToLive = 1;
	//int damage = 1;
public:
	Bullet(Vector2 initialPos, Vector2 velocity) : ImageObject("resources/circle.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0) {
		ImageObject::transform->position = initialPos;
		ImageObject::transform->scale = Vector2(0.2f,0.2f);
		ImageObject::physics->AddTorque(500.f);
		ImageObject::physics->SetVelocity(velocity);
	}
	~Bullet();
	void Update() override;
	void OnCollisionEnter(Object* other) override {
		Destroy();
	}
};

