#include "SplashScreen.h"
#include "../Spawner/Spawner.h"
#include "SceneManager.h"

void SplashScreen::OnEnter()
{
	companyLogo = new ImageObject("resources/images/SplashScreen.png", Vector2(0.f, 0.f), Vector2(960.f, 720.f), 0, "BG");
	companyLogo->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT/10);
	companyLogo->GetTransform()->scale = Vector2(10.f, 10.f);
	SPAWN.SpawnObject(companyLogo);

	presentTitle = new TextObject(" ");
	presentTitle->SetText("PRESENTED BY");
	presentTitle->GetTransform()->position = Vector2(RM->WINDOW_WIDTH / 2.15f, RM->WINDOW_HEIGHT / 6);
	SPAWN.SpawnObject(presentTitle);
}

void SplashScreen::OnExit()
{
	Scene::OnExit();

}

void SplashScreen::Update()
{
	Scene::Update();
	if (timeSinceStarted >= timeToGoToMainMenu) {
		SM.SetNextScene("Main Menu");
	}
	if (companyLogo->GetTransform()->position.y < RM->WINDOW_HEIGHT / 2) {
		companyLogo->GetTransform()->position.y += 2.5;
	}
	if (presentTitle->GetTransform()->position.y < RM->WINDOW_HEIGHT / 2) {
		presentTitle->GetTransform()->position.y += 2.5;
	}

	timeSinceStarted += TIME.GetDeltaTime();
}

void SplashScreen::Render()
{
	Scene::Render();
}
