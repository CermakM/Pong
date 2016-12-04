#include "engine.h"

// -------------------- Initialize a 3-2-1-GO countdown before gaming loop --------------------

void Engine::InitCountdown() {

	SDL_Rect text_rect;

	font = TTF_OpenFont("font/FFF_Tusj.ttf", 200);

	std::vector<const char*> countdown{ "3", "2", "1", "GO" };

	Uint8 alpha = 255;

	// alpha decremented by 5 each loop

	for (auto& c : countdown) {

		InitText(font, c, { 120, 30, 30, 255 }, text_rect, &text_temp_texture);

		while (alpha) {

			Uint32 init_time = SDL_GetTicks();

			SDL_SetTextureAlphaMod(text_temp_texture, alpha);

			text_rect.x = (WIDTH - text_rect.w) / 2; text_rect.y = (HEIGHT - text_rect.h) / 2;

			SDL_RenderClear(renderer);

			SDL_RenderCopy(renderer, canvas, NULL, NULL);

			SDL_RenderCopy(renderer, text_temp_texture, NULL, &text_rect);

			SDL_RenderPresent(renderer);

			alpha -= 5;

			// Limit set to 255 / 5 = 51 ticks per second => countdown is set to number per sec

			FPSControl(init_time, 51);
		}

		alpha = 255;

		SDL_DestroyTexture(text_temp_texture);
		text_temp_texture = nullptr;
	}

	SDL_PumpEvents();
	SDL_FlushEvent( SDL_KEYDOWN );
	SDL_FlushEvent( SDL_QUIT );

	TTF_CloseFont(font);
	font = nullptr;
}

// -------------------- 