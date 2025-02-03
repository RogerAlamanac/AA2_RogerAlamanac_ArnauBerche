#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include <map>
#include <string>
class Ranking : public Scene {
private:
	TextObject* title;
	TextObject* space;
	std::map<std::string, int> spaceHighscores;

	TextObject* tank;
	std::map<std::string, int> tankHighscores;

	TextObject* splat;
	std::map<std::string, int> splatHighscores;

public:
	Ranking() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};