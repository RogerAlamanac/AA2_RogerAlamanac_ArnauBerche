#pragma once
#include "Player.h"
#include "../Object/ImageObject.h"
#include "../Spawner/Spawner.h"

class Canon : public ImageObject
{
public:
	Vector2 relativeOffset;
	
	Canon(Vector2 pos) : ImageObject("resources/tank turret.png", Vector2(0.f, 0.f), Vector2(193.f, 193.f), 0, "PLAYER") {
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
	}
	~Canon();

	void SetRotation(float rotation)
	{
		ImageObject::transform->rotation = rotation;
	};
	void SetPosition(Vector2 position)
	{
		ImageObject::transform->position = position;
	};
};

class Body : public ImageObject
{
public:

	PlayerDirections currentDirection;

	float fireCooldown = 1.f;
	float timeSinceLastFire = 0.f;

	Body(Vector2 pos, float velocity) : ImageObject("resources/tank body.png", Vector2(0.f, 0.f), Vector2(142.f, 195.f), 0, "PLAYER") {
		currentDirection = PlayerDirections::NONE;
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
	}

	void SetRotation(float rotation)
	{
		ImageObject::transform->rotation = rotation;
	};
	void SetPosition(Vector2 position)
	{
		ImageObject::transform->position = position;
	};
};

class Tank : public ImageObject, public Player
{
private:
	Canon* canon;
	Body* body;
	float movementSpeed;

public:
	Tank(Vector2 pos, float velocity) : ImageObject("resources/none.png", Vector2(0.f, 0.f), Vector2(1.f, 1.f), 0, "PLAYER"), Player() {
		movementSpeed = velocity;
		ImageObject::transform->position = pos;
		ImageObject::transform->scale = Vector2(1.f, 1.f);
		canon = new Canon(pos);
		body = new Body(pos, velocity);
		SPAWN.SpawnObject(body);
		SPAWN.SpawnObject(canon);
		canon->relativeOffset = Vector2(0, -ImageObject::transform->size.y / 2);
	}
	~Tank();
	void Movement() override;
	Vector2 CalculateOfset();
	Vector2 DirectionToAim(Vector2 relativeOffset);
	void Attack() override;
	void ReceiveDamage() override;
	void Update() override;
};

