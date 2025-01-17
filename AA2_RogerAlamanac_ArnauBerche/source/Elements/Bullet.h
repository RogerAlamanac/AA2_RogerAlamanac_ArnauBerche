#pragma once
#include "../Object/ImageObject.h"
#include "../Player/Player.h"
#include <iostream>
#include "../Spawner/Spawner.h"
#include "../Scenes/GameplaySpaceInvaders.h"
#include "../Scenes/SceneManager.h"
#include "../Enemies/BasicEnemy.h"
class Bullet : public ImageObject
{
private:
	bool friendly;

public:
	Bullet(Vector2 initialPos, float velocity, Vector2 finalPos, bool _friendly) : ImageObject("resources/images/SpaceShip/Player/SpaceShipBullet_Pixel", Vector2(0.f, 0.f), Vector2(512.f, 512.f), 0, "BULLET") {
		friendly = _friendly;
		ImageObject::transform->position = initialPos;
		ImageObject::transform->scale = Vector2(0.2f,0.2f);
		physics->SetVelocity(finalPos * velocity);
		physics->AddCollider(new AABB(Vector2(0.f, 0.f), Vector2(512.f, 512.f)));
	}
	~Bullet();
	void Update() override;

	void OnCollisionEnter(Object* other) override {
		if (other->tag == "BG") { return; }

		if (friendly) 
		{
			if (other->tag == "PLAYER" ||
				other->tag == "BULLET")
			{
				return;
			}
			if (other->tag == "ENEMY") {
				other->Destroy();
			}

		}
		else
		{
			if (other->tag == "ENEMY" ||
				other->tag == "BULLET")
			{
				return;
			}
			if (other->tag == "PLAYER")
			{
				Player* player = dynamic_cast<Player*>(other);
				if (player != nullptr) {
					player->ReceiveDamage(); 
				}
			}
		}
		Destroy();
	}
};

