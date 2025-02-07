#pragma once
#include "Scene.h"
#include "../WaveManager.h"
#include "../UI/Score.h"

class GameplaySplat : public Scene {
private:
	bool enemySpawned = false;
	bool randomSpawned = false;
	int amountEnemies = 10;
	int currentScore = 0;
	Wave currentWave;
	Score* score;
	WaveManager* waveManager = new WaveManager();
public:
	GameplaySplat() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
	int GetTotalEnemies(const Wave& wave); 
	void SpawnEnemiesFromWave(const Wave& wave); 
	void SpawnEnemyById(EnemyConfig enemy);
	void AdvanceToNextWave();
	Vector2 GenerateSpawnPosition();
	std::vector<EnemyConfig>GetCurrentWaveEnemies();
};