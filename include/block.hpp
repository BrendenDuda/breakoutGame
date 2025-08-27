#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "main.hpp"
#include "ball.hpp"
class Block {
    public:
        /*
        Constructor for Block class        
        Inputs: b - a block pointer
                x - x coordinate of block
                y - y coordinate of block
                row - row for block to be positioned in (top = 0)
        */
        Block(SDL_Renderer *ren, float x, float y, int row);
        ~Block();
        void blockUpdate(Ball * b);
        void blockDraw();
        bool isHit();
    private:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        SDL_FRect rect;
        bool hit = false; //Flag for if the block has been hit by the ball

};

#endif