#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "../Object/Transform.h"

class Renderer {
protected:
	SDL_Color color;
	Transform* transform;
	SDL_Rect sourceRect;
	SDL_Rect destRect;
	std::string targetPath;

public:
	Renderer(Transform* t, std::string targetPath) {
		this->transform = t;
		this->targetPath = targetPath;
	}

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

	virtual void SetColor(SDL_Color color) { this->color = color; }
	inline SDL_Color GetColor() { return color; }
};