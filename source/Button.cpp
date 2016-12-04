#include "Button.h"

Button::Button(const char* name, SDL_Renderer** engine_renderer ) {

	SDL_Log( "Button object has been created" );

	texture = nullptr;
	renderer = *engine_renderer;

	rect = { 0 };
	font = TTF_OpenFont( "font/FFF_Tusj.ttf", 50 );
	if ( !font) {

		SDL_Log( "\nOh My Goodness, an error : %s", TTF_GetError() );

	}
	// -------------------- Create text texture --------------------
	SDL_Surface* surface;
	
	surface = TTF_RenderText_Solid( font, name, { 200, 20, 30, 255 });

	texture = SDL_CreateTextureFromSurface( renderer, surface );

	TTF_SizeText( font, name, &rect.w, &rect.h ); // Get the width and height of the message

	SDL_QueryTexture( texture, NULL, NULL, &rect.w, &rect.h );

	// -------------------- Create rectangle texture --------------------

	surface = SDL_ConvertSurfaceFormat( surface, SDL_PIXELFORMAT_RGBA8888, 0 );
	Uint32 color = SDL_MapRGBA( surface->format, 50, 50, 50, 255 );
	SDL_FillRect( surface, &rect, color );

	rect_texture = SDL_CreateTextureFromSurface( renderer, surface );

	setBlind();

	SDL_FreeSurface( surface );
	surface = nullptr;
}


Button::~Button() {

	SDL_DestroyTexture( rect_texture );
	rect_texture = nullptr;
	SDL_DestroyTexture( texture );
	texture = nullptr;
	TTF_CloseFont( font );
	font = nullptr;

	SDL_Log( "Button object has been destroyed" );
}


bool Button::isGood() {

	return texture == nullptr ? 0 : 1;
}


void Button::setPosition( Ushort position, Ushort total_rects, Ushort y ) {

	Ushort offset = (WIDTH - total_rects*rect.w) / (total_rects + 1);

	rect.x = offset + position* (offset + rect.w);
	rect.y = y;

}

void Button::setFocus() {

	SDL_SetTextureAlphaMod( rect_texture, 100 );

}


void Button::setBlind() {

	SDL_SetTextureAlphaMod( rect_texture, 0 );
}


void Button::Show() {

	SDL_RenderCopy( renderer, rect_texture, NULL, &rect );
	SDL_RenderCopy( renderer, texture, NULL, &rect );
}