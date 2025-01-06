#pragma once
#include "Object.h"

#include "../Renderers/TextRenderer.h"

class TextObject : public Object {
private:
	TextRenderer* tr;
	SDL_Rect buttonRect;
	SDL_Color buttonColor = { 0, 0, 255, 255 }; 
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
	void SetButtonColor(SDL_Color color) {
		buttonColor = color;
	}

	SDL_Rect GetRect() const {
		return buttonRect;
	}
	void Render() {

		SDL_SetRenderDrawColor(RM->GetRenderer(), 0, 0,0, 255);
		SDL_RenderFillRect(RM->GetRenderer(), &buttonRect);
		tr->Render();
		
	}
};
