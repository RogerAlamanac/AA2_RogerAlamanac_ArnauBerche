#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
class Tank : public ImageObject,  Player
{
public:
	Tank(Vector2 pos) : ImageObject("resources/guitar.jpg", Vector2(0.f, 0.f), Vector2(384.f, 96.f), 1) {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
	}
	~Tank();
	void Movement() override;
	void Attack() override;
	void Update() override;
};

