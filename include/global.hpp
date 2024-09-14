#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <deque>
#include <fstream>
#include <iostream>
#include <math.h>
#include <random>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace sf;
using namespace std;
const int TOTAL_MONEY=300;
const string SUN_PATH = "sun.png";
const float SUN_FALLING_SPEED = 1.2;
const float SUN_TIME_SPAWN = 8000;
const float BULLET_SPEAD = 5;

const int BIG_ZOMBIE_TIME_SPAWN = 14000;
const int ZOMBIE_TIME_SPAWN = 8000;

const int NUMBER_ZOMBIE_ROW = 5;
int random_number(int min, int max);
const int PRODUCTION_VALUE = 50;
const float TIR_SPEED = 0.3;
const int WIDTH = 929;
const int HEIGHT = 600;
const int FRAME_RATE = 144;
const int PLANTS_IMAGE_MIDDLE = 44;
const string PICS_PATH = "./files/pics/", AUDIO_PATH = "./files/audio/",
             FONTS_PATH = "./files/fonts/", FONT_ADD = "Cormorant-BoldItalic.ttf",
             BACKGROUND_IMG = "bg.png", BACKGROUND_AUDIO = "bg.ogg",
             SETTING_TXT="./setting.txt",
             WINDOW_HEADER_NAME = "PLAYFUL ZOMBIES";
const string NOKHOOD_SHOTER_IMG = "nokhood.png", SNOW_SHOTR_IMG = "snow.png",
             SUNFLOWER_IMG = "sunflower.png", PORATO_IMG = "potato.png";
const string NOKHOOD_SHOTER_OPT_IMG = "nokhod_opt.jpg", SNOW_SHOTR_OPT_IMG = "snow_opt.jpg",
             SUNFLIWER_OPT_IMG = "sunflower_opt.jpg", POTATO_OPT_IMG = "potato_opt.jpg",
             MELON_OPT_IMG = "melon_opt.jpg", WIN_IMG="win.png",
             SUN_BAR = "sun_bar.jpg", GAMEOVER_IMG = "game over.png";
const string ZOMBIE_IMG = "zombie.png", BIG_ZOMBIE_IMG = "big_zombe.png";
const Color BLUE = Color(50, 115, 220);
const Color PURPLE = Color(130, 50, 220);
const Color YELLOW = Color(255, 248, 220);

const int nokhood_left = 10;
const int nokhood_top = 155;
const int nokhood_right = 128;
const int nokhood_bottom = 224;
const int snow_left = 10;
const int snow_top = 235;
const int snow_right = 128;
const int snow_bottom = 304;
const float RATE_CLOCK = 1;
const int sunflower_left = 10;
const int sunflower_top = 75;
const int sunflower_right = 128;
const int sunflower_bottom = 144;
const int potato_left = 10;
const int potato_top = 315;
const int potato_right = 128;
const int potato_bottom = 384;
const int melon_left = 10;
const int melon_top = 395;
const int melon_right = 128;
const int melon_bottom = 460;
const int melon_value = 200, nokhood_value = 100, snow_value = 150, potato_value = 50, sunflower_value = 50;

#define debug(x) cout << x << endl, exit(0);