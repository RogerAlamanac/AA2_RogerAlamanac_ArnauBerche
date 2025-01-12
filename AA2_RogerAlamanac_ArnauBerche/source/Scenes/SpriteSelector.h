#pragma once
#include "Scene.h"
#include "../Object/ImageObject.h"
#include "../Object/TextObject.h"
#include "../Player/Spaceship.h"
#include "../Player/Tank.h"
#include "../Player/Swatter.h"
class SpriteSelector : public Scene {
private:
	ImageObject* background1;
	ImageObject* background2;
	ImageObject* background3;
	ImageObject* enemies1;
	ImageObject* enemies2;
	ImageObject* enemies3;
	ImageObject* VFX1;
	ImageObject* VFX2;
	ImageObject* VFX3;
	TextObject* back;
	TextObject* title;
	std::vector<ImageObject*> sprites;

	Vector2 initialPos = Vector2((RM->WINDOW_WIDTH / 5), 200);
	Vector2 previousSpritePos = initialPos;
	
public:
	SpriteSelector() {
		background1 = new ImageObject("resources/background_space.jpg", Vector2(0.f, 0.f), Vector2(2000.f, 1125.f), 0, "SPRITE");
		sprites.push_back(background1);
		background2 = new ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(background2);
		background3 = new ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(background3);
		enemies1 = new ImageObject("resources/basicenemy.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(enemies1);
		enemies2 = new ImageObject("resources/Swatter.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(enemies2);
		enemies3 = new ImageObject("resources/Swatter.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(enemies3);
		VFX1 = new ImageObject("resources/circle.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(VFX1);
		VFX2 = new ImageObject("resources/none.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(VFX2);
		VFX3 = new ImageObject("resources/tank body.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		sprites.push_back(VFX3);

		back = new TextObject("Main Menu");
		title = new TextObject("Sprite Selector");
	};
	~SpriteSelector() {
		for (ImageObject* sprite : sprites) {
			delete sprite;
		}
	}
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;

	bool IsMouseOverObject(ImageObject* object, int mouseX, int mouseY) {
		SDL_Rect rect = {
			static_cast<int>(object->GetTransform()->position.x),
			static_cast<int>(object->GetTransform()->position.y),
			static_cast<int>(object->GetTransform()->scale.x),
			static_cast<int>(object->GetTransform()->scale.y)
		};
		return (mouseX > (rect.x - 50) && mouseX < (rect.x + rect.w) && mouseY > (rect.y-50) && mouseY < (rect.y + rect.w));
	}
	bool IsMouseOverButton(SDL_Rect buttonRect, int mouseX, int mouseY) {
		return (mouseX > buttonRect.x &&
			mouseX < (buttonRect.x + buttonRect.w) &&
			mouseY > buttonRect.y &&
			mouseY < (buttonRect.y + buttonRect.h));
	}
};