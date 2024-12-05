#pragma once
#include "Object.h"
class TestObject : public Object {
public:
	TestObject() : Object("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(384.f, 96.f), 0) {

		//Rand in all the window
		Vector2 randomPos = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);

		transform->position = randomPos;
		transform->scale = Vector2(1.f, 1.f);

		Vector2 randomForce = Vector2(-500 + rand() & 1001, -500 + rand() % 1001);
		physics->AddForce(randomForce);

	}

	TestObject(Vector2 pos, Vector2 startVelocity) : Object("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(384.f, 96.f), 0)
	{
		transform->position = pos;
		transform->scale = Vector2(1.f,1.f);
		physics->AddForce(startVelocity);
	}

	void OnCollisionEnter(Object* other) override {
			Destroy();
	}


};