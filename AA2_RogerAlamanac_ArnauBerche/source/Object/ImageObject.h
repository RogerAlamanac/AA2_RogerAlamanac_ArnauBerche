#pragma once
#include "Object.h"
#include "../Renderers/ImageRenderer.h"
class ImageObject : public Object {
public:
	ImageObject(std::string texturePath, Vector2 sourceOffset, Vector2 sourceSize, int imgType) : Object() {
		physics->AddCollider(new AABB(sourceOffset, sourceSize * 0.2f));
		physics->AddCollider(new AABB(sourceOffset, sourceSize * 0.2f));
		if (imgType == 0)
		{
			renderer = new ImageRenderer(transform, texturePath, sourceOffset, sourceSize);
		}
		else if (imgType == 1)
		{
			renderer = new AnimatedImageRenderer(32, 32, 60, true, transform, texturePath, sourceOffset, sourceSize);
		}
	}
};
