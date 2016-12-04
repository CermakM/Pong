#include "engine.h"


// -------------------- Basic Initializaiton of parameters --------------------

void Engine::Start() {

	RUN = true;

	if ( level > 6 ) { score += 10000; level = 1; }

	current_score = score;

	Player1->setStartParam( (WIDTH - PLAYER_W) / 2, HEIGHT - 60 );

	Pong_Ball->setStartParam( (WIDTH - BALL_R) / 2, (HEIGHT - BALL_R) / 2 );

	BuildBricks();

	Draw();

	Pong_Ball->velocity += level / 2;

	Player1->velocity += level / 3;
}

// --------------------
