#pragma once
#include "Object.h"
class TestObject : public Object {
public:
	TestObject() : Object("resources/SpriteSheet.png", Vector2(0.f, 0.f), Vector2(1600.f, 680.f), 1) {

		//Rand in all the window
		Vector2 randomPos = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);

		transform->position = randomPos;
		transform->scale = Vector2(0.2f, 0.2f);

		Vector2 randomForce = Vector2(-500 + rand() & 1001, -500 + rand() % 1001);
		physics->AddForce(randomForce);

	}

	void OnCollisionEnter(Object* other) override {
		if (TestObject* to = reinterpret_cast<TestObject*>(other)) {
			//CODE that runs if other is a TestObject
			Destroy();
			to->Destroy();
		}
	}
};