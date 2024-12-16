#pragma once
#include "../Object/ImageObject.h"
class Background : public ImageObject
{
public:
	Background(Vector2 pos) : ImageObject("resources/background_space.jpg", Vector2(0.f, 0.f), Vector2(2000.f, 1125.f),0,"BG") {
		transform->position = pos;
		transform->scale = Vector2(30.f, 17.f);
	}
	~Background();
	void Update() override;
};

