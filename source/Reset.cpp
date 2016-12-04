#include "engine.h"

void Engine::Reset(Flag::Reset rflag) {

	Pong_Ball->current_dir = STOP;
	Player1->current_dir = STOP;

	Brick_Wall.clear();

	RUN = false;

	switch (rflag) {
	case Flag::RESTART_CURRENT:
		PrintMessage(Flag::LOSE);
		break;
	case Flag::RESTART_NEXTLEVEL:
		score = current_score;
		score += 500;
		if ( !(level % 3) ) score += 1000; 
		level++;
		PrintMessage(Flag::WIN);
		break;
	}
	
	SDL_Event temp_event;
	while ( SDL_WaitEventTimeout( &temp_event, 10000 ) ) {
		if ( temp_event.type == SDL_QUIT ) {
			RESTART = false;
			return;
		}
		if ( temp_event.type == SDL_KEYDOWN ) break;
	}
}


