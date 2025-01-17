#include "Game.h"
#include "../Renderers/RenderManager.h"
#include "../Scenes/SceneManager.h"
#include "../Scenes/GameplaySpaceInvaders.h"
#include "../Scenes/GameplaySplat.h"
#include "../Scenes/GameplayTanks.h"
#include "../Scenes/MainMenu.h"
#include "../Scenes/SpriteSelector.h"
#include "../InputManager/InputManager.h"
void Game::Init()
{
	RM->Init();

	//SpaceShip
			//BG
		RM->LoadTexture("resources/images/SpaceShip/BG/Space_Draw.png");
		RM->LoadTexture("resources/images/SpaceShip/BG/Space_Pixel.png");
		RM->LoadTexture("resources/images/SpaceShip/BG/Space_Real.png");

			//Enemies
		RM->LoadTexture("resources/images/SpaceShip/Enemies/SpaceEnemy_Draw.png");
		RM->LoadTexture("resources/images/SpaceShip/Enemies/SpaceEnemy_Pixel.png");
		RM->LoadTexture("resources/images/SpaceShip/Enemies/SpaceEnemy_Real.png");

			//Player
		RM->LoadTexture("resources/images/SpaceShip/Player/Spaceship.png");

			//VFX
		RM->LoadTexture("resources/images/SpaceShip/VFX/SpaceShipBullet_Draw.png");
		RM->LoadTexture("resources/images/SpaceShip/VFX/SpaceShipBullet_Pixel.png");
		RM->LoadTexture("resources/images/SpaceShip/VFX/SpaceShipBullet_Real.png");


	//Swatter
			//BG
		RM->LoadTexture("resources/images/Swater/BG/Kitchen_Draw.png");
		RM->LoadTexture("resources/images/Swater/BG/Kitchen_Pixel.png");
		RM->LoadTexture("resources/images/Swater/BG/Kitchen_Real.png");

			//Enemies
		RM->LoadTexture("resources/images/Swater/Enemies/SwatterEnemy_Draw.png");
		RM->LoadTexture("resources/images/Swater/Enemies/SwatterEnemy_Pixel.png");
		RM->LoadTexture("resources/images/Swater/Enemies/SwatterEnemy_Real.png");

			//Player
		RM->LoadTexture("resources/images/Swater/Player/Swatter.png");

			//VFX
		RM->LoadTexture("resources/images/Swater/VFX/ExplosionSpritsheet_Draw.png");
		RM->LoadTexture("resources/images/Swater/VFX/ExplosionSpritsheet_Pixel.png");
		RM->LoadTexture("resources/images/Swater/VFX/ExplosionSpritsheet_Real.png");


	//Tank
			//BG
		RM->LoadTexture("resources/images/Tank/BG/Battle_Draw.png");
		RM->LoadTexture("resources/images/Tank/BG/Battle_Pixel.png");
		RM->LoadTexture("resources/images/Tank/BG/Battle_Real.png");

			//Enemies
		RM->LoadTexture("resources/images/Tank/Enemies/TankEnemy_Draw.png");
		RM->LoadTexture("resources/images/Tank/Enemies/TankEnemy_Pixel.png");
		RM->LoadTexture("resources/images/Tank/Enemies/TankEnemy_Real.png");

			//Player
		RM->LoadTexture("resources/images/Tank/Player/none.png");
		RM->LoadTexture("resources/images/Tank/Player/tank body.png");
		RM->LoadTexture("resources/images/Tank/Player/tank turret.png");

			//VFX
		RM->LoadTexture("resources/images/Tank/VFX/TankBullet_Draw.png");
		RM->LoadTexture("resources/images/Tank/VFX/TankBullet_Pixel.png");
		RM->LoadTexture("resources/images/Tank/VFX/TankBullet_Real.png");



	assert(SM.AddScene("Main Menu", new MainMenu()));
	assert(SM.AddScene("SpaceInvaders", new GameplaySpaceInvaders()));
	assert(SM.AddScene("Tanks", new GameplayTanks()));
	assert(SM.AddScene("Splat", new GameplaySplat()));
	assert(SM.AddScene("Sprite Selector", new SpriteSelector()));
	assert(SM.InitFirstScene("Main Menu"));

}


void Game::Update()
{
	SM.UpdateCurrentScene();
}

void Game::Render()
{
	RM->ClearScreen();
	SM.GetCurrentScene()->Render();
	RM->RenderScreen();
}

void Game::Release()
{
	SM.GetCurrentScene()->OnExit();
	RM->Release();
}


