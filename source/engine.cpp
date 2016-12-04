#include "engine.h"

// Picture size : Player = 17 x 100
// Picture size : Ball = 35 x 35
// Window  size : 640 x 480
// Temporary solution - intend to read from a config file

const char* game_title = "PONG_v1.2";

const Ushort PLAYER_W = 100;
const Ushort PLAYER_H = 20;
const Ushort BALL_R = 35;
const Ushort BRICK_W = 70;

const Ushort FPS = 60;

bool SKIP_INTRO;

bool INITIALIZATION = true;

bool RUN = true;

bool RESTART = true;

bool PAUSE = false;

Ushort WIDTH;
Ushort HEIGHT;
Ushort score;
Ushort level;
Ushort current_score;

Engine::Engine() {

	// Initialize the SDL and IMG libraries
	SDL_Init( SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF );
	TTF_Init();

	font = nullptr;
	text_surface = nullptr;
	text_temp_texture = nullptr;

	LoadConfig();

	Player1 = new Player( "images/Paddle1.png" );
	Pong_Ball = new Ball( "images/ball.png" );

	SDL_Log( "Engine was started. Initializing SDL.. \n" );

	// Create a renderer to render the texture bitmap surfaces with;
	CreateGameWindow();

	// Assign textures
	CreateTextures();
	CreateBackground();

	// Create buttons;
	Menu_Button = new Button( "MENU", &renderer );
	Quit_Button = new Button( "QUIT", &renderer );
	Start_Button= new Button( "START", &renderer );
	Control_Button = new Button( "HELP", &renderer );
}


Engine::~Engine() {

	SaveConfig();

	SDL_DestroyTexture( Background_Texture );
	SDL_DestroyTexture( Player1_Texture );
	SDL_DestroyTexture( Pong_Ball_Texture );
	SDL_DestroyTexture( Brick_Texture );
	SDL_DestroyTexture( canvas );

	SDL_DestroyRenderer(renderer);
    
	SDL_DestroyWindow(window);
	
	delete Player1;
	delete Pong_Ball;
	delete Menu_Button;
	delete Quit_Button;

	SDL_Log("Engine was stopped\n");
	SDL_Quit();
}
