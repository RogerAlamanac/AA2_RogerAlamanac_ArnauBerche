#include "GameplaySpaceInvaders.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/BasicEnemy.h"
#include "../Player/Spaceship.h"
#include "../Object/TextObject.h"
#include "../Elements/Background.h"

void GameplaySpaceInvaders::OnEnter()
{
	//SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
	player = new Spaceship(Vector2(100, 700), MAX_LIFES);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
	score = new Score(Vector2(10, 10), 0);
	SPAWN.SpawnObject(score);
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
		SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 50, 10, 1, true));
		enemySpawned = true;
		amountEnemies--;
	}
	else if ((int)TIME.GetElapsedTime() % 5 != 0)
	{
		enemySpawned = false;
	}
	//if (/*enemyDead*/) {
	//	
	//}
	/*score->GetCurrentScore() += 1;
	score1->SetText("Score: " + std::to_string(currentScore));*/
}

void GameplaySpaceInvaders::Render()
{
	Scene::Render();
}
