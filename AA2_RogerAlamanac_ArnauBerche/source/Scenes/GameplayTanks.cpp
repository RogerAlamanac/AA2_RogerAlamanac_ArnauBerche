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
	if (needsDefault)
	{
		ClearITU();
		imagesToUse[0].push_back("resources/images/Tanks/background-tanks1.png");
		imagesToUse[0].push_back("resources/images/Tanks/background-tanks1.png");
		imagesToUse[0].push_back("resources/images/Tanks/background-tanks1.png");
		needsDefault = false;
	}
	if (!waveManager->LoadFromXML("source/WavesEnemiesSpaceInvaders.xml")) {
		return;
	}
	waveManager->currentWaveIndex = 0;
	if (!waveManager->waves.empty()) {
		currentWave = waveManager->waves[waveManager->currentWaveIndex];
		amountEnemies = GetTotalEnemies(currentWave);
	}
	SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), "hi"));
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
			}
		}
		if (_objects[i]->tag == "ENEMY") {
			_objects[i]->GetTransform()->scale = Vector2(0.7f, 0.7f);
		}
	}
	Scene::Update();

	//int spawnPosX;
	//int spawnPosY;
	//int randomEnemy;
	//if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned && amountEnemies > 0)
	//{
	//	spawnPosX = rand() % RM->WINDOW_WIDTH + 1;
	//	spawnPosY = rand() % RM->WINDOW_HEIGHT + 1;
	//	randomEnemy = (rand() % 2 + 1);
	//	switch (randomEnemy)
	//	{
	//	case 1:
	//		SPAWN.SpawnObject(new ShootingEnemy(Vector2(90, -90), 100, 10, 1, true));
	//		break;
	//	case 2:
	//		SPAWN.SpawnObject(new AimingEnemy(Vector2(spawnPosX, spawnPosY), 100, 10, 10, true, player));
	//		break;
	//	default:
	//		break;
	//	}
	//	enemySpawned = true;
	//	amountEnemies--;
	//}
	//else if ((int)TIME.GetElapsedTime() % 5 != 0)
	//{
	//	enemySpawned = false;
	//}
	std::cout << amountEnemies << std::endl;
	if (amountEnemies > 0) {
		for (const auto& enemy : currentWave.enemies) {
			if (!enemySpawned) {
				// Generar enemigos
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

	if ((int)TIME.GetElapsedTime() % 3 == 0 && !randomSpawned) {
		amountEnemies++;
		SpawnEnemyById(currentWave.randomEnemy);
		randomSpawned = true;
	}
	else
	{
		randomSpawned = false;
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
	// Generar enemigos fijos
	for (auto enemy : wave.enemies)
		for (int i = 0; i < enemy.amount; ++i) {
			SpawnEnemyById(enemy);
		}

	// Generar enemigos fijos
	for (auto enemy : wave.enemies)
		for (int i = 0; i < enemy.amount; ++i) {
			SpawnEnemyById(enemy);
			amountEnemies--;
		}

}
void GameplayTanks::SpawnEnemyById(EnemyConfig enemy)
{
	switch (enemy.id) {
	case 1: {
		Vector2 spawnPos = GenerateSpawnPosition();
		BasicEnemy* enemyBasic = new BasicEnemy(spawnPos, 10, 10, 1, true);
		enemyBasic->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyBasic);
		break;
	}
	case 2: {
		Vector2 spawnPos = GenerateSpawnPosition();
		ShootingEnemy* enemyShoot = new ShootingEnemy(spawnPos, 10, 20, 1, true);
		enemyShoot->SetPattern(enemy.pattern);
		SPAWN.SpawnObject(enemyShoot);
		break;
	}
	}
}

void GameplayTanks::AdvanceToNextWave()
{
	if (waveManager->HasNextWave()) {
		waveManager->LoadNextWave(); // Carga la siguiente oleada desde el WaveManager
		enemySpawned = false;

		std::cout << "NEXT WAVE";
	}
	//else {
	//	// Si no hay más oleadas, mostrar un mensaje o terminar el nivel
	//	end->SetText("YOU WIN!");
	//}
}

Vector2 GameplayTanks::GenerateSpawnPosition() {
	return Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT / 3); // Genera en la parte superior
}
std::vector<EnemyConfig> GameplayTanks::GetCurrentWaveEnemies()
{
	return std::vector<EnemyConfig>();
}