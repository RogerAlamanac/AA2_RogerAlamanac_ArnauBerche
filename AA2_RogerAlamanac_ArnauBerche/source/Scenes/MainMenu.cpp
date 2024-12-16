#include "MainMenu.h"
#include "../Spawner/Spawner.h"
#include "../Object/TextObject.h"
#include "../Renderers/RenderManager.h"
#include "SceneManager.h"
#include "../InputManager/InputManager.h"

void MainMenu::OnEnter()
{

}

void MainMenu::OnExit()
{
    Scene::OnExit();
}

void MainMenu::Update()
{
    // No va;
     InputManager& input = IM;
     if(input.GetEvent(SDLK_1, DOWN)){
        SM.SetNextScene("SpaceInvaders");
     }
     if(input.GetEvent(SDLK_2, DOWN)){
        SM.SetNextScene("Tanks");
     }
     if(input.GetEvent(SDLK_3, DOWN)){
        SM.SetNextScene("Splat");
     }
     
}

void MainMenu::Render()
{
    Scene::Render();
}
