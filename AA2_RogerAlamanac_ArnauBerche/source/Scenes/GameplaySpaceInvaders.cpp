#include "GameplaySpaceInvaders.h"
#include "../Spawner/Spawner.h"
#include "../Enemies/BasicEnemy.h"
#include "../Player/Spaceship.h"
#include "../Object/TextObject.h"
#include "../Elements/Background.h"
#include <iostream>

void GameplaySpaceInvaders::OnEnter()
{
	//SPAWN.SpawnObject(new Background(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2)));
	player = new Spaceship(Vector2(100, 700), MAX_LIFES);
	SPAWN.SpawnObject(dynamic_cast<Object*>(player));
	score = new Score(Vector2(10, 10), 0);
	SPAWN.SpawnObject(score);

	scoreText = new TextObject("Score: 0"); // Inicializa el texto con puntuación 0
	scoreText->GetTransform()->position = Vector2(10, 10);
	SPAWN.SpawnObject(scoreText);
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
	/*score->GetCurrentScore() += 1;
	score1->SetText("Score: " + std::to_string(currentScore));*/
	IncreaseScore(1);
	score->Update();
}

void GameplaySpaceInvaders::Render()
{
	Scene::Render();
	scoreText->SetText("Score: " + std::to_string(currentScore)); // Actualiza el puntaje en la pantalla
	score->Render();
}
void GameplaySpaceInvaders::IncreaseScore(int points)
{
	currentScore += points;
	std::cout << "Score: " << currentScore << std::endl;
}
void GameplaySpaceInvaders::EnemyDestroyed()
{
	currentScore += 10;  // Incrementamos el puntaje por cada enemigo destruido
	std::cout << "Score: " << currentScore << std::endl;
}
