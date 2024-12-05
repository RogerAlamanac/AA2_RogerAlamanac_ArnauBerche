#include "Gameplay.h"
#include "../Object/TestObject.h"

void Gameplay::OnEnter()
{
	//for(int i = 0; i < 50; i++)
	//	SpawnObjectRandomly();

	_objects.push_back(new TestObject(Vector2(100, 100), Vector2(1000, 0)));
	_objects.push_back(new TestObject(Vector2(900, 100), Vector2(-1000, 0)));
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
