#pragma once
enum ObjectsNames
{
	openMenu_b,
	menu_b,
	win_b,
	gameOver_b,
	player_b,
	monsterConstMove_b,
	monsterRandom_b,
	monsterToPlayer_b,
	money_b,
	wall_b,
	ladder_b,
	rod_b,
	present_b,
	clock_b
};
auto const NUM_OF_LEVELS = 5;
auto const NUM_OF_OBJECTS = 14;
auto const NUM_OF_MUSIC = 5;
auto const WINDOW_WIDTH = 1000;
auto const WINDOW_HEIGHT = 600;
auto const BOARD_HEIGHT = 468;
auto const MENU_HEIGHT = 132;
auto const IMG_HEIGHT = 20;
auto const IMG_WIDTH = 20;
auto const ROW_HIGHT = 67;
auto const PLAYER = '@';
auto const MONSTER = '%';
auto const WALL = '#';
auto const ROD = '-';
auto const LADDER = 'H';
auto const PRESENT = '+';
auto const MONEY = '*';

enum Direction_t { RIGHT, DOWN, LEFT, UP, STAY };

enum Buttons
{
	start_button,
	end_button,
	non_button

};

enum music
{
	gameOverMusic_m,
	moneySound_m,
	monsterToPlayer_m,
	winMusic_m,
	presentMusic_m

};