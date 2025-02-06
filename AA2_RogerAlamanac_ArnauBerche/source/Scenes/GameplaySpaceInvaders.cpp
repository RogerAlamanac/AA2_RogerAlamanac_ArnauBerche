#include "GameplaySpaceInvaders.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/BasicEnemy.h"
#include "../Player/Spaceship.h"
#include "../Object/TextObject.h"
#include "../Elements/Background.h"
#include "../Elements/Bullet.h"
#include <iostream>
#include "SceneManager.h"
#include "../Audio/AudioManager.h"
#include "../Enemies/ShootingEnemy.h"
#include "../Scenes/SceneManager.h"
#include "../InputManager/InputManager.h"
#include "../Scenes/Ranking.h"
#include "../Scenes/HighScoreInput.h"

void GameplaySpaceInvaders::OnEnter()
{
	SM.currentSceneInt = 0;

	waveManager->waves.clear(); 
	if (!waveManager->LoadFromXML("source/WavesEnemiesSpaceInvaders.xml")) {
		std::cout << "No se ha podido cargar el archivo" << std::endl;
		return;
	}

	waveManager->currentWaveIndex = 0;
	enemySpawned = false;

	if (!waveManager->waves.empty()) {
		currentWave = waveManager->waves[waveManager->currentWaveIndex];
		amountEnemies = GetTotalEnemies(currentWave);
	}

	SPAWN.SpawnObject(new Background(Vector2((float)RM->WINDOW_WIDTH / 2, (float)RM->WINDOW_HEIGHT / 2), SM.imagesToUse[SM.currentSceneInt][0]));

	player = new Spaceship(Vector2(100, 700), MAX_LIFES);
	dynamic_cast<Object*>(player)->GetTransform()->scale = Vector2(0.7f, 0.7f);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
	score = new Score(Vector2(100, 100), 0);
	score->SetText("Score: " + std::to_string(currentScore));
	SPAWN.SpawnObject(score);
	lifes = new TextObject(" ");
	lifes->SetText("LIFES: " + std::to_string(player->GetCurrentLifes()));
	lifes->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2, 100);
	SPAWN.SpawnObject(lifes);
	end = new TextObject(" ");
	end->SetText(" ");
	end->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2);
	end->GetTransform()-> scale = Vector2(2.f, 2.f);
	AM.PlaySong("illuminati");

}

void GameplaySpaceInvaders::OnExit()
{
	AM.StopAudio();
	waveManager->currentWaveIndex = 0;
	waveManager->waves.clear();
	currentScore = 0;
	Scene::OnExit();
}
int GameplaySpaceInvaders::GetTotalEnemies(const Wave& wave) {
	int total = 0;
	for (const auto& enemy : wave.enemies) {
		total += enemy.amount;
	}
	return total;
}
void GameplaySpaceInvaders::Update()
{
		for (int i = (int)_objects.size() - 1; i >= 0; i--) {
			if (_objects[i]->IsPendingDestroy()) {
				if (_objects[i]->tag == "ENEMY") {
					currentScore += 100;
					amountEnemies--;
				}
			}
			if (_objects[i]->tag == "ENEMY") {
				_objects[i]->GetTransform()->scale = Vector2(0.7f, 0.7f);
			}
		}
	Scene::Update();
	std::cout << waveManager->currentWaveIndex << std::endl;
	if (amountEnemies > 0) {
		for (const auto& enemy : currentWave.enemies) {
			if (!enemySpawned) {

				SpawnEnemiesFromWave(currentWave);
				enemySpawned = true;
				std::cout << "Enemy Spawned" << std::endl;
			}		
		}
	}
	else 
	{
		AdvanceToNextWave();
		if (!waveManager->waves.empty()) {
			currentWave = waveManager->waves[waveManager->currentWaveIndex];
			amountEnemies = GetTotalEnemies(currentWave);
		} 
		else{
			SM.SetNextScene("Main Menu");
		}
	}

	score->SetText("Score: " + std::to_string(currentScore));
	lifes->SetText("LIFES: " + std::to_string(player->GetCurrentLifes()));

	 if(IM.GetEvent(SDLK_ESCAPE, DOWN) ) {
		SM.SetNextScene("Main Menu");
	 }

	 if (player->GetCurrentLifes() <= 0) {
		 Ranking* rankingScene = dynamic_cast<Ranking*>(SM.GetScene("Ranking"));
		 if (rankingScene && rankingScene->IsHighScore("Space", currentScore)) {
			 HighScoreInput* highScoreScene = dynamic_cast<HighScoreInput*>(SM.GetScene("HighScoreInput"));
			 if (highScoreScene) {
				 highScoreScene->SetGameData("Space", currentScore);
				 SM.SetNextScene("HighScoreInput");
			 }
		 }
		 else {
			 SM.SetNextScene("Main Menu");
		 }
	 }
}

void GameplaySpaceInvaders::Render()
{
	Scene::Render();
}

void GameplaySpaceInvaders::SpawnEnemiesFromWave(const Wave& wave) {
	for(auto enemy : wave.enemies)
		for (int i = 0; i < enemy.amount; ++i) {
			SpawnEnemyById(enemy);
		}
}
void GameplaySpaceInvaders::SpawnEnemyById(EnemyConfig enemy)
{
	switch (enemy.id) {
	case 1: {
		Vector2 spawnPos = GenerateSpawnPosition(); 
		BasicEnemy* enemyBasic = new BasicEnemy(spawnPos, 50, 10, 1, true, SM.imagesToUse[SM.currentSceneInt][1]);
		enemyBasic->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyBasic);
		break;
	}
	case 2: {
		Vector2 spawnPos = GenerateSpawnPosition(); 
		ShootingEnemy* enemyShoot = new ShootingEnemy(spawnPos, 50, 20, 1, true, SM.imagesToUse[SM.currentSceneInt][1]);
		enemyShoot->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyShoot);
		break;
	}
	}
}

void GameplaySpaceInvaders::AdvanceToNextWave()
{
	if (waveManager->HasNextWave()) {
		waveManager->LoadNextWave();
		enemySpawned = false;
		std::cout << "NEXT WAVE";
	}
	else {
		// Player completed all waves
		Ranking* rankingScene = dynamic_cast<Ranking*>(SM.GetScene("Ranking"));
		if (rankingScene && rankingScene->IsHighScore("Space", currentScore)) {
			HighScoreInput* highScoreScene = dynamic_cast<HighScoreInput*>(SM.GetScene("HighScoreInput"));
			if (highScoreScene) {
				highScoreScene->SetGameData("Space", currentScore);
				SM.SetNextScene("HighScoreInput");
			}
		}
		else {
			SM.SetNextScene("Main Menu");
		}
	}
}



void GameplaySpaceInvaders::SaveScoreToRanking(const std::string& playerName)
{
	/*std::string filename = "ranking.bin";
	std::vector<Player> ranking = loadRanking(filename);

	addPlayerToRanking(ranking, playerName, currentScore);
	saveRanking(ranking, filename);*/
}

Vector2 GameplaySpaceInvaders::GenerateSpawnPosition() {
	return Vector2((float)(rand() % RM->WINDOW_WIDTH), (float)(rand() % RM->WINDOW_HEIGHT / 3));
}
std::vector<EnemyConfig> GameplaySpaceInvaders::GetCurrentWaveEnemies()
{
	return std::vector<EnemyConfig>();
}


