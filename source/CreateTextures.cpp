#include "engine.h"

void Engine::CreateTextures() {

	canvas = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBX8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT );

	Player1_Texture = SDL_CreateTextureFromSurface( renderer, Player1->image );
	Pong_Ball_Texture = SDL_CreateTextureFromSurface( renderer, Pong_Ball->image );

	GameObject Brick( "images/brick.png" );

	Brick_Texture = SDL_CreateTextureFromSurface( renderer, Brick.image );

	font = TTF_OpenFont( "font/FFF_Tusj.ttf", 100 );
	InitText( font, "PONG", { 200, 180, 30, 255 }, Title_Rect, &Title_Texture );

	Title_Rect.x = (WIDTH - Title_Rect.w) / 2; Title_Rect.y = HEIGHT / 5;

	TTF_CloseFont( font );
	font = nullptr;
}

