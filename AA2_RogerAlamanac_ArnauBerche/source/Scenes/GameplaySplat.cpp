#include "GameplaySplat.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/SeekerEnemy.h"
#include "../Player/Swatter.h"
#include "../Elements/Background.h"
#include "SceneManager.h"
#include "../Enemies/ShootingEnemy.h"

void GameplaySplat::OnEnter()
{
	SM.currentSceneInt = 1;

	if (!waveManager->LoadFromXML("source/WavesEnemiesSplat.xml")) {
		std::cout << "No se ha podido cargar el archivo" << std::endl;
		return;
	}

	waveManager->currentWaveIndex = 0;
	if (!waveManager->waves.empty()) {
		currentWave = waveManager->waves[waveManager->currentWaveIndex];
		amountEnemies = GetTotalEnemies(currentWave);
	}

	SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), SM.imagesToUse[SM.currentSceneInt][0]));
	player = new Swatter(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), MAX_LIFES);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
	score = new Score(Vector2(100, 100), 0);
	score->SetText("Score: " + std::to_string(currentScore));
	SPAWN.SpawnObject(score);
	end = new TextObject("End");
	end->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2 - 50, RM->WINDOW_HEIGHT / 2 + 50);
	end->SetText(" ");
	end->GetTransform()->scale = Vector2(5, 5);
	SPAWN.SpawnObject(end);
}

void GameplaySplat::OnExit()
{
	Scene::OnExit();
}
int GameplaySplat::GetTotalEnemies(const Wave& wave) {
	int total = 0;
	for (const auto& enemy : wave.enemies) {
		total += enemy.amount;
	}
	return total;
}
void GameplaySplat::Update() 
{
	for (int i = _objects.size() - 1; i >= 0; i--) {
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
	
	score->SetText("Score: " + std::to_string(currentScore));

	if (currentScore >= 500) {
		end->SetText("NEW BEST!");
	}
	if (player->GetCurrentLifes() <= 0) {
		SM.SetNextScene("Main Menu");
	}
}

void GameplaySplat::Render()
{
	Scene::Render();
}
void GameplaySplat::SpawnEnemiesFromWave(const Wave& wave) {

	for (auto enemy : wave.enemies)
		for (int i = 0; i < enemy.amount; ++i) {
			SpawnEnemyById(enemy);
		}

}
void GameplaySplat::SpawnEnemyById(EnemyConfig enemy)
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
	case 3: {
		Vector2 spawnPos = GenerateSpawnPosition();
		SeekerEnemy* seekEnemy = new SeekerEnemy(spawnPos, 100, 10, 10, 1000, true, player, SM.imagesToUse[SM.currentSceneInt][1]);
		seekEnemy->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(seekEnemy);
		break;
	}
	}
}

void GameplaySplat::AdvanceToNextWave()
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

Vector2 GameplaySplat::GenerateSpawnPosition() {
	return Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT / 3); 
}
std::vector<EnemyConfig> GameplaySplat::GetCurrentWaveEnemies()
{
	return std::vector<EnemyConfig>();
}