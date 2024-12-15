#include "Gameplay.h"
#include "../Spawner/Spawner.h"
#include "../Audio/AudioManager.h"
#include "../InputManager/InputManager.h"
#include "../InputManager/TimeManager.h"
#include "../Player/Spaceship.h"
#include "../Player/Tank.h"
#include "../Player/Swatter.h"
#include "../InputManager/TimeManager.h"
#include "../Enemies/BasicEnemy.h"


void Gameplay::OnEnter()
{
	switch (game)
	{
	case 0:
		SPAWN.SpawnObject(new Spaceship(Vector2(100, 700)));
		break;
	case 1:
		SPAWN.SpawnObject(new Tank(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), 100));
		break;
	case 2:
		SPAWN.SpawnObject(new Swatter(Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), 3.f));
		break;
	default:
		break;
	}

	//for(int i = 0; i < 50; i++)
	//	SpawnObjectRandomly();
	//SPAWN.SpawnObject(new TestObject(Vector2(100, 100), Vector2(1000, 0)));
	//SPAWN.SpawnObject(new TestObject(Vector2(300, 100), Vector2(-1000, 0)));

	//Object* textObj = new TextObject("HOLA");
	//textObj->GetTransform()->position = Vector2(100, 100);
	//SPAWN.SpawnObject(textObj);

	//AM.LoadSong("illuminati");
	//AM.PlaySong("illuminati");

	//AM.LoadClip("d");
}

void Gameplay::Update()
{
	Scene::Update();
	switch (game)
	{
	case 0:
		if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned)
		{
			SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 100, 10, 1, true));
			enemySpawned = true;
		}
		else if ((int)TIME.GetElapsedTime() % 5 != 0)
		{
			enemySpawned = false;
		}
		break;
	case 1:
		if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned)
		{
			SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 100, 10, 1, true));
			enemySpawned = true;
		}
		else if ((int)TIME.GetElapsedTime() % 5 != 0)
		{
			enemySpawned = false;
		}
		break;
	case 2:
		if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned)
		{
			SPAWN.SpawnObject(new BasicEnemy(Vector2(90, -90), 100, 10, 1, true));
			enemySpawned = true;
		}
		else if ((int)TIME.GetElapsedTime() % 5 != 0)
		{
			enemySpawned = false;
		}
		break;
	default:
		break;
	}
}

void Gameplay::OnExit()
{
	Scene::OnExit();
}

void Gameplay::Render()
{
	Scene::Render();
}

//void Gameplay::SpawnObjectRandomly()
//{
//	SPAWN.SpawnObject(new TestObject());
//}
