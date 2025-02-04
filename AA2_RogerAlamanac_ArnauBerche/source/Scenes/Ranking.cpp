#include "Ranking.h"
#include "../Spawner/Spawner.h"

void Ranking::OnEnter()
{
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

    spaceHighscores["ABA"] = 150;
    spaceHighscores["ACC"] = 300;
    spaceHighscores["ATT"] = 200;
    spaceHighscores["AHH"] = 450;

    tankHighscores["BBB"] = 500;
    tankHighscores["BAA"] = 400;
    tankHighscores["KDU"] = 300;
    tankHighscores["HJD"] = 200;

    splatHighscores["HDY"] = 500;
    splatHighscores["HDS"] = 400;
    splatHighscores["JCS"] = 300;
    splatHighscores["FAR"] = 200;

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
}

void Ranking::Render()
{
	Scene::Render();
}
