#include "engine.h"


void Engine::InitText(TTF_Font* font, const char* message, SDL_Color color, SDL_Rect& qrect, SDL_Texture** dsttexture) {

	if ( !font || !dsttexture) {

		SDL_Log("\nOh My Goodness, an error : %s", TTF_GetError());

	}

	text_surface = TTF_RenderText_Solid(font, message, color);

	*dsttexture = SDL_CreateTextureFromSurface(renderer, text_surface);

	TTF_SizeText(font, message, &qrect.w, &qrect.h); // Get the width and height of the message

	SDL_QueryTexture(*dsttexture, NULL, NULL, &qrect.w, &qrect.h);

	SDL_FreeSurface(text_surface);
	text_surface = nullptr;

}