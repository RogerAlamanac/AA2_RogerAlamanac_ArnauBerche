#include "AnimatedImageRenderer.h"

void AnimatedImageRenderer::Update(float dt)
{
	destRect.x = transform->position.x;
	destRect.y = transform->position.y;
	if (currentFrameTime >= fps)
	{
		currentFrame++;
		currentFrameTime = 0;
	}

	if (currentFrame >= amountFrames)
	{
		if (looping)
		{
			currentFrame = 1;
		}
		else
		{
			currentFrame = amountFrames;
		}
	}


	sourceRect.x = frameWidth * (currentFrame - 1);
	sourceRect.w = frameWidth;
	sourceRect.h = frameHeight;

	destRect.w = sourceRect.w * transform->scale.x;
	destRect.h = sourceRect.h * transform->scale.y;
	currentFrameTime += dt;
}

void AnimatedImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), RM->GetTexture(targetPath), &sourceRect, &destRect);
}
