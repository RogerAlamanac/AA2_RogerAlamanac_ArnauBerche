#include "Ranking.h"
#include "../Spawner/Spawner.h"
#include "../InputManager/InputManager.h"
#include "SceneManager.h"

void Ranking::OnEnter()
{
    LoadRankingsFromFile();

	title = new TextObject(" ");
	title->SetText("RANKING");
	title->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2), 100);
	SPAWN.SpawnObject(title);

	space = new TextObject(" ");
	space->SetText("Space HighScores");
	space->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 500, 200);
	SPAWN.SpawnObject(space);

	tank = new TextObject(" ");
	tank->SetText("Tank HighScores");
	tank->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2)-50, 200);
	SPAWN.SpawnObject(tank);

	splat = new TextObject(" ");
	splat->SetText("Splat HighScores");
	splat->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) + 400, 200);
	SPAWN.SpawnObject(splat);

    if (!spaceHighscores.empty())
    {
        std::vector<std::pair<std::string, int>> sortedScores(spaceHighscores.begin(), spaceHighscores.end());

        for (size_t i = 0; i < sortedScores.size(); ++i) {
            size_t maxIndex = i;
            for (size_t j = i + 1; j < sortedScores.size(); ++j) {
                if (sortedScores[j].second > sortedScores[maxIndex].second) {
                    maxIndex = j;
                }
            }
            if (maxIndex != i) {
                std::pair<std::string, int> temp = sortedScores[i];
                sortedScores[i] = sortedScores[maxIndex];
                sortedScores[maxIndex] = temp;
            }
        }

        int count = 0;
        for (const auto& entry : sortedScores) {
            TextObject* scoreX = new TextObject(" ");
            scoreX->SetText(entry.first);
            scoreX->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 500, 300 + (count * 50));
            SPAWN.SpawnObject(scoreX);

            TextObject* scoreY = new TextObject(" ");
            scoreY->SetText(std::to_string(entry.second));
            scoreY->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 400, 300 + (count * 50));
            SPAWN.SpawnObject(scoreY);

            ++count;
        }
    }

    if (!tankHighscores.empty())
    {
        std::vector<std::pair<std::string, int>> sortedScores(tankHighscores.begin(), tankHighscores.end());

        for (size_t i = 0; i < sortedScores.size(); ++i) {
            size_t maxIndex = i;
            for (size_t j = i + 1; j < sortedScores.size(); ++j) {
                if (sortedScores[j].second > sortedScores[maxIndex].second) {
                    maxIndex = j;
                }
            }
            if (maxIndex != i) {
                std::pair<std::string, int> temp = sortedScores[i];
                sortedScores[i] = sortedScores[maxIndex];
                sortedScores[maxIndex] = temp;
            }
        }

        int count = 0;
        for (const auto& entry : sortedScores) {
            TextObject* scoreX = new TextObject(" ");
            scoreX->SetText(entry.first);
            scoreX->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) , 300 + (count * 50));
            SPAWN.SpawnObject(scoreX);

            TextObject* scoreY = new TextObject(" ");
            scoreY->SetText(std::to_string(entry.second));
            scoreY->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) + 100, 300 + (count * 50));
            SPAWN.SpawnObject(scoreY);

            ++count;
        }
    }

     if (!splatHighscores.empty())
    {
        std::vector<std::pair<std::string, int>> sortedScores(splatHighscores.begin(), splatHighscores.end());

        for (size_t i = 0; i < sortedScores.size(); ++i) {
            size_t maxIndex = i;
            for (size_t j = i + 1; j < sortedScores.size(); ++j) {
                if (sortedScores[j].second > sortedScores[maxIndex].second) {
                    maxIndex = j;
                }
            }
            if (maxIndex != i) {
                std::pair<std::string, int> temp = sortedScores[i];
                sortedScores[i] = sortedScores[maxIndex];
                sortedScores[maxIndex] = temp;
            }
        }

        int count = 0;
        for (const auto& entry : sortedScores) {
            TextObject* scoreX = new TextObject(" ");
            scoreX->SetText(entry.first);
            scoreX->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) + 500, 300 + (count * 50));
            SPAWN.SpawnObject(scoreX);

            TextObject* scoreY = new TextObject(" ");
            scoreY->SetText(std::to_string(entry.second));
            scoreY->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) + 600, 300 + (count * 50));
            SPAWN.SpawnObject(scoreY);

            ++count;
        }
    }
}

void Ranking::OnExit()
{
	Scene::OnExit();
}

void Ranking::Update()
{
	Scene::Update();
    if (IM.GetEvent(SDLK_ESCAPE, DOWN)) {
        SM.SetNextScene("Main Menu");
    }
}

void Ranking::Render()
{
	Scene::Render();
}

bool Ranking::IsHighScore(const std::string& game, int score) {
    std::map<std::string, int>* highScores;

    if (game == "Space") highScores = &spaceHighscores;
    else if (game == "Tank") highScores = &tankHighscores;
    else if (game == "Splat") highScores = &splatHighscores;
    else return false;

    if (highScores->size() < 10) return true;

    for (const auto& entry : *highScores) {
        if (score > entry.second) return true;
    }
    return false;
}

void Ranking::AddHighScore(const std::string& game, const std::string& initials, int score) {
    std::map<std::string, int>* highScores;

    if (game == "Space") highScores = &spaceHighscores;
    else if (game == "Tank") highScores = &tankHighscores;
    else if (game == "Splat") highScores = &splatHighscores;
    else return;

    (*highScores)[initials] = score;

    if (highScores->size() > 10) {
        auto minIt = std::min_element(highScores->begin(), highScores->end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });
        highScores->erase(minIt);
    }

    SaveRankingsToFile();
}

void Ranking::SaveRankingsToFile() {
    std::ofstream outFile(saveFile, std::ios::binary | std::ios::out);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for saving highscores!" << std::endl;
        return;
    }

    auto saveGameScores = [&](const std::map<std::string, int>& highscores, const std::string& gameType) {
        for (const auto& entry : highscores) {
            HighScoreEntry scoreEntry;
            strncpy_s(scoreEntry.initials, sizeof(scoreEntry.initials), entry.first.c_str(), _TRUNCATE);


            scoreEntry.score = entry.second;

            strncpy_s(scoreEntry.gameType, sizeof(scoreEntry.gameType), gameType.c_str(), _TRUNCATE);


            outFile.write(reinterpret_cast<char*>(&scoreEntry), sizeof(HighScoreEntry));
        }
        };

    saveGameScores(spaceHighscores, "Space");
    saveGameScores(tankHighscores, "Tank");
    saveGameScores(splatHighscores, "Splat");

    outFile.close();
    std::cout << "Highscores saved successfully!" << std::endl;
}

void Ranking::LoadRankingsFromFile() {
    std::ifstream inFile(saveFile, std::ios::binary | std::ios::in);
    if (!inFile.is_open()) {
        std::cerr << "No existing highscore file found. Starting fresh!" << std::endl;
        return;
    }

    HighScoreEntry scoreEntry;
    while (inFile.read(reinterpret_cast<char*>(&scoreEntry), sizeof(HighScoreEntry))) {
        std::string initials(scoreEntry.initials);
        std::string gameType(scoreEntry.gameType);

        if (gameType == "Space") {
            spaceHighscores[initials] = scoreEntry.score;
        }
        else if (gameType == "Tank") {
            tankHighscores[initials] = scoreEntry.score;
        }
        else if (gameType == "Splat") {
            splatHighscores[initials] = scoreEntry.score;
        }
    }

    inFile.close();
    std::cout << "Highscores loaded successfully!" << std::endl;
}
