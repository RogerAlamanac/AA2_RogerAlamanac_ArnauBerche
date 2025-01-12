#pragma once
#include "Scene.h"
#include "../Object/ImageObject.h"
#include "../Object/TextObject.h"
#include "../Player/Spaceship.h"
#include "../Player/Tank.h"
#include "../Player/Swatter.h"
class SpriteSelector : public Scene {
private:
	ImageObject* Background1;
	ImageObject* Background2;
	ImageObject* Background3;
	ImageObject* Enemies1;
	ImageObject* Enemies2;
	ImageObject* Enemies3;
	ImageObject* VFX1;
	ImageObject* VFX2;
	ImageObject* VFX3;
public:
	SpriteSelector() {
		Background1 = new ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		Background2 = new ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		Background3 = new ImageObject("resources/Spaceship.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
		Enemies1 = new ImageObject("resources/Tank.png", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "SPRITE");
	};
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};