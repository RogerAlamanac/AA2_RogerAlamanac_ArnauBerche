#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include "../Renderers/TextRenderer.h"
class MainMenu : public Scene {
public:
	MainMenu() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};