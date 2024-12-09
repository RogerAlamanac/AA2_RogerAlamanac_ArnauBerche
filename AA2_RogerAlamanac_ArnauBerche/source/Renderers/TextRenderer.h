#pragma once
#include "SDL.h" //SDL_Texture
#include "SDL_ttf.h" // TTF RenderText Solid
#include "Renderer.h"
#include "RenderManager.h"

#define FONT_PATH "resources/fonts/PixelPowerLine-9xOK.ttf"

class TextRenderer : public Renderer {
protected:
	std::string text;
	SDL_Texture* textTexture;
	bool autoSize = true;
public:
	TextRenderer(Transform* transform, std::string _text) : Renderer(transform, FONT_PATH) {
		SetText(_text);
	}
	virtual void Update(float dt) override {
		Vector2 offset = (Vector2(-transform->size.x, -transform->size.y) / 2.0f) * transform->scale;

		destRect.x = transform->position.x + offset.x;
		destRect.y = transform->position.y + offset.y;
		if (autoSize) {
			destRect.w = sourceRect.w * transform->scale.x;
			destRect.h = sourceRect.h * transform->scale.y;
		}
		else {
			destRect.w = transform->size.x * transform->scale.x;
			destRect.h = transform->size.y * transform->scale.y;
		}
	}
	void SetColor(SDL_Color color) override {
		Renderer::SetColor(color);
		SetText(text);
	}

	virtual void Render() override {
		SDL_RenderCopyEx(RM->GetRenderer(), textTexture, &sourceRect, &destRect, transform->rotation, NULL, SDL_FLIP_NONE);
	}
	void SetText(std::string newText) {
		RM->LoadFont(FONT_PATH);

		//Generate texture
		if (textTexture != nullptr) {
			SDL_DestroyTexture(textTexture);
		}

		SDL_Surface* surf = TTF_RenderText_Solid(RM->GetFont(FONT_PATH), newText.c_str(), color);
		assert(surf);

		textTexture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surf);
		assert(textTexture);

		sourceRect = {
			0,0,
			surf->w, surf->h
		};

		text = newText;
	}
};