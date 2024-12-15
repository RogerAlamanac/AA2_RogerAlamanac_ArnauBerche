#include "SpaceInvaders.h"
#include "../Audio/AudioManager.h"
#include "../InputManager/InputManager.h"
#include "../InputManager/TimeManager.h"
#include "../Player/Spaceship.h"
#include "../Enemies/BasicEnemy.h"
#include "../InputManager/TimeManager.h"
#include "../Spawner/Spawner.h"

void SpaceInvaders::OnEnter()
{
	SPAWN.SpawnObject(new Spaceship(Vector2(100, 700)));
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

void SpaceInvaders::Update()
{
	Scene::Update();
	if ((int)TIME.GetElapsedTime() % 5 == 0 && !enemySpawned)
	{
		SPAWN.SpawnObject(new BasicEnemy(Vector2(700, 700), 10, 1, true));
		enemySpawned = true;
	}
	else if ((int)TIME.GetElapsedTime() % 5 != 0)
	{
		enemySpawned = false;
	}

}

void SpaceInvaders::OnExit()
{
	Scene::OnExit();
}

void SpaceInvaders::Render()
{
	Scene::Render();
}