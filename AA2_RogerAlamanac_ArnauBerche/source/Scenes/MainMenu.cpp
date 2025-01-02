#include "MainMenu.h"
#include "../Spawner/Spawner.h"
#include "../Object/TextObject.h"
#include "../Renderers/RenderManager.h"
#include "SceneManager.h"
#include "../InputManager/InputManager.h"

void MainMenu::OnEnter()
{
    /*title->SetText("MAIN MENU");
    option1->SetText("SPACE INVADERS");
    option2->SetText("TANKS");
    option3->SetText("SPLAT!");*/


    title->GetTransform()->position = Vector2((RM->WINDOW_WIDTH/2),100); // Ajusta la posición según sea necesario
    SPAWN.SpawnObject(title);
    option1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 200 );
    SPAWN.SpawnObject(option1);
    option2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 300);
    SPAWN.SpawnObject(option2);
    option3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 400);
    SPAWN.SpawnObject(option3);

}

void MainMenu::OnExit()
{
    Scene::OnExit();
}

void MainMenu::Update()
{
    // No va;
    Scene::Update();
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
    title->Render();
    option1->Render();
    option2->Render();
    option3->Render();
}
