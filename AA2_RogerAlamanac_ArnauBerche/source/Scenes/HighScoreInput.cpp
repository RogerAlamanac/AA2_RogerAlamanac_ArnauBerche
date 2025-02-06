#include "HighScoreInput.h"
#include "SceneManager.h"
#include "Ranking.h"
#include "../InputManager/InputManager.h"
#include "../Spawner/Spawner.h"

HighScoreInput::HighScoreInput() : gameType(""), playerScore(0), playerInitials("") {}

void HighScoreInput::OnEnter() {
    promptText = new TextObject("Enter your initials (3 letters): ");
    promptText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2 - 200, RM->WINDOW_HEIGHT / 2 - 50);
    SPAWN.SpawnObject(promptText);

    initialsText = new TextObject("_ _ _");
    initialsText->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2 - 50, RM->WINDOW_HEIGHT / 2 + 50);
    SPAWN.SpawnObject(initialsText);
}

void HighScoreInput::Update() {
    Scene::Update();
    std::cout << "HighScoreInput Update running..." << std::endl;

    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        if (IM.GetEvent(SDLK_a + (letter - 'A'), DOWN) && playerInitials.length() < 3) {
            playerInitials += letter;
            std::cout << "Key Pressed: " << letter << ", Current Initials: " << playerInitials << std::endl;
            initialsText->SetText(playerInitials);
        }
    }

    if (IM.GetEvent(SDLK_BACKSPACE, DOWN) && !playerInitials.empty()) {
        playerInitials.pop_back();
        std::cout << "Backspace pressed. Current Initials: " << playerInitials << std::endl;
        initialsText->SetText(playerInitials.empty() ? "_ _ _" : playerInitials);
    }

    if (playerInitials.length() == 3 && IM.GetEvent(SDLK_RETURN, DOWN)) {
        std::cout << "Submitting initials: " << playerInitials << std::endl;

        Ranking* rankingScene = dynamic_cast<Ranking*>(SM.GetScene("Ranking"));
        if (rankingScene) {
            rankingScene->AddHighScore(gameType, playerInitials, playerScore);
            std::cout << "High score added for " << gameType << " with score " << playerScore << std::endl;
        }
        else {
            std::cout << "Ranking scene not found!" << std::endl;
        }

        SM.SetNextScene("Ranking");
        std::cout << "Switched to Ranking scene." << std::endl;
    }
}

void HighScoreInput::Render() {
    Scene::Render();
}

void HighScoreInput::OnExit() {
    playerInitials.clear();
    initialsText = new TextObject("_ _ _");
    Scene::OnExit();
}

void HighScoreInput::SetGameData(const std::string& game, int score) {
    gameType = game;
    playerScore = score;
}
