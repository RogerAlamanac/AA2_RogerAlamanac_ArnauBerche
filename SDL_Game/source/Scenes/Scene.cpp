#include "Scene.h"
#include "../Spawner/Spawner.h"

void Scene::OnExit()
{
	//Clear the spawner
	SPAWN.ClearSpawnedObjects();
	//Destroy ALL objects
	for (Object* o : _objects) {
		delete o;
	}
	_objects.clear();
}

void Scene::Update()
{
	//DESTRUCTION
	for (int i = _objects.size() - 1; i >= 0; i--) {
		if (_objects[i]->IsPendingDestroy()) {
			delete _objects[i];
			_objects.erase(_objects.begin() + i);
		}
	}
	//SPAWNING
	while (SPAWN.GetSpawnedObjectsCount() > 0) {
		_objects.push_back(SPAWN.GetSpawnedObject());
	}
	//UPDATING
	for (Object* o : _objects) {
		o->Update();
	}
}

void Scene::Render()
{
	RM->ClearScreen();
	for (Object* go : _objects) go->Render();
	RM->RenderScreen();
}
