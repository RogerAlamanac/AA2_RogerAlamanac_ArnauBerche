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
void GameplaySpaceInvaders::OnEnter()
{
	
	if (!waveManager->LoadFromXML("source/WavesEnemiesSpaceInvaders.xml")) {
		std::cout<< "No se pudo cargar la configuración de oleadas.\n";
		return;
	}

	currentWaveIndex = 0;
	if (!waveManager->waves.empty()) {
		currentWave = waveManager->waves[currentWaveIndex];
		amountEnemies = GetTotalEnemies(currentWave);
	}

	// Resto de inicializaciones
	//SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
	player = new Spaceship(Vector2(100, 700), MAX_LIFES);
	dynamic_cast<Object*>(player)->GetTransform()->scale = Vector2(0.7f, 0.7f);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
	score = new Score(Vector2(100, 100), 0);
	score->SetText("Score: " + std::to_string(currentScore));
	SPAWN.SpawnObject(score);
	end = new TextObject("End");
	end->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2 - 50, RM->WINDOW_HEIGHT / 2 + 50);
	end->SetText(" ");
	end->GetTransform()->scale = Vector2(5, 5);
	SPAWN.SpawnObject(end);
	AM.LoadSong("illuminati");
	AM.PlaySong("illuminati");
	AM.LoadClip("d");
}

void GameplaySpaceInvaders::OnExit()
{
	Scene::OnExit();
}
int GameplaySpaceInvaders::GetTotalEnemies(const Wave& wave) {
	int total = wave.randomEnemy.amount;
	for (const auto& enemy : wave.enemies) {
		total += enemy.amount;
	}
	return total;
}
void GameplaySpaceInvaders::Update()
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
	//if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned && amountEnemies > 0)
	//{
	//	spawnPosX = rand() % RM->WINDOW_WIDTH + 1;
	//	spawnPosY = rand() % RM->WINDOW_HEIGHT + 1;
	//	SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 50, 10, 1, true));
	//	enemySpawned = true;
	//	amountEnemies--;
	//}
	//else if ((int)TIME.GetElapsedTime() % 5 != 0)
	//{
	//	enemySpawned = false;
	//}
	if (amountEnemies > 0) {
		if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned) {
			// Generar enemigos
			SpawnEnemiesFromWave(currentWave);
			enemySpawned = true;
		}
		else if ((int)TIME.GetElapsedTime() % 5 != 0) {
			enemySpawned = false;
		}
	}
	//bool allEnemiesDefeated = true;
	//for (Object* obj : _objects) {
	//	if (obj->tag == "ENEMY") {
	//		allEnemiesDefeated = false;
	//		break;
	//	}
	//}
	//if (allEnemiesDefeated) {
	//	AdvanceToNextWave();
	//}
	score->SetText("Score: " + std::to_string(currentScore));

	if (currentScore >= 500) {
		end->SetText("NEW BEST!");
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
	// Generar enemigos aleatorios
	if (wave.randomEnemy.amount > 0) {
		BasicEnemy* enemy = new BasicEnemy(Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT), 10, 10, wave.randomEnemy.id, true);
		enemy->SetPattern(wave.randomEnemy.pattern); // Patrón obtenido del XML
		SPAWN.SpawnObject(enemy);
		amountEnemies--;
	}

	// Generar enemigos fijos
	for (const auto& enemy : wave.enemies) {
		for (int i = 0; i < enemy.amount; ++i) {
			BasicEnemy* enemy1 = new BasicEnemy(Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT), 10, 10, enemy.id, true);
			enemy1->SetPattern(enemy.pattern); // Patrón obtenido del XML
			SPAWN.SpawnObject(enemy1);
			amountEnemies--;
		}
	}
}
Vector2 GameplaySpaceInvaders::GenerateSpawnPosition() {
	return Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT / 3); // Genera en la parte superior
}
//std::vector<EnemyConfig> GameplaySpaceInvaders::GetCurrentWaveEnemies(){
//{
//	return std::vector<EnemyConfig>();
//}
//void GameplaySpaceInvaders::AdvanceToNextWave() {
//	if (waveManager->HasNextWave()) {
//		waveManager->LoadNextWave(); // Carga la siguiente oleada desde el WaveManager
//
//		// Generar los enemigos de la nueva oleada
//		for (auto enemyData : waveManager->GetCurrentWaveEnemies()) {
//			for (int i = 0; i < enemyData.amount; i++) {
//				Vector2 spawnPos = GenerateSpawnPosition(); // Genera una posición inicial válida
//				BasicEnemy* enemy = new BasicEnemy(spawnPos, 50.0f, enemyData.health, enemyData.damage, true);
//				SPAWN.SpawnObject(enemy);
//			}
//		}
//	}
//	else {
//		// Si no hay más oleadas, mostrar un mensaje o terminar el nivel
//		end->SetText("YOU WIN!");
//	}
//}

