#include "MainMenu.h"
#include "../Spawner/Spawner.h"
#include "../Object/TextObject.h"
#include "../Renderers/RenderManager.h"
#include "SceneManager.h"
#include "../InputManager/InputManager.h"

void MainMenu::OnEnter()
{

    if (SM.needsDefault)
    {
        SM.ClearITU();
        SM.imagesToUse.resize(3);
        SM.imagesToUse[0].push_back("resources/images/SpaceShip/BG/Space_Draw.png");
        SM.imagesToUse[0].push_back("resources/images/SpaceShip/Enemies/SpaceEnemy_Draw.png");
        SM.imagesToUse[0].push_back("resources/images/SpaceShip/VFX/SpaceShipBullet_Draw.png");

        SM.imagesToUse[1].push_back("resources/images/Swater/BG/Kitchen_Draw.png");
        SM.imagesToUse[1].push_back("resources/images/Swater/Enemies/SwatterEnemy_Draw.png");
        SM.imagesToUse[1].push_back("resources/images/Swater/VFX/ExplosionSpritesheet_Draw.png");

        SM.imagesToUse[2].push_back("resources/images/Tank/BG/Battle_Draw.png");
        SM.imagesToUse[2].push_back("resources/images/Tank/Enemies/TankEnemy_Draw.png");
        SM.imagesToUse[2].push_back("resources/images/Tank/VFX/TankBullet_Draw.png");
        SM.needsDefault = false;
    }

	title = new TextObject("MainMenu");
	option1 = new TextObject("Space Invaders");
	option2 = new TextObject("Tanks");
	option3 = new TextObject("Splat");
	sprites = new TextObject("Sprite Selector");

    int optionWidth = 600; 
    int optionHeight = 75; 

    title->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH/2) - 50,100);
    title->GetTransform()->scale = Vector2(1.5f,1.5f);
    title->SetText("MAIN MENU");
    SPAWN.SpawnObject(title);
    options.push_back(title);

    option1->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 100, 200 );
    option1->GetTransform()->scale = Vector2(1.5f, 1.5f);
    option1->SetText("1. SPACE INVADERS");
    option1->SetRect({static_cast<int>(option1->GetTransform()->position.x - (optionWidth / 2)), 100, optionWidth, optionHeight });
    SPAWN.SpawnObject(option1);
    options.push_back(option1);

    option2->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 100, 300);
    option2->GetTransform()->scale = Vector2(1.5f, 1.5f);
    option2->SetText("2. TANKS");
    option2->SetRect({ static_cast<int>(option2->GetTransform()->position.x - (optionWidth / 2)), 200, optionWidth, optionHeight });
    option2->SetButtonColor(SDL_Color{ 0, 255, 0, 255 });
    SPAWN.SpawnObject(option2);
    options.push_back(option2);

    option3->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 100, 400);
    option3->GetTransform()->scale = Vector2(1.5f, 1.5f);
    option3->SetText("3. SPLAT!");
    option3->SetRect({ static_cast<int>(option3->GetTransform()->position.x - (optionWidth / 2)), 300, optionWidth, optionHeight });
    option3->SetButtonColor(SDL_Color{ 0, 0, 255, 255 });
    SPAWN.SpawnObject(option3);
    options.push_back(option3);

    sprites->GetTransform()->position = Vector2(((float)RM->WINDOW_WIDTH / 2) - 100, 500);
    sprites->GetTransform()->scale = Vector2(1.5f, 1.5f);
    sprites->SetText("SPRITE SELECTOR");
    sprites->SetRect({ static_cast<int>(sprites->GetTransform()->position.x - (optionWidth / 2)), 400, optionWidth, optionHeight });
    sprites->SetButtonColor(SDL_Color{ 0, 0, 255, 255 }); 
    SPAWN.SpawnObject(sprites);
    options.push_back(option3);
}

void MainMenu::OnExit()
{
    Scene::OnExit();
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
        if (IsMouseOverButton(sprites->GetRect(), mouseX, mouseY)) {
            SM.SetNextScene("Sprite Selector");
        }
    }
}

void MainMenu::Render()
{
    Scene::Render();
}
