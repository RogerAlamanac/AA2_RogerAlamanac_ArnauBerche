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

void GameplaySpaceInvaders::OnEnter()
{
	SM.currentSceneInt = 0;

	if (!waveManager->LoadFromXML("source/WavesEnemiesSpaceInvaders.xml")) {
		std::cout << "No se ha podido cargar el archivo" << std::endl;
		return;
	}

	waveManager->currentWaveIndex = 0;
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

	
	AM.PlaySong("illuminati");

}

void GameplaySpaceInvaders::OnExit()
{
	AM.StopAudio();
	waveManager->currentWaveIndex = 0;
	waveManager->waves.clear();
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
	std::cout << amountEnemies << std::endl;
	if (amountEnemies > 0) {
		for (const auto& enemy : currentWave.enemies) {
			if (!enemySpawned) {

				SpawnEnemiesFromWave(currentWave);
				enemySpawned = true;
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
	}
	
	 if(IM.GetEvent(SDLK_ESCAPE, DOWN) ) {
		SM.SetNextScene("Main Menu");
	 }

	if (player->GetCurrentLifes() <= 0) {
		SM.SetNextScene("Main Menu");
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
		BasicEnemy* enemyBasic = new BasicEnemy(spawnPos, 5, 10, 1, true, SM.imagesToUse[SM.currentSceneInt][1]);
		enemyBasic->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyBasic);
		break;
	}
	case 2: {
		Vector2 spawnPos = GenerateSpawnPosition(); 
		ShootingEnemy* enemyShoot = new ShootingEnemy(spawnPos, 5, 20, 1, true, SM.imagesToUse[SM.currentSceneInt][1]);
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

		end->SetText("YOU WIN!");
	}
}

Vector2 GameplaySpaceInvaders::GenerateSpawnPosition() {
	return Vector2((float)(rand() % RM->WINDOW_WIDTH), (float)(rand() % RM->WINDOW_HEIGHT / 3));
}
std::vector<EnemyConfig> GameplaySpaceInvaders::GetCurrentWaveEnemies()
{
	return std::vector<EnemyConfig>();
}


