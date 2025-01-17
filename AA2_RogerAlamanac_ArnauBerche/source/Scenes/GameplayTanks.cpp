#include "GameplayTanks.h"
#include "../Elements/Background.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/ShootingEnemy.h"
#include "../Enemies/AimingEnemy.h"
#include "../Player/Tank.h"
#include "SceneManager.h"
#include "../Enemies/BasicEnemy.h"

void GameplayTanks::OnEnter()
{
	SM.currentSceneInt = 2;

	if (!waveManager->LoadFromXML("source/WavesEnemiesTanks.xml")) {
		return;
	}
	waveManager->currentWaveIndex = 0;
	if (!waveManager->waves.empty()) {
		currentWave = waveManager->waves[waveManager->currentWaveIndex];
		amountEnemies = GetTotalEnemies(currentWave);
	}
	SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), SM.imagesToUse[SM.currentSceneInt][0]));
	player = new Tank(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), 100, MAX_LIFES);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));

	score = new Score(Vector2(100, 100), 0);
	score->SetText("Score: " + std::to_string(currentScore));
	SPAWN.SpawnObject(score);
}

void GameplayTanks::OnExit()
{
	Scene::OnExit();
}
int GameplayTanks::GetTotalEnemies(const Wave& wave) {
	int total = 0;
	for (const auto& enemy : wave.enemies) {
		total += enemy.amount;
	}
	return total;
}


void GameplayTanks::Update() 
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
	if (player->GetCurrentLifes() <= 0) {
		SM.SetNextScene("Main Menu");
	}
}

void GameplayTanks::Render()
{
	Scene::Render();
}

void GameplayTanks::SpawnEnemiesFromWave(const Wave& wave) {
	for (EnemyConfig enemy : wave.enemies)
		for (int i = 0; i < enemy.amount; ++i) {
			SpawnEnemyById(enemy);
		}
}
void GameplayTanks::SpawnEnemyById(EnemyConfig enemy)
{
	switch (enemy.id) {
	case 1: {
		Vector2 spawnPos = GenerateSpawnPosition();
		BasicEnemy* enemyBasic = new BasicEnemy(spawnPos, 10, 10, 1, true, SM.imagesToUse[SM.currentSceneInt][1]);
		enemyBasic->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyBasic);
		break;
	}
	case 2: {
		Vector2 spawnPos = GenerateSpawnPosition();
		ShootingEnemy* enemyShoot = new ShootingEnemy(spawnPos, 10, 20, 1, true, SM.imagesToUse[SM.currentSceneInt][1]);
		enemyShoot->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyShoot);
		break;
	}
	}
}

void GameplayTanks::AdvanceToNextWave()
{
	if (waveManager->HasNextWave()) {
		waveManager->LoadNextWave(); 
		enemySpawned = false;

		std::cout << "NEXT WAVE";
		TextObject* nextWave = new TextObject("Wave");
		nextWave->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2);
		nextWave->GetTransform()->scale = Vector2(5, 5);
		nextWave->SetText("NEW WAVE!");
		
	}

}

Vector2 GameplayTanks::GenerateSpawnPosition() {
	return Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT / 3); 
}
std::vector<EnemyConfig> GameplayTanks::GetCurrentWaveEnemies()
{
	return std::vector<EnemyConfig>();
}