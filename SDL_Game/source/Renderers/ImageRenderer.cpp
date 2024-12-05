#include "ImageRenderer.h"

 void ImageRenderer::Update(float dt) 
{
	destRect.x = transform->position.x;
	destRect.y = transform->position.y;

	destRect.w = sourceRect.w * transform->scale.x;
	destRect.h = sourceRect.h * transform->scale.y;
}

void ImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), RM->GetTexture(targetPath), &sourceRect, &destRect);
}
