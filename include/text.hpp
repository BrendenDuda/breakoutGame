#ifndef TEXT_HPP
#define TEXT_HPP

#include "main.hpp"

struct Text {
    SDL_Renderer *renderer = 0;
    SDL_Texture *image = 0;
    SDL_FRect rect;
    float xVel;
    float yVel;
};

bool textNew(Text ** text, SDL_Renderer * renderer);
void textFree(Text ** text);
void textUpdate(Text * t);
void textDraw(const Text * t);

#endif