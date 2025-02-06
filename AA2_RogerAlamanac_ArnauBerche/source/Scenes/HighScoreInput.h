#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include <string>

class HighScoreInput : public Scene {
private:
    TextObject* promptText;
    TextObject* initialsText;
    std::string playerInitials;
    int playerScore;
    std::string gameType;

public:
    HighScoreInput();
    HighScoreInput(const std::string& game, int score)
        : gameType(game), playerScore(score), playerInitials("") {}

    void OnEnter() override;
    void Update() override;
    void Render() override;
    void OnExit() override;

    void SetGameData(const std::string& game, int score);

};