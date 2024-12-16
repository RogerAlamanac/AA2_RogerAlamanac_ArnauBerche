//#include <SDL.h>
//#include <SDL_image.h>
#include "Game/Game.h"
#include <iostream>
#include <exception>
#include "InputManager/InputManager.h"
#include "Object/AABB.h"
#include "InputManager/TimeManager.h"
int main(int argc, char* args[]) {
	srand(time(NULL));
	Game game;

	try
	{
		game.Init();
	}
	catch (std::exception& exception) {
		std::cout << "Error: " << exception.what();
		game.Release();
		return -1;
	}
	bool playing = true;
	while (playing) {
		TIME.Update();
		if (TIME.ShouldUpdateGame()) {
			playing = !IM.Listen();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
		}
	}

	game.Release();
	return 0;
}