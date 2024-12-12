#include "Gameplay.h"
#include "../Object/TestObject.h"
#include "../Object/TextObject.h"
#include "../Audio/AudioManager.h"
#include "../InputManager/InputManager.h"

void Gameplay::OnEnter()
{
	//for(int i = 0; i < 50; i++)
	//	SpawnObjectRandomly();
	//SPAWN.SpawnObject(new TestObject(Vector2(100, 100), Vector2(1000, 0)));
	//SPAWN.SpawnObject(new TestObject(Vector2(300, 100), Vector2(-1000, 0)));

	//Object* textObj = new TextObject("HOLA");
	//textObj->GetTransform()->position = Vector2(100, 100);
	//SPAWN.SpawnObject(textObj);

	SPAWN.SpawnObject(new TestObject(Vector2(100, 400)));

	AM.LoadSong("illuminati");
	AM.PlaySong("illuminati");

	AM.LoadClip("d");
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

//void Gameplay::SpawnObjectRandomly()
//{
//	SPAWN.SpawnObject(new TestObject());
//}
