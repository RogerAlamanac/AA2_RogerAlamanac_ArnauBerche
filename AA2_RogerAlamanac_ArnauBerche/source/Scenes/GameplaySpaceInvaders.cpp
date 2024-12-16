#include "GameplaySpaceInvaders.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/BasicEnemy.h"
#include "../Player/Spaceship.h"
#include "../Object/TextObject.h"

void GameplaySpaceInvaders::OnEnter()
{
	player = new Spaceship(Vector2(100, 700));
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
}

void GameplaySpaceInvaders::OnExit()
{
	Scene::OnExit();
}

void GameplaySpaceInvaders::Update()
{
	Scene::Update();

	int spawnPosX;
	int spawnPosY;
	if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned && amountEnemies > 0)
	{
		spawnPosX = rand() % RM->WINDOW_WIDTH + 1;
		spawnPosY = rand() % RM->WINDOW_HEIGHT + 1;
		SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 100, 10, 1, true));
		enemySpawned = true;
		amountEnemies--;
	}
	else if ((int)TIME.GetElapsedTime() % 5 != 0)
	{
		enemySpawned = false;
	}
}

void GameplaySpaceInvaders::Render()
{
	Scene::Render();
}
