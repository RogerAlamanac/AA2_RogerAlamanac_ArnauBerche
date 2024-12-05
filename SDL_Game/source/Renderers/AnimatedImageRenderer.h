#pragma once
#include "ImageRenderer.h"
class AnimatedImageRenderer : public ImageRenderer
{
private:
	int frameWidth;
	int frameHeight;
	int fps;
	bool looping;
	float currentFrameTime;
	int currentFrame = 1;
	int amountFrames;

	// Coger el width de la imagen i dividirlo entre el Sprite Size para conseguir cuantos frames tiene la animacion, 
	// coger sprite size como offset i multiplicarlo por el frame rate para coger la parte de la imagen que queremos
public:
	AnimatedImageRenderer(int frameWidth, int frameHeight, int fps, bool looping,
		Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize) : ImageRenderer(transform, resourcePath, sourceOffset, sourceSize),
		frameWidth(frameWidth), frameHeight(frameHeight), fps(fps), looping(looping)
	{
		currentFrameTime = 0;
		amountFrames = sourceRect.w / frameWidth;
	}

	virtual void Update(float dt) override;
	virtual void Render() override;

};
