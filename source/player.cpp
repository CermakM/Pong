#include "player.h"

Player::Player(const char* fname) : GameObject(fname) {

	init_dir = STOP;

	jump_is_active = false;

	SDL_Log("The object Player has been created");
}


Player::~Player() {
	SDL_Log("The object Player has been destroyed.");
}


void Player::Move() {
	switch ( current_dir ) {
		case RIGHT: 
			rect.x >= WIDTH - PLAYER_W ? current_dir = STOP : rect.x += velocity;
			break;
		case LEFT:
			rect.x <= 0? current_dir = STOP : rect.x -= velocity;
			break;
		case JUMP:
			if ( jump_is_active )
				rect.y > origin_y - 40 ? rect.y -= velocity / 2 : jump_is_active = false;
			else rect.y < origin_y ? rect.y += velocity / 2 : current_dir = STOP;
	}		
}

void Player::setStartParam(Ushort x, Ushort y) {

	// Just an experimental value corresponding to the demanded speed
	velocity = 10 + WIDTH / 500;
	
	origin_x = rect.x = x;
	origin_y = rect.y = y;

	current_dir = init_dir;
}

void Player::Jump() {
	jump_is_active = true;
}