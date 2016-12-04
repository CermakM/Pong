#include "engine.h"


void Engine::FPSControl(const Uint32 & init_tick, const Ushort& fps) {

	Uint32 current_tick = SDL_GetTicks() - init_tick;
	if (current_tick < 1000 / fps) {
		SDL_Delay(1000 / fps - current_tick);
	}
}

