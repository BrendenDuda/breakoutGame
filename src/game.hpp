#ifndef GAME_HPP
#define GAME_HPP

#include "main.hpp"
#include "text.hpp"
#include "player.hpp"

struct Game {
    SDL_Window * window = 0;
    SDL_Renderer *renderer = 0;
    SDL_Texture *background = 0;
    Text *text;
    Player *player;
    SDL_Event event;
    bool isRunning = false; //Game loop runs until false
};

bool gameNew(Game ** game);//Changing not a member of game, but game itself
void gameFree(Game ** game);
void gameRun(Game * g);

#endif