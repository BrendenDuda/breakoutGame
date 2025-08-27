#ifndef BALL_HPP
#define BALL_HPP

#include "main.hpp"
class Ball {
    public:
        SDL_FRect rect;
        Ball(SDL_Renderer *ren);
        ~Ball();
        void ballUpdate();
        void ballDraw();
    private:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        float xVel;
        float yVel;
};

#endif