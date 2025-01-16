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

	ImageObject* spaceInvaders;
	ImageObject* tank;
	ImageObject* swater;
	std::vector<ImageObject*> hoverSprites;

	
public:
	SpriteSelector() = default;
	~SpriteSelector() {
		for (ImageObject* sprite : sprites) {
			delete sprite;
		}
		sprites.clear();
		for (ImageObject* sprite : hoverSprites) {
			delete sprite;
		}
		hoverSprites.clear();
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
		return (mouseX > (rect.x - 50) && mouseX < (rect.x + rect.w) && mouseY > (rect.y-50) && mouseY < (rect.y + rect.h));
	}
	bool IsMouseOverButton(SDL_Rect buttonRect, int mouseX, int mouseY) {
		return (mouseX > buttonRect.x &&
			mouseX < (buttonRect.x + buttonRect.w) &&
			mouseY > buttonRect.y &&
			mouseY < (buttonRect.y + buttonRect.h));
	}
};