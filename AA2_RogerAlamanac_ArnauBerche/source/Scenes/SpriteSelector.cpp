#include "SpriteSelector.h"
#include "../InputManager/InputManager.h"
#include <iostream>
#include "SceneManager.h"

void SpriteSelector::OnEnter()
{
	spaceInvaders = new ImageObject("resources/images/SpaceShip/BG/Space_Draw.png", Vector2(0.f, 0.f), Vector2(2000.f, 1125.f), 0, "TYPE1");
	hoverSprites.push_back(spaceInvaders);
	tank = new ImageObject("resources/images/SpaceShip/BG/Space_Draw.png", Vector2(0.f, 0.f), Vector2(2000.f, 1125.f), 0, "TYPE2");
	hoverSprites.push_back(tank);
	swater = new ImageObject("resources/images/SpaceShip/BG/Space_Draw.png", Vector2(0.f, 0.f), Vector2(2000.f, 1125.f), 0, "TYPE3");
	hoverSprites.push_back(swater);

	background1 = new ImageObject("resources/images/SpaceShip/BG/Space_Draw.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(background1);
	background2 = new ImageObject("resources/images/SpaceShip/BG/Space_Pixel.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(background2);
	background3 = new ImageObject("resources/images/SpaceShip/BG/Space_Real.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(background3);
	enemies1 = new ImageObject("resources/images/SpaceShip/Enemies/SpaceEnemy_Draw.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(enemies1);
	enemies2 = new ImageObject("resources/images/SpaceShip/Enemies/SpaceEnemy_Pixel.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(enemies2);
	enemies3 = new ImageObject("resources/images/SpaceShip/Enemies/SpaceEnemy_Real.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(enemies3);
	VFX1 = new ImageObject("resources/images/SpaceShip/VFX/SpaceShipBullet_Draw.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(VFX1);
	VFX2 = new ImageObject("resources/images/SpaceShip/VFX/SpaceShipBullet_Pixel.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(VFX2);
	VFX3 = new ImageObject("resources/images/SpaceShip/VFX/SpaceShipBullet_Real.png", Vector2(0.f, 0.f), Vector2(1000.f, 1000.f), 0, "SPRITE");
	sprites.push_back(VFX3);

	back = new TextObject("Main Menu");
	title = new TextObject("Sprite Selector");

    title->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2) - 120, 150);
    title->GetTransform()->scale = Vector2(2.f, 2.f);
    title->SetText("SPRITE SELECTOR");
    SPAWN.SpawnObject(title);

	spaceInvaders->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 100);
	SPAWN.SpawnObject(spaceInvaders);
	tank->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 100);
	SPAWN.SpawnObject(tank);
	swater->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 100);
	SPAWN.SpawnObject(swater);

    background1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 200);
    SPAWN.SpawnObject(background1);
    background2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 200);
    SPAWN.SpawnObject(background2);
    background3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 200);
    SPAWN.SpawnObject(background3);
    enemies1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 350);
    SPAWN.SpawnObject(enemies1);
    enemies2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 350);
    SPAWN.SpawnObject(enemies2);
    enemies3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 350);
    SPAWN.SpawnObject(enemies3);
    VFX1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 500);
    SPAWN.SpawnObject(VFX1);
    VFX2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 500);
    SPAWN.SpawnObject(VFX2);
    VFX3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 500);
    SPAWN.SpawnObject(VFX3);

    int optionWidth = 400;
    int optionHeight = 100;
    back->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2) -50, 700);
    back->GetTransform()->scale = Vector2(1.5f, 1.5f);
    back->SetText("MAIN MENU");
    back->SetRect({ static_cast<int>(back->GetTransform()->position.x - (optionWidth / 2)), 600, optionWidth, optionHeight });
    back->SetButtonColor(SDL_Color{ 255, 0, 0, 255 });
    SPAWN.SpawnObject(back);
}

void SpriteSelector::OnExit()
{
    SPAWN.ClearSpawnedObjects();
    sprites.clear();
	Scene::OnExit();
}

void SpriteSelector::Update()
{
    Scene::Update();

    int mouseX = IM.GetMouseX();
    int mouseY = IM.GetMouseY();
    std::cout << "Mouse: (" << mouseX << ", " << mouseY << ")" << std::endl;

    for (ImageObject* sprite : hoverSprites) 
    {
		if (IsMouseOverObject(sprite, mouseX, mouseY)) {
			if (sprite == nullptr) continue; 
			std::cout << "Mouse está sobre el sprite: " << sprite->tag << std::endl;
			if (IM.GetLeftClick()) {
				std::cout << "¡Sprite clickeado!" << std::endl;
                if (sprite->tag == "TYPE1") 
                {
					SM.ClearITU();
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/BG/Space_Draw.png");
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/Enemies/SpaceEnemy_Draw.png");
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/VFX/SpaceShipBullet_Draw.png");

					SM.imagesToUse[1].push_back("resources/images/Swater/BG/Kitchen_Draw.png");
					SM.imagesToUse[1].push_back("resources/images/Swater/Enemies/SwatterEnemy_Draw.png");
					SM.imagesToUse[1].push_back("resources/images/Swater/VFX/ExplosionSpritesheet_Draw.png");

					SM.imagesToUse[2].push_back("resources/images/Tank/BG/Battle_Draw.png");
					SM.imagesToUse[2].push_back("resources/images/Tank/Enemies/TankEnemy_Draw.png");
					SM.imagesToUse[2].push_back("resources/images/Tank/VFX/TankBullet_Draw.png");

                }
                else if (sprite->tag == "TYPE2")
                {
					SM.ClearITU();
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/BG/Space_Pixel.png");
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/Enemies/SpaceEnemy_Pixel.png");
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/VFX/SpaceShipBullet_Pixel.png");

					SM.imagesToUse[1].push_back("resources/images/Swater/BG/Kitchen_Pixel.png");
					SM.imagesToUse[1].push_back("resources/images/Swater/Enemies/SwatterEnemy_Pixel.png");
					SM.imagesToUse[1].push_back("resources/images/Swater/VFX/ExplosionSpritesheet_Pixel.png");

					SM.imagesToUse[2].push_back("resources/images/Tank/BG/Battle_Pixel.png");
					SM.imagesToUse[2].push_back("resources/images/Tank/Enemies/TankEnemy_Pixel.png");
					SM.imagesToUse[2].push_back("resources/images/Tank/VFX/TankBullet_Pixel.png");
                }
                else if (sprite->tag == "TYPE3")
                {
					SM.ClearITU();
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/BG/Space_Real.png");
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/Enemies/SpaceEnemy_Real.png");
					SM.imagesToUse[0].push_back("resources/images/SpaceShip/VFX/SpaceShipBullet_Real.png");

					SM.imagesToUse[1].push_back("resources/images/Swater/BG/Kitchen_Real.png");
					SM.imagesToUse[1].push_back("resources/images/Swater/Enemies/SwatterEnemy_Real.png");
					SM.imagesToUse[1].push_back("resources/images/Swater/VFX/ExplosionSpritesheet_Real.png");

					SM.imagesToUse[2].push_back("resources/images/Tank/BG/Battle_Real.png");
					SM.imagesToUse[2].push_back("resources/images/Tank/Enemies/TankEnemy_Real.png");
					SM.imagesToUse[2].push_back("resources/images/Tank/VFX/TankBullet_Real.png");
                }
				SM.needsDefault = false;
			}
		}
    }

    if (IM.GetLeftClick()) {
        if (IsMouseOverButton(back->GetRect(), mouseX, mouseY)) {
            SM.SetNextScene("Main Menu");
        }
    }
}

void SpriteSelector::Render()
{
	Scene::Render();
}
