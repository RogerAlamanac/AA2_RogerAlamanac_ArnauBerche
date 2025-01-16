#include "SpriteSelector.h"
#include "../InputManager/InputManager.h"
#include <iostream>
#include "SceneManager.h"

void SpriteSelector::OnEnter()
{
    title->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2) - 120, 150);
    title->GetTransform()->scale = Vector2(2.f, 2.f);
    title->SetText("SPRITE SELECTOR");

    background1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 200);

    background2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 200);

    background3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 200);

    enemies1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 350);

    enemies2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 350);

    enemies3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 350);

    VFX1->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5), 500);

    VFX2->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 400, 500);

    VFX3->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 5) + 800, 500);

    for (ImageObject* sprite : sprites) {
        if (sprite != nullptr) {
            SPAWN.SpawnObject(sprite);
        }
    }
    int optionWidth = 400;
    int optionHeight = 100;
    back->GetTransform()->position = Vector2((RM->WINDOW_WIDTH / 2) -50, 700);
    back->GetTransform()->scale = Vector2(1.5f, 1.5f);
    back->SetText("MAIN MENU");
    back->SetRect({ static_cast<int>(back->GetTransform()->position.x - (optionWidth / 2)), 600, optionWidth, optionHeight });
    back->SetButtonColor(SDL_Color{ 255, 0, 0, 255 }); // Rojo
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
    // Verificar si el mouse está sobre algún sprite
    for (ImageObject* sprite : sprites) {
        if (IsMouseOverObject(sprite, mouseX, mouseY)) {
            if (sprite == nullptr) continue; // Evita acceder a punteros nulos
            std::cout << "Mouse está sobre el sprite: " << sprite << std::endl;

            // Puedes realizar acciones adicionales, como cambiar el color del sprite,
            // mostrar un tooltip, o registrar un clic si es necesario
            if (IM.GetLeftClick()) {
                std::cout << "¡Sprite clickeado!" << std::endl;
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
