#pragma once
#include "Scene.h"
#include "../UI/Score.h"
#include "../WaveManager.h" 

class GameplaySpaceInvaders : public Scene {
private:
	bool enemySpawned = false;
	bool randomSpawned = false;
	int amountEnemies = 10;
	int currentScore = 0;
	Wave currentWave;
	Score* score;
	TextObject* end;
	WaveManager* waveManager = new WaveManager();

public:
	GameplaySpaceInvaders() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
	int GetTotalEnemies(const Wave& wave); 
	void SpawnEnemiesFromWave(const Wave& wave); 
	void SpawnEnemyById(EnemyConfig enemy);
	void AdvanceToNextWave();
	void SaveScoreToRanking(const std::string& playerName)
	Vector2 GenerateSpawnPosition();
	std::vector<EnemyConfig>GetCurrentWaveEnemies();
};