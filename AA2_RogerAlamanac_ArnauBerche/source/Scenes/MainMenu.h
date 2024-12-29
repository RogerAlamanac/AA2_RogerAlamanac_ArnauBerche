#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include "../Renderers/TextRenderer.h"
class MainMenu : public Scene {
private:
	Object* title;
	Object* option1;
	Object* option2;
	Object* option3;
public:
	MainMenu() {
		title = new TextObject("Main Menu");
		option1 = new TextObject("1. Space Invaders");
		option2 = new TextObject("2. Tanks");
		option3 = new TextObject("3. Splat");
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
};