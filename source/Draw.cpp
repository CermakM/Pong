#include "engine.h"


void Engine::Draw(Flag::Game game) {

	// Clear the canvas and set target to canvas
	SDL_SetRenderTarget( renderer, canvas );
	SDL_RenderClear( renderer );

	// Copy the textures to rendering table of the canvas
	SDL_RenderCopy( renderer, Background_Texture, NULL, NULL );
	SDL_RenderCopy( renderer, Player1_Texture, NULL, &Player1->rect );
	SDL_RenderCopy( renderer, Pong_Ball_Texture, NULL, &Pong_Ball->rect );

	// Initialize score and level texts
	char buffer[20];
	font = TTF_OpenFont( "font/FFF_Tusj.ttf", 30 );
	if ( !font ) SDL_Log( "Error opening file \n%s ", SDL_GetError() );

	sprintf_s( buffer, sizeof(buffer), "Score: %d", current_score);

	InitText( font, buffer, { 50, 50, 50, 255 }, Score_Rect, &Score_Texture );
	Score_Rect.x = WIDTH - Score_Rect.w;
	Score_Rect.y = HEIGHT - Score_Rect.h;

	(level % 3) ? sprintf_s( buffer, sizeof(buffer), "Level: %d", level ) : sprintf_s( buffer, sizeof(buffer), "Level: HIT TWICE", level );
	InitText( font, buffer, { 50, 50, 50, 255 }, Level_Rect, &Level_Texture );
	Level_Rect.x = 0;
	Level_Rect.y = HEIGHT - Level_Rect.h;

	SDL_RenderCopy( renderer, Score_Texture, NULL, &Score_Rect );
	SDL_RenderCopy( renderer, Level_Texture, NULL, &Level_Rect );


	// Memory handling - in order not to create an excessive pointers
	TTF_CloseFont( font );
	SDL_DestroyTexture( Score_Texture );
	SDL_DestroyTexture( Level_Texture );
	font = nullptr;
	Score_Texture = nullptr;
	Level_Texture = nullptr;



	if ( game == Flag::MENU ) {
		SDL_RenderCopy( renderer, Title_Texture, NULL, &Title_Rect );
		Control_Button->Show();
		Start_Button->Show();
		Quit_Button->Show();

	}
	else if ( game == Flag::PAUSE ) {
		SDL_RenderCopy( renderer, Title_Texture, NULL, &Title_Rect );
		Menu_Button->Show();
		Quit_Button->Show();
	}

	
	for ( auto& brick : Brick_Wall ) {
		if ( brick.is_visible )
			SDL_RenderCopy( renderer, Brick_Texture, NULL, &brick.rect );
	}
	
	// Render the canvas to the screen
	SDL_SetRenderTarget( renderer, NULL );
	SDL_RenderClear( renderer );
	SDL_RenderCopy( renderer, canvas, NULL, NULL );

	SDL_RenderPresent(renderer); // Render everything in the clipboard to the screen
}
