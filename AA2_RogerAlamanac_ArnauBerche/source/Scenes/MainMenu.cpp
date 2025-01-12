#include "MainMenu.h"
#include "../Spawner/Spawner.h"
#include "../Object/TextObject.h"
#include "../Renderers/RenderManager.h"
#include "SceneManager.h"
#include "../InputManager/InputManager.h"

void MainMenu::OnEnter()
{
    int optionWidth = 400; 
    int optionHeight = 50; 

    title->GetTransform()->position = Vector2((RM->WINDOW_WIDTH/2),100);
    title->SetText("MAIN MENU");
    SPAWN.SpawnObject(title);

    option1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 200 );
    option1->SetText("1. SPACE INVADERS");
    option1->SetRect({static_cast<int>(option1->GetTransform()->position.x - (optionWidth / 2)), 150, optionWidth, optionHeight });
    option1->SetButtonColor(SDL_Color{ 255, 0, 0, 255 }); // Rojo
    SPAWN.SpawnObject(option1);

    option2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 300);
    option2->SetText("2. TANKS");
    option2->SetRect({ static_cast<int>(option2->GetTransform()->position.x - (optionWidth / 2)), 250, optionWidth, optionHeight });
    option2->SetButtonColor(SDL_Color{ 0, 255, 0, 255 }); // Verde
    SPAWN.SpawnObject(option2);

    option3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 400);
    option3->SetText("3. SPLAT!");
    option3->SetRect({ static_cast<int>(option3->GetTransform()->position.x - (optionWidth / 2)), 350, optionWidth, optionHeight });
    option3->SetButtonColor(SDL_Color{ 0, 0, 255, 255 }); // Azul
    SPAWN.SpawnObject(option3);

    //sprites->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2), 500);
    //sprites->SetText("SPRITE SELECTOR");
    //sprites->SetRect({ static_cast<int>(sprites->GetTransform()->position.x - (optionWidth / 2)), 450, optionWidth, optionHeight });
    //sprites->SetButtonColor(SDL_Color{ 0, 0, 255, 255 }); // Azul
    //SPAWN.SpawnObject(sprites);
}

void MainMenu::OnExit()
{
    Scene::OnExit();
    SPAWN.ClearSpawnedObjects();
}

void MainMenu::Update()
{
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
       /* if (IsMouseOverButton(sprites->GetRect(), mouseX, mouseY)) {
            SM.SetNextScene("Sprite Selector");
        }*/
    }
}

void MainMenu::Render()
{
    Scene::Render();
}
