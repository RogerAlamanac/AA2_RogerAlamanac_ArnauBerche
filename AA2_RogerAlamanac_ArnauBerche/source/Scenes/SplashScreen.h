#pragma once
#include "Scene.h"
#include "../Object/ImageObject.h"
#include "../Object/TextObject.h"
class SplashScreen : public Scene {
private:
	ImageObject* companyLogo;
	TextObject* presentTitle;
	float timeToGoToMainMenu = 3.0f;
	float timeSinceStarted = 0.0f;
public:
	SplashScreen() = default;
	~SplashScreen();
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};