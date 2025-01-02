#pragma once
#include "Object.h"

#include "../Renderers/TextRenderer.h"

class TextObject : public Object {
private:
	TextRenderer* tr;
	SDL_Rect buttonRect;
public:
	TextObject(std::string text) : Object() {
		tr = new TextRenderer(transform, text);
		renderer = tr;
		tr->SetColor(SDL_Color{ 255,255,255,255 });
	}
	void SetText(std::string text) {
		tr->SetText(text);
	}
	void SetRect(SDL_Rect rect) {
		buttonRect = rect;
	}

	SDL_Rect GetRect() const {
		return buttonRect;
	}
	void Render() {
		tr->Render();
	}
};
