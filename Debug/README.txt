#### AUTHOR : MAREK CERMAK ####

#### DATE: 12_2016 
#### PONG - SIMPLE ADAPTATION OF A FAMOUS PONG GAME - SINGLE PLAYER
#### CREATED IN ASSOCIATION WITH 
	##SDL2, 
	##SDL2_TTF, 
	##SDL2_IMAGE LIBRARIES 
####

#### Launch via the exe file in "Release" folder

CONTROLS: USE ARROW KEYS OR 'A' 'S' 'D' KEYS FOR DIRECTION MOVEMENT AND STOP
	: USE SPACEBAR TO JUMP PLATFORM
	: PRESS 'P' OR 'ESCAPE' FOR PAUSING THE CURRENT GAME
	: WHILE IN PAUSE MENU, USE FOLLOWING KEYS :
		'ESC' / 'ENTER' / 'P' TO RETURN TO GAME LOOP
		'M' TO RETURN TO MAIN MENU AND START CURRENT LEVEL ALL OVER
		'Q' TO EXIT
	: WHILE IN MAIN MENU, USE THE FOLLOWING KEYS:
		'ENTER' / 'S' TO PROCEED TO THE GAME LOOP
		'H' TO OPEN HELP FILE
		'Q' TO QUIT

YOU CAN QUIT ANY TIME, YOUR CURRENT LEVEN AND SCORE WILL BE SAVED

FOR DIRECT CONFIGURATION OF YOUR GAME INCLUDING WINDOW SIZE AND SKIP INTRO, CONFIGURE 'CONFIG.TXT' FILE WITH PROPER PARAMETRES - USED FOR TESTING PURPOSES ONLY


#### KNOWN ISSUES:

-- The collision between the Paddle and the Ball works even on the level of the paddle - requires better collision calculating
-- The "config.txt" requires strict parametres and has very little exception handling, therefore, if something goes wrong, it might be the couse. Delete the "config.txt" file and see if the issue persists.