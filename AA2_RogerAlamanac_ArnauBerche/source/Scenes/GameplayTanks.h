#pragma once
#include "Scene.h"
#include "../UI/Score.h"
#include "../WaveManager.h" 
class GameplayTanks : public Scene {
private:
	bool enemySpawned = false;
	bool randomSpawned = false;
	int amountEnemies = 20;
	int currentScore = 0;
	Wave currentWave;
	int currentWaveIndex = 0;
	Score* score;
	WaveManager* waveManager = new WaveManager();
public:
	GameplayTanks() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
	int GetTotalEnemies(const Wave& wave); // Calcula el total de enemigos en una oleada
	void SpawnEnemiesFromWave(const Wave& wave); // Genera enemigos basados en la oleada actual
	void SpawnEnemyById(EnemyConfig enemy);
	void AdvanceToNextWave();
	Vector2 GenerateSpawnPosition();
	std::vector<EnemyConfig>GetCurrentWaveEnemies();
};