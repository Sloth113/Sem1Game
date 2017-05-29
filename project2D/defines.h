#pragma once
enum class eGameState
{
	SPLASH,
	MENU,
	LEVELSEL,
	INGAME,
	PAUSE,
	STATE_COUNT
};

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int SPLASH_TIME = 3;
const int SCREEN_DELAY = 3;

const int MAX_Y_MOVE = 208;
const int MIN_Y_MOVE = 33;