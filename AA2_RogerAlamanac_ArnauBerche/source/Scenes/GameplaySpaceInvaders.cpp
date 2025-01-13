#include "GameplaySpaceInvaders.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/BasicEnemy.h"
#include "../Player/Spaceship.h"
#include "../Object/TextObject.h"
#include "../Elements/Background.h"
#include "../Elements/Bullet.h"
#include <iostream>
#include "SceneManager.h"

void GameplaySpaceInvaders::OnEnter()
{
	SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
	player = new Spaceship(Vector2(100, 700), MAX_LIFES);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
	score = new Score(Vector2(100, 100), 0);
	score->SetText("Score: " + std::to_string(currentScore));
	SPAWN.SpawnObject(score);

	end = new TextObject("End");
	end->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2 - 50, RM->WINDOW_HEIGHT / 2 + 50);
	end->SetText(" ");
	end->GetTransform()->scale = Vector2(5, 5);
	SPAWN.SpawnObject(end);
}

void GameplaySpaceInvaders::OnExit()
{
	Scene::OnExit();
}

void GameplaySpaceInvaders::Update()
{
		for (int i = _objects.size() - 1; i >= 0; i--) {
		if (_objects[i]->IsPendingDestroy()) {
			if (_objects[i]->tag == "ENEMY") {
				currentScore += 100;
			}
		}
	}
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

