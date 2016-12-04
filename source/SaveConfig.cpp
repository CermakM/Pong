#include "engine.h"
#include "sys/stat.h"


bool fileExists( const char* fname ) {
	struct stat buffer;
	return !(stat( fname, &buffer )); // the stat returns 0 if file is accessible
}

void Engine::SaveConfig() {

	std::ofstream f;

	if ( !fileExists("config.txt") ) {
		f.open( "config.txt", std::ofstream::out | std::ofstream::trunc );
		SDL_Log( "WARNING: saving the config file failed.. Creating default file \"config.txt\"" );
		f << "WIDTH=1080\n" << "HEIGHT=760\n" << "score=0\n" << "level=1\n" << "SKIP_INTRO=0";
		f.close();
		return;

	}

	f.open( "config.txt", std::ofstream::out | std::ofstream::trunc );

	const char* names[] = { "WIDTH=", "HEIGH=", "score=", "level=", "SKIP_INTRO=" };

	Ushort arr[] = {WIDTH, HEIGHT, score, level, SKIP_INTRO };

	for (int i = 0; i < 5; i++) {
		f << names[i];
		f << std::to_string(arr[i]).c_str();
		f << "\n";
	}

	f.close();
}

