#include "MainMenu.h"
#include "../Spawner/Spawner.h"
#include "../Object/TextObject.h"
#include "../Renderers/RenderManager.h"
#include "SceneManager.h"
#include "../InputManager/InputManager.h"

void MainMenu::OnEnter()
{
    //title->SetText("MAIN MENU");
    //option1->SetText("SPACE INVADERS");
    //option2->SetText("TANKS");
    //option3->SetText("SPLAT!");


    int optionWidth = 400; // Ajusta el ancho del botón según sea necesario
    int optionHeight = 50; // Ajusta la altura del botón según sea necesario

    title->GetTransform()->position = Vector2((RM->WINDOW_WIDTH/2),100); // Ajusta la posición según sea necesario

    SPAWN.SpawnObject(title);
    option1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 200 );
    option1->SetRect({static_cast<int>(option1->GetTransform()->position.x - (optionWidth / 2)), 150, optionWidth, optionHeight });
    option1->SetButtonColor(SDL_Color{ 255, 0, 0, 255 }); // Rojo
    SPAWN.SpawnObject(option1);
    option2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 300);
    option2->SetRect({ static_cast<int>(option2->GetTransform()->position.x - (optionWidth / 2)), 250, optionWidth, optionHeight });
    option2->SetButtonColor(SDL_Color{ 0, 255, 0, 255 }); // Verde
    SPAWN.SpawnObject(option2);
    option3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 400);
    option3->SetRect({ static_cast<int>(option3->GetTransform()->position.x - (optionWidth / 2)), 350, optionWidth, optionHeight });
    option3->SetButtonColor(SDL_Color{ 0, 0, 255, 255 }); // Azul
    SPAWN.SpawnObject(option3);

}

void MainMenu::OnExit()
{
    Scene::OnExit();
}

void MainMenu::Update()
{
    /*// No va;
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
     }*/
    Scene::Update();
    InputManager& input = IM;
    int mouseX = input.GetMouseX();
    int mouseY = input.GetMouseY();

    if (input.GetLeftClick()) {
        if (IsMouseOverButton(option1->GetRect(), mouseX, mouseY)) {
            SM.SetNextScene("SpaceInvaders");
        }
        if (IsMouseOverButton(option2->GetRect(), mouseX, mouseY)) {
            SM.SetNextScene("Tanks");
        }
        if (IsMouseOverButton(option3->GetRect(), mouseX, mouseY)) {
            SM.SetNextScene("Splat");
        }
    }
}

void MainMenu::Render()
{
    Scene::Render();
}
