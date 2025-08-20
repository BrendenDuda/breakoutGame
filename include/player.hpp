#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "main.hpp"

struct Player {
    SDL_Renderer *renderer = 0;
    SDL_Texture *image = 0;
    SDL_FRect rect;
    const bool *keystate;
};

bool playerNew(Player **player, SDL_Renderer * renderer);
void playerFree(Player **player);
void playerUpdate(Player *p);
void playerDraw(const Player *p);
#endif
