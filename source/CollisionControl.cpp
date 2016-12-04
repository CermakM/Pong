#include "engine.h"


// -------------------- Check Global Colisions --------------------

void Engine::ColisionControl() {

	eDir* const Tdir = &Pong_Ball->current_dir;

	// -------------------- Check Object Colisions --------------------

	for (GameObject& brick : Brick_Wall)
	{
		// collision LEFT WALL
		if (Pong_Ball->rect.x <= 0) {
			*Tdir == ULEFT ? *Tdir = URIGHT : *Tdir = DRIGHT;
			return;
		}

		// collision RIGHT WALL
		else if (Pong_Ball->rect.x >= WIDTH - BALL_R) {
			*Tdir == URIGHT ? *Tdir = ULEFT : *Tdir = DLEFT;
			return;
		}
		// collision TOP WALL && FROM UNDERNEATH

		else if (Pong_Ball->rect.y <= 0 || brick.HasCollision(&Pong_Ball->rect)) {
			if (*Tdir == UP) { *Tdir = DOWN; return; }
			*Tdir == URIGHT ? *Tdir = DRIGHT : *Tdir == UP ? *Tdir == DOWN : *Tdir = DLEFT;
			return;
		}

		// collision FROM ABOVE - prepare for setting the score
		else if (brick.HasCollision(&Pong_Ball->rect)) {
			if (*Tdir == DOWN) { *Tdir = UP; return; }
			*Tdir == DLEFT ? *Tdir = ULEFT : *Tdir = URIGHT;
			return;
		}

		// collision UPPER CORNER
		else if (Pong_Ball->rect.x == 0 && Pong_Ball->rect.y == 0 || Pong_Ball->rect.x == WIDTH - BALL_R && Pong_Ball->rect.y == 0) {
			*Tdir = static_cast<eDir> (*Tdir * (-1)); // set reverse direction
			return;
		}

		// collision LOST CONDITION
		// + 50 added to let the ball go a bit lower under the frame
		else if (Pong_Ball->rect.y >= HEIGHT + 50) {
			Reset(Flag::RESTART_CURRENT);
			return;
		}
	}

	// --------------------

	// -------------------- Check Paddle Colision --------------------

	if (SDL_HasIntersection(&Player1->rect, &Pong_Ball->rect)) {

		// check if there are any bricks left, if not, WIN CONDITION
		std::vector<GameObject>::iterator it = Brick_Wall.begin();
		while (1) {
			if (it == Brick_Wall.end()) {
				Reset(Flag::RESTART_NEXTLEVEL);
				return;
			}
			if (it->is_visible) break;
			it++;
		}

		switch (Player1->current_dir) {
		case STOP:
			if (*Tdir == DOWN) { *Tdir = UP; return; }
			*Tdir == DLEFT ? *Tdir = ULEFT : *Tdir = URIGHT;
			break;
		case RIGHT:
			*Tdir = URIGHT;
			break;
		case LEFT:
			*Tdir = ULEFT;
			break;
		case JUMP:
			Pong_Ball->Jump();
		}
	}

	// --------------------
}