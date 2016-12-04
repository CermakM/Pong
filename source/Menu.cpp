#include "engine.h"


// -------------------- User-friendly MENU for initializaiton and pause --------------------

void Engine::Menu( SDL_Event* event, Flag::Game game ) {
	SDL_Log( "Entering MENU" );

	SDL_FlushEvents( SDL_KEYDOWN, SDL_LASTEVENT );

	if ( game == Flag::PAUSE ) {
		Menu_Button->setPosition( 0, 2, HEIGHT - 150 );
		Quit_Button->setPosition( 1, 2, HEIGHT - 150 );
	}

	else {
		Control_Button->setPosition( 0, 3, HEIGHT - 150 );
		Start_Button->setPosition( 1, 3, HEIGHT - 150 );
		Quit_Button->setPosition( 2, 3, HEIGHT - 150 );
	}

	Draw( game );

	// Waits indefinitely for an event and when it comes, processes it
	// I can use this only couse I filtered out all unwanted (unprocessable) events

	while ( SDL_WaitEvent( event ) ) {	

		Uint32 init_tick = SDL_GetTicks();

		if ( event->type == SDL_QUIT ) {
			RUN = false; RESTART = false; PAUSE = false; INITIALIZATION = false;
			return;
		}

		switch ( game ) {
			case Flag::MENU:
				SDL_Log( "Entering INITIAL MENU... " );
				Draw( game );
				switch ( event->key.keysym.sym ) {

					// start game
					case SDLK_RETURN:
					case SDLK_s:
						INITIALIZATION = false;
						SDL_Log( "RETURN was pressed" );
						break;

						// quit game
					case (SDLK_q):
						INITIALIZATION = false; RUN = false; RESTART = false;
						SDL_Log( "Q was pressed" );
						break;

						// open controls
					case (SDLK_h):
						Help();
						SDL_Log( "H was pressed" );
						break;
				}
				break;

			case Flag::PAUSE:
				SDL_Log( "Entering PAUSE MENU... " );
				Draw( game );
				switch ( event->key.keysym.sym ) {

					// Return to game loop
					case SDLK_ESCAPE:
					case SDLK_RETURN:
					case SDLK_p:
						PAUSE = false;
						SDL_Log( "RETURN was pressed" );
						break;

						// quit game
					case (SDLK_q):
						PAUSE = false; RUN = false; RESTART = false;
						SDL_Log( "Q was pressed" );
						break;

						// Return to main menu
					case (SDLK_m):
						RUN = false; PAUSE = false;
						RESTART = true; INITIALIZATION = true;
						Brick_Wall.clear();
						SDL_Log( "M was pressed" );
						break;
				}
		}
		break;
	}

	SDL_PumpEvents();
	SDL_FlushEvents( SDL_KEYDOWN, SDL_LASTEVENT );

	SDL_Log( "Leaving menu" );

}


int Engine::Help() {

	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE );

	return reinterpret_cast<int> (ShellExecute( NULL, "open", "README.txt", NULL, NULL, SW_SHOWNORMAL ));
}