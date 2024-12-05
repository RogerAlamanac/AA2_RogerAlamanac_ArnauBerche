#include "Gameplay.h"
#include "../Object/TestObject.h"

void Gameplay::OnEnter()
{
	for(int i = 0; i < 50; i++)
	SpawnObjectRandomly();
}

void Gameplay::Update()
{
	Scene::Update();
}

void Gameplay::OnExit()
{
	Scene::OnExit();
}

void Gameplay::Render()
{
	Scene::Render();
}

void Gameplay::SpawnObjectRandomly()
{

	SPAWN.SpawnObject(new TestObject());
}
