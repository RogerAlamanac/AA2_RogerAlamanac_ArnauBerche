#include "Scene.h"
#include "../Spawner/Spawner.h"

void Scene::OnExit()
{

	SPAWN.ClearSpawnedObjects();

	for (Object* o : _objects) {
		delete o;
	}
	_objects.clear();
}

void Scene::Update()
{

	for (int i = _objects.size() - 1; i >= 0; i--) {
		if (_objects[i]->IsPendingDestroy()) {
			delete _objects[i];
			_objects.erase(_objects.begin() + i);
		}
	}

	while (SPAWN.GetSpawnedObjectsCount() > 0) {
		_objects.push_back(SPAWN.GetSpawnedObject());
	}

	for (Object* o : _objects) {
		o->Update();
	}

	for (int i = 0; i < _objects.size(); i++)
	{
		for (int j = i + 1; j < _objects.size(); j++) 
		{
			if (_objects[i]->GetRigidBody()->CheckCollision(_objects[j]->GetRigidBody())) 
			{
				_objects[i]->OnCollisionEnter(_objects[j]);
				_objects[j]->OnCollisionEnter(_objects[i]);
			}
		}
	}
}

void Scene::Render()
{
	RM->ClearScreen();
	for (Object* go : _objects) go->Render();
	RM->RenderScreen();
}