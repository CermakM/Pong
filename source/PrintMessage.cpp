#include "engine.h"

// -------------------- Set up messages  --------------------

void Engine::PrintMessage(Flag::Message messg) {

	SDL_Rect text_rect;

	switch (messg) {
	case Flag::LOSE:
		text_surface = IMG_Load("images/parch_lose.png");
		break;

	case Flag::WIN:
		text_surface = IMG_Load("images/parch_win.png");
		break;

	case Flag::QUIT:
		text_surface = IMG_Load("images/parch_quit.png");
		break;
	}

	text_temp_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

	if (!text_surface | !text_temp_texture) {
		SDL_Log("\nOh My Goodness, an error : %s %s", IMG_GetError(), SDL_GetError());
	}

	SDL_FreeSurface(text_surface);

	// ----------- Set up the distance rectangle and render

	SDL_QueryTexture(text_temp_texture, NULL, NULL, &text_rect.w, &text_rect.h);

	const Ushort frames = 20;
	const Ushort frameheight = text_rect.h / frames;

	// Create distance rectangle - its y position is incremented along with source rect y position by frameheight
	// Source rectangle used to get the partition of the texture - to prevent blurry image

	SDL_Rect dstrect;
	text_rect.x = 0; text_rect.y = 0;
	text_rect.h = frameheight;

	dstrect.x = (WIDTH - text_surface->w) / 2;
	dstrect.y = (HEIGHT - text_surface->h) / 2;
	dstrect.w = text_rect.w; dstrect.h = text_rect.h;


	for (int i = 0; i < frames; i++)
	{
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopy(renderer, text_temp_texture, &text_rect, &dstrect);
		SDL_RenderPresent(renderer);
		SDL_Delay(15);
		text_rect.y += frameheight; dstrect.y += frameheight;
	}

	// ----------- Memory handling

	SDL_DestroyTexture(text_temp_texture);
	text_surface = nullptr;
	text_temp_texture = nullptr;
}

// -------------------- 
