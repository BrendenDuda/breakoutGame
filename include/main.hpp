#ifndef MAIN_HPP
#define MAIN_HPP

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

#include "main.hpp"

#define SDL_FLAGS SDL_INIT_VIDEO

#define WINDOW_TITLE "Breakout"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define TEXT_SIZE 80
#define WHITE_COLOUR (SDL_Color) {255,255,255,255}
#define TEXT_STR "TEST"
#define BALL_VEL 5
#define TEXT_VEL 3

#define PLAYER_VEL 5

#endif