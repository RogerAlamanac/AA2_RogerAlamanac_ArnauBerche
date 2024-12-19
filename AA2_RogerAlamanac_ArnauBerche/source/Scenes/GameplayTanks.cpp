#include "GameplayTanks.h"
#include "../Elements/Background.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/ShootingEnemy.h"
#include "../Enemies/AimingEnemy.h"
#include "../Player/Tank.h"
#include "SceneManager.h"

void GameplayTanks::OnEnter()
{
	SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
	player = new Tank(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), 100);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
}

void GameplayTanks::OnExit()
{
	Scene::OnExit();
}

void GameplayTanks::Update() 
{
	Scene::Update();

	int spawnPosX;
	int spawnPosY;
	int randomEnemy;
	if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned && amountEnemies > 0)
	{
		spawnPosX = rand() % RM->WINDOW_WIDTH + 1;
		spawnPosY = rand() % RM->WINDOW_HEIGHT + 1;
		randomEnemy = (rand() % 2 + 1);
		switch (randomEnemy)
		{
		case 1:
			SPAWN.SpawnObject(new ShootingEnemy(Vector2(90, -90), 100, 10, 1, true));
			break;
		case 2:
			SPAWN.SpawnObject(new AimingEnemy(Vector2(spawnPosX, spawnPosY), 100, 10, 10, true, player));
			break;
		default:
			break;
		}
		enemySpawned = true;
		amountEnemies--;
	}
	else if ((int)TIME.GetElapsedTime() % 5 != 0)
	{
		enemySpawned = false;
	}
}

void GameplayTanks::Render()
{
	Scene::Render();
}