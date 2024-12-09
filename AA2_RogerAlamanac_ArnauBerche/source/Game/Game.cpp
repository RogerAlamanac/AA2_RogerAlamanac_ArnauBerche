#include "Game.h"
#include "../Renderers/RenderManager.h"
#include "../Scenes/SceneManager.h"
#include "../Scenes/Gameplay.h"
#include "../Scenes/MainMenu.h"
#include "../InputManager/InputManager.h"
void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/Spaceship.png");

	assert(SM.AddScene("Main Menu", new MainMenu()));
	assert(SM.AddScene("Gameplay", new Gameplay()));
	assert(SM.InitFirstScene("Gameplay"));

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


