#include "engine.h"


void Engine::LoadConfig() {

	std::ifstream f;
	f.open( "config.txt", std::ifstream::in );
	if ( !f.good() ){
		SDL_Log( "WARNING: opening the config file failed.. Creating default file \"config.txt\"" );
		SaveConfig();
		f.open( "config.txt", std::ifstream::in );
	}

	// Read from a file 
	std::string item;
	std::vector<std::string> configs;
	while ( std::getline( f, item ) ) {
		// Text parse using string library
		std::size_t pos = item.find( "=" );
		if ( pos == std::string::npos ) SDL_Log( "WARNING: Wrong config format!" );
		std::string data_string = item.substr( pos + 1 );
		configs.push_back( data_string );
	}


	WIDTH = std::stoi( configs[0] );
	HEIGHT = std::stoi( configs[1] );
	score = std::stoi( configs[2] );
	level = std::stoi( configs[3] );
	SKIP_INTRO = std::stoi( configs[4] );

	f.close();
}