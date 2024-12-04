//#include <SDL.h>
//#include <random>
//#include <SDL_image.h>
#include "Game.h"
#include <iostream>
#include <exception>
#include "InputManager.h"
#include "AABB.h"
#include "TimeManager.h"
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
			std::cout << TIME.GetDeltaTime() << std::endl;
			playing = !IM.Listen();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
		}

		//if (IM.GetEvent(SDLK_SPACE, DOWN)) {
		//	std::cout << "Pressed Space" << std::endl;
		//}
	}

	game.Release();
	return 0;
}