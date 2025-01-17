#pragma once
#include "../Object/ImageObject.h"
#include <string>
class Background : public ImageObject
{
public:
	Background(Vector2 pos, std::string path) : ImageObject(path, Vector2(0.f, 0.f), Vector2(1360.f, 768.f),0,"BG") {
		transform->position = pos;
		transform->scale = Vector2(13.6f, 7.68f);
	}
	~Background();
	void Update() override;
};

