#pragma once
#include "Renderer.h"
#include "RenderManager.h"
#include "../Object/Transform.h"
class ImageRenderer : public Renderer {
public:
	ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize) : Renderer(transform, resourcePath) {
		RM->GetTexture(resourcePath);

		sourceRect = SDL_Rect{
			(int)sourceOffset.x,
			(int)sourceOffset.y,
			(int)sourceSize.x,
			(int)sourceSize.y
		};

		destRect = SDL_Rect{
			(int)transform->position.x,
			(int)transform->position.y,
			(int)transform->scale.x,
			(int)transform->scale.y
		};
	}

	virtual void Update(float dt) override;
	virtual void Render();
};