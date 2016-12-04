#pragma once

#include "stdafx.h"
#include "config.h"
#include "gameobject.h"
#include "ball.h"
#include "player.h"
#include "Button.h"

struct Flag {
	enum Game { MENU, CONTROLS, PAUSE, OBJECT};
	enum Reset { RESTART_CURRENT, RESTART_NEXTLEVEL};
	enum Message { QUIT, LOSE, WIN, };
};

class Engine
{
private:

	/**
	*	\Rendering properties
	*/
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* canvas;
	SDL_Surface* text_surface;
	TTF_Font* font;

	/**
	*	\Game object textures
	*/
	SDL_Texture* Background_Texture;
	SDL_Texture* Player1_Texture;
	SDL_Texture* Pong_Ball_Texture;
	SDL_Texture* Brick_Texture;
	SDL_Texture* text_temp_texture;

	SDL_Texture* Title_Texture;
	SDL_Texture* Score_Texture;
	SDL_Texture* Level_Texture;
	SDL_Rect Title_Rect;
	SDL_Rect Score_Rect;
	SDL_Rect Level_Rect;

	/**
	*	\Game objects
	*/
	GameObject* Player1;
	GameObject* Pong_Ball;
	Button* Menu_Button;
	Button* Control_Button;
	Button* Start_Button;
	Button* Quit_Button;
	

	std::vector<GameObject> Brick_Wall;

	
public:
	
	Engine();
    ~Engine();

	/**
	*	\Load configuration file and sets up startup variables
	*	If there is none, creates a new config file with default parametres 
	*/
	void LoadConfig();


	/**
	*	\Saves current configuration into the config.txt file 
	*/
	void SaveConfig();


	void CreateGameWindow();

	void CreateTextures();

	void CreateBackground();


	/**
	*	\Creates a system of textures - bricks - to be shot by the player
	*/
	void BuildBricks();


	/**
	*	\Renders to the screen textures according to the flag
	*	If no flag is provided, it renders only basic textures for animation
	*/
	void Draw( Flag::Game game = Flag::OBJECT );

	
	/**
	*	\Filtres the unwanted events
	*	\Set to filter keyups - prevents repetition - and mousemotion
	*/
	friend int EventFilter( void* userdata, SDL_Event* event );


	/**
	*	\Creates a short intro animation simply with PONG text
	*/
	void Intro();


	/**
	*	\Create a second thread with keyboard input checking
	*	\User options: return to main menu, view help and exit
	*/
	void Menu( SDL_Event* event, Flag::Game);
	
	void Start();

	/**
	*	\Opens the README.txt file
	*/
	int Help();

	void Reset( Flag::Reset );


	/** 
	*	\Release countdown by sceonds before start of the game
	*/
	void InitCountdown();


	/**
	*	\TTF_Font created using TTF_OpenFont()
	*	\the message to be printed
	*	\color formated {R, G, B, A} or SDL_Color format
	*	\SDL_Rect has to be used to position the initialized texture
	*	\Initialize a shorter text segment and saves it into the current renderer.
	*	 The texture is saved into the text_temp_texture private member and has to be destroyed manually
	*/
	void InitText( TTF_Font*, const char*, SDL_Color, SDL_Rect&, SDL_Texture** );


	/** 
	*	 \Initialize a message image to the flagg and saves it into the current renderer 
	*/
	void PrintMessage( Flag::Message );

	void ChangePlayerDirection( SDL_KeyboardEvent* );

	void MovementControl();

	void ColisionControl();

	
	/**
	*	\reference to initial SDL_GetTicks() function
	*	\frames(ticks) per second to be done
	*/
	void FPSControl(const Uint32 & init_tick, const Ushort& fps );



};