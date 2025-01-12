#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include "../Renderers/TextRenderer.h"
class MainMenu : public Scene {
private:
	TextObject* title;
	TextObject* option1;
	TextObject* option2;
	TextObject* option3;
	TextObject* sprites;
public:
	MainMenu() {
		title = new TextObject("MainMenu");
		option1 = new TextObject("Space Invaders");
		option2 = new TextObject("Tanks");
		option3 = new TextObject("Splat");
	}
	~MainMenu() {
		delete title;
		delete option1;
		delete option2;
		delete option3;
	}
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
	bool IsMouseOverButton(SDL_Rect buttonRect, int mouseX, int mouseY) {
		return (mouseX > buttonRect.x &&
			mouseX < (buttonRect.x + buttonRect.w) &&
			mouseY > buttonRect.y &&
			mouseY < (buttonRect.y + buttonRect.h));
	}
};