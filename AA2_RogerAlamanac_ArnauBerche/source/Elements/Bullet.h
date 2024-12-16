#pragma once
#include "../Object/ImageObject.h"
#include <iostream>
class Bullet : public ImageObject
{
private:
	bool friendly;
public:
	Bullet(Vector2 initialPos, float velocity, Vector2 finalPos, bool _friendly) : ImageObject("resources/circle.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "BULLET") {
		friendly = _friendly;
		ImageObject::transform->position = initialPos;
		ImageObject::transform->scale = Vector2(0.2f,0.2f);
		physics->SetVelocity(finalPos * velocity);
		physics->AddCollider(new AABB(Vector2(0.f, 0.f), Vector2(512.f, 512.f)));
	}
	~Bullet();
	void Update() override;

	void OnCollisionEnter(Object* other) override {
		if (other->tag == "BG") { return; }

		if (friendly) 
		{
			if (other->tag == "PLAYER" ||
				other->tag == "BULLET")
			{
				return;
			}
		}
		else
		{
			if (other->tag == "ENEMY" ||
				other->tag == "BULLET")
			{
				return;
			}
		}

		other->Destroy();
	}
};

