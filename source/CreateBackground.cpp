#include "engine.h"

void Engine::CreateBackground() {

	// Create a bitmap surface for the background
	SDL_Surface* BMP_Surface = nullptr;;
	BMP_Surface = IMG_Load("images/wallpaper.jpg");
	if (BMP_Surface == NULL) {
		SDL_Log("An error occured during initialization of the bitmap surface\n");
		SDL_Log("\n%s", SDL_GetError());
		BMP_Surface = IMG_Load( "images/wallpaper_backup.png" );
	}

	// Convert the bitmap surface to texture 
	Background_Texture = SDL_CreateTextureFromSurface(renderer, BMP_Surface);

	SDL_FreeSurface(BMP_Surface);
	BMP_Surface = nullptr;
}
