#include "engine.h"

void Engine::ChangePlayerDirection(SDL_KeyboardEvent* key) {
	switch (key->keysym.sym) {
	case SDLK_RIGHT:
	case SDLK_d:
		Player1->current_dir = RIGHT;
		break;
	case SDLK_LEFT:
	case SDLK_a:
		Player1->current_dir = LEFT;
		break;
	case SDLK_DOWN:
	case SDLK_s:
		Player1->current_dir = STOP;
		break;
	case SDLK_SPACE:
		Player1->Jump();
		Player1->current_dir = JUMP;
		break;
	}
}