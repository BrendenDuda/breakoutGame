#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "main.hpp"
#include "ball.hpp"
class Block {
    public:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        SDL_FRect rect;

        /*
        Constructor for a block
        Inputs: x - x coordinate of block
                y - y coordinate of block
                row - row for block to be positioned in (top = 0)
        */
        Block(float x, float y, int row);
        ~Block();
        void blockUpdate(Ball * b);
        void blockDraw();
};

#endif