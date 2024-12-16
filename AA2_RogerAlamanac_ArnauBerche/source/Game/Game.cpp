#include "Game.h"
#include "../Renderers/RenderManager.h"
#include "../Scenes/SceneManager.h"
#include "../Scenes/GameplaySpaceInvaders.h"
#include "../Scenes/GameplaySplat.h"
#include "../Scenes/GameplayTanks.h"
#include "../Scenes/MainMenu.h"
#include "../InputManager/InputManager.h"
void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/background_space.jpg");
	RM->LoadTexture("resources/Spaceship.png");
	RM->LoadTexture("resources/circle.png");
	RM->LoadTexture("resources/basicenemy.png");
	RM->LoadTexture("resources/guitar.jpg");
	RM->LoadTexture("resources/tank turret.png");
	RM->LoadTexture("resources/tank body.png");
	RM->LoadTexture("resources/Swatter.png");
	RM->LoadTexture("resources/none.png");

	assert(SM.AddScene("Main Menu", new MainMenu()));
	assert(SM.AddScene("SpaceInvaders", new GameplaySpaceInvaders()));
	assert(SM.AddScene("Tanks", new GameplayTanks()));
	assert(SM.AddScene("Splat", new GameplaySplat()));
	assert(SM.InitFirstScene("SpaceInvaders"));

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


