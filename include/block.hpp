#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "main.hpp"
#include "ball.hpp"
class Block {
    public:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        SDL_FRect rect;

        ~Block();
        /*
        Updates a block to populate its SDL components.
        Needed to be able to return false on SDL function failure.
        Inputs: b - a block pointer
                x - x coordinate of block
                y - y coordinate of block
                row - row for block to be positioned in (top = 0)
        */
        bool blockNew(Block * b, SDL_Renderer *ren, float x, float y, int row);
        void blockUpdate(Ball * b);
        void blockDraw();
     private:
        Block();

};

#endif