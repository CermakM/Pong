#include "engine.h"


int EventFilter( void* userdata, SDL_Event* event ) {

	if ( event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONDOWN ) {
		return 0;
	}

	else if ( event->type == SDL_KEYUP ) {
		SDL_Log( "Warning: Keyup repetition filtered." );
		return 0;
	}

	else if ( event->type != SDL_QUIT && event->type == SDL_WINDOWEVENT ) {
		SDL_Log( "Warning: Window event filtered." );
		return 0;
	}

	return 1;

}
