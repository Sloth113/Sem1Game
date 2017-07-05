#pragma once
//Global consts and states 
enum class eGameState
{
	SPLASH,
	MENU,
	SCORES,
	INGAME,
	PAUSE,
	STATE_COUNT
};

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int SPLASH_TIME = 3;
const int SCREEN_DELAY = 3;

const float GAMETIME = 15;
