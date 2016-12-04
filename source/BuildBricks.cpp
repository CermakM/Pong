#include "engine.h"


// Build the brick-grid according to the current level

void Engine::BuildBricks() {

	Ushort first_brick = WIDTH  % BRICK_W / 2;
	for (int i = 5; i <= 30 * level; i += 30) {
		for (int j = first_brick; j < WIDTH - BRICK_W; j += BRICK_W) {
			GameObject Brick("images/brick.png");
			Brick.setStartParam(j, i);
			Brick_Wall.push_back(Brick);
			if ( !(level % 3) ) 
				Brick_Wall.push_back( Brick );
		}
	}
}

// --------------------
