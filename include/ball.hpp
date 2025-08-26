#ifndef BALL_HPP
#define BALL_HPP

#include "main.hpp"
class Ball {
    public:
        Ball(SDL_Renderer *ren);
        ~Ball();
        void ballUpdate();
        void ballDraw();
    private:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        SDL_FRect rect;
        float xVel;
        float yVel;
};

#endif