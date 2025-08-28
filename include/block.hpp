#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "ball.hpp"
#include "main.hpp"
class Block {
    public:
    SDL_FRect rect;
    /*
        Constructor for Block class        
        Inputs: b - a block pointer
                x - x coordinate of block
                y - y coordinate of block
                row - row for block to be positioned in (top = 0)
        */
        Block(SDL_Renderer *ren, float x, float y, int row);
        ~Block();
        void blockUpdate(Ball *b);
        void blockDraw();
        bool isHit();
    private:
        SDL_Renderer *renderer = 0;
        SDL_Texture *image = 0;
        bool hit = false; //Flag for if the block has been hit by the ball

};

#endif