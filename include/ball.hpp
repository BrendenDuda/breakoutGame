#ifndef BALL_HPP
#define BALL_HPP

#include <vector>
#include <memory>
//#include "block.hpp"
#include "main.hpp"

class Block; //Foreward declaration to prevent circular includes.
class Ball {
    public:
        SDL_FRect rect;
        Ball(SDL_Renderer *ren);
        ~Ball();
        void ballUpdate(std::vector<std::unique_ptr<Block>>& bl);
        void ballDraw();
    private:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        float xVel;
        float yVel;
};

#endif