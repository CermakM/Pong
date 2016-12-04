#include "ball.h"

Ball::Ball(const char* fname) : GameObject(fname) {

	init_dir = DOWN;

	SDL_Log("The object Ball has been created");
}

Ball::~Ball() {
	SDL_Log("The object Ball has been destroyed.");
}

void Ball::Move() {

	if ( current_dir == ULEFT ) {
		rect.x -= velocity; rect.y -= velocity;
	}
	else if ( current_dir == URIGHT ) {
		rect.x += velocity; rect.y -= velocity;
	}

	else if ( current_dir == DRIGHT )
	{
		rect.x += velocity; rect.y += velocity;
	}
	else if ( current_dir == DLEFT ) {
		rect.x -= velocity; rect.y += velocity;
	}

	else if ( current_dir == UP ) {
		rect.y -= velocity;
	}

	else if ( current_dir == DOWN )
	{
		rect.y += velocity;
	}

}


void Ball::setStartParam( Ushort x, Ushort y) {

	// Just an experimental value corresponding to the demanded speed
	velocity = 5 + HEIGHT / 400; 

	times_jumped = 0;

	origin_x = rect.x = x;
	origin_y = rect.y = y;

	current_dir = DOWN;
}

void Ball::Jump() {

	times_jumped++;

	if ( !(times_jumped % 4)) velocity += 1;

	current_dir = UP;

}