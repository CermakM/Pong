#include "engine.h"


void Engine::Intro() {

	// Load fonts
	//font_pong = TTF_OpenFont( "Fonts/FFF_Tusj.ttf", 100 );

	SDL_Rect rect_title;

	bool alpha_set = false;
	Uint8 alpha = 1;
	Uint8 size;
	
	INITIALIZATION = true;

	while (alpha) {

		const Uint8* keyboardState = SDL_GetKeyboardState( NULL );

		SDL_PumpEvents();
		
		if ( SKIP_INTRO | keyboardState[SDL_SCANCODE_ESCAPE]) return;
		
		size = alpha;

		font = TTF_OpenFont("font/FFF_Tusj.ttf", size);

		InitText(font, "PONG", { 200, 180, 30, 255 }, rect_title, &text_temp_texture);

		rect_title.x = (WIDTH - rect_title.w) / 2; rect_title.y = (HEIGHT - rect_title.h) / 2;

		SDL_SetTextureAlphaMod(text_temp_texture, alpha);

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, Background_Texture, NULL, NULL);
		SDL_RenderCopy(renderer, text_temp_texture, NULL, &rect_title);
		SDL_RenderPresent(renderer);

		SDL_Delay(10);

		if (alpha == 255) alpha_set = true;
		alpha_set ? alpha-- : alpha++;

		TTF_CloseFont(font);
		font = nullptr;
		SDL_DestroyTexture(text_temp_texture);
		text_temp_texture = nullptr;
	}
}