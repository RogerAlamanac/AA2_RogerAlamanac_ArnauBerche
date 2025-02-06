#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include <map>
#include <string>
#include <vector>
#include <fstream>

class Ranking : public Scene {
private:
	TextObject* title;
	TextObject* space;
	std::map<std::string, int> spaceHighscores;

	TextObject* tank;
	std::map<std::string, int> tankHighscores;

	TextObject* splat;
	std::map<std::string, int> splatHighscores;

	const std::string saveFile = "highscores.bin";

	struct HighScoreEntry {
		char initials[4];
		int score;
		char gameType[10];
	};

public:
	Ranking() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;

	bool IsHighScore(const std::string& game, int score);
	void AddHighScore(const std::string& game, const std::string& initials, int score);

	void SaveRankingsToFile();
	void LoadRankingsFromFile();
};