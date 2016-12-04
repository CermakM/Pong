#include "gameobject.h"

GameObject::GameObject(const char* fname) {
	// image = std::auto_ptr<SDL_Surface>( IMG_Load( fname ) );
	image = IMG_Load( fname );
	if (!image) SDL_Log("Image Load: %s\n", IMG_GetError()); // handles an error

	rect = image->clip_rect;

	SDL_Log("The object GameObject has been created");
}

GameObject::~GameObject() {
	SDL_Log("The object GameObject has been destroyed.");
}


void GameObject::setStartParam( Ushort x, Ushort y) {

	current_dir = STOP;

	is_visible = VISIBLE;

	velocity = 0;

	rect.x = x; rect.y = y;

}

void GameObject::Jump() {

	// Inteded to use while collision of basic game objects ( like falling bricks ) 
}


void GameObject::Move() {

	// Intended to use for higher levels - moving bricks

}

bool GameObject::HasCollision(SDL_Rect* object) {
	if ( this->is_visible ) {
		if ( SDL_HasIntersection( &this->rect, object ) ) {
			this->is_visible = INVISIBLE;
			( level % 3 ) ? current_score += 100 : current_score += 50;
			return true;
		}	
	}

	return false;
}