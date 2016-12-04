#include "engine.h"

void Engine::CreateGameWindow() {

	window = SDL_CreateWindow(
		game_title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		SDL_Log("An error occured during initialization of the window\n");
		SDL_GetError();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother. 
	SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);
}
