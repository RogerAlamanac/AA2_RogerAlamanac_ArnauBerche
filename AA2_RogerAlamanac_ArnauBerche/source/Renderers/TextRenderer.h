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
	void SetColor(SDL_Color color) override {
		Renderer::SetColor(color);
		SetText(text);
	}
	virtual void Update(float dt) override {
		Vector2 offset = (Vector2(-transform->size.x, -transform->size.y) / 2.0f) * transform->scale;

		destRect.x = (int)transform->position.x + (int)offset.x;
		destRect.y = (int)transform->position.y + (int)offset.y;
		if (autoSize) {
			destRect.w = (int)sourceRect.w * (int)transform->scale.x;
			destRect.h = (int)sourceRect.h * (int)transform->scale.y;
		}
		else {
			destRect.w = (int)transform->size.x * (int)transform->scale.x;
			destRect.h = (int)transform->size.y * (int)transform->scale.y;
		}

	}

	virtual void Render() override {
		SDL_RenderCopyEx(
			RM->GetRenderer(),
			textTexture,
			&sourceRect,
			&destRect,
			transform->rotation,
			NULL,
			SDL_FLIP_NONE);
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