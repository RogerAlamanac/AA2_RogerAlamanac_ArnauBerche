#include "GameplaySplat.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/SeekerEnemy.h"
#include "../Player/Swatter.h"

void GameplaySplat::OnEnter()
{
	player = new Swatter(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2));
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
}

void GameplaySplat::OnExit()
{
	Scene::OnExit();
}

void GameplaySplat::Update() 
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
			SPAWN.SpawnObject(new SeekerEnemy(Vector2(spawnPosX, spawnPosY), 100, 10, 10, 1000, true, player));
			break;
		case 2:
			SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 100, 10, 1, true));
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

void GameplaySplat::Render()
{
	Scene::Render();
}