
// A simple Pong game version 1.2a
// Author: M. Cermak, 2016
// For info see the enclosed README file

#include "engine.h"

using namespace std;

int main( int argc, char *argv[] ) {

	SDL_Event EVENT;

	Engine GE;

	Uint32 init_tick;

	SDL_SetEventFilter( EventFilter, &EVENT );

	GE.Intro();

	while ( RESTART ) {
		
		GE.Start();

		while ( INITIALIZATION ) {

			GE.Menu( &EVENT, Flag::MENU );

		}
		
		if ( !RUN ) break;

		GE.InitCountdown();

		while ( RUN ) {

			init_tick = SDL_GetTicks();

			while ( SDL_PollEvent( &EVENT ) ) {

				if ( EVENT.type == SDL_QUIT ) {
					RUN = false; RESTART = false;
				}

				if ( EVENT.type == SDL_KEYDOWN ) {

					GE.ChangePlayerDirection( &EVENT.key );

					if ( EVENT.key.keysym.sym == SDLK_p || EVENT.key.keysym.sym == SDLK_ESCAPE ) {

						SDL_Log( "Key P pressed" );

						PAUSE = true;
					}
				}
			}


			while ( PAUSE ) { GE.Menu( &EVENT, Flag::PAUSE ); }

			GE.MovementControl();

			GE.ColisionControl();

			GE.Draw();

			GE.FPSControl( init_tick, FPS );

		} // game logic
	}

	GE.PrintMessage( Flag::QUIT );

	SDL_Delay( 2500 );

	return 0;

} // main
