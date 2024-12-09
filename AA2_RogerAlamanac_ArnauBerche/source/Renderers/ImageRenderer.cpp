#include "ImageRenderer.h"

 void ImageRenderer::Update(float dt) 
{
	 Vector2 offset = (Vector2(-transform->size.x, -transform->size.y) / 2.0f) * transform->scale;

	destRect.x = transform->position.x + offset.x;
	destRect.y = transform->position.y + offset.y;

	destRect.w = transform->size.x * transform->scale.x;
	destRect.h = transform->size.y * transform->scale.y;
}

void ImageRenderer::Render()
{
	SDL_RenderCopyEx(RM->GetRenderer(), RM->GetTexture(targetPath), &sourceRect, &destRect, transform->rotation, NULL, SDL_FLIP_NONE);
}
