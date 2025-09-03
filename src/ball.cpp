#include <cmath>
#include <vector>
#include "..\include\ball.hpp"
#include "..\include\block.hpp"

Ball::Ball(SDL_Renderer *ren) {
    xVel = BALL_VEL;
    yVel = BALL_VEL;

    rect.x = WINDOW_WIDTH / 2;
    rect.y = WINDOW_HEIGHT / 2;
    renderer = ren;
    image = IMG_LoadTexture(ren, "images/ball.png");
    if (image == NULL) {
        fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());
    }
    if (!SDL_GetTextureSize(image, &rect.w, &rect.h)) {
        fprintf(stderr, "Error getting texture size: %s\n", SDL_GetError());
    }
}

Ball::~Ball() {
    if (image) {
        SDL_DestroyTexture(image);
        image = NULL;
    }

std::cout << "Ball Freed" << std::endl;
}

void Ball :: ballUpdate(std::vector<std::unique_ptr<Block>>& bl, Player *p) {
    rect.x += xVel;
    rect.y += yVel;
    //x-axis
    if (rect.x + rect.w > WINDOW_WIDTH) {
        xVel = -(BALL_VEL);        
    }
    else if (rect.x < 0) {
        xVel = BALL_VEL;
    }
    //y-axis
    if (rect.y + rect.h > WINDOW_HEIGHT) {
        yVel = -(BALL_VEL);        
    }
    else if (rect.y < 0) {
        yVel = BALL_VEL;
    }

    //Block collision
    for (int i = 0; i < bl.size(); i++) {
        double epsilon = 1e-6; //For comparing floating point values
        if (bl[i]->isHit()){
            std::cout << "block is hit" << std::endl;
            //top edge
            if (rect.y + rect.h >= bl[i]->rect.y - epsilon && abs((rect.y + rect.h) - bl[i]->rect.y) < 20) {
                yVel = -(BALL_VEL);
                std::cout << "top edge" << std::endl;

            }
            //bottom edge
            else if (bl[i]->rect.y + bl[i]->rect.h >= rect.y - epsilon && abs((bl[i]->rect.y + bl[i]->rect.h) - rect.y) < 20) {
                yVel = BALL_VEL;
                std::cout << "bottom edge" << std::endl;

            }
            //left edge
            else if (rect.x + rect.w >= bl[i]->rect.x - epsilon && abs((rect.x + rect.w) - bl[i]->rect.x) < 20) { //Intersects and is within 20 pixels of edge
                xVel = -(BALL_VEL);      
            std::cout << "Left edge" << std::endl;
            }
            //right edge
            else if (bl[i]->rect.x + bl[i]->rect.w >= rect.x - epsilon && abs((bl[i]->rect.x + bl[i]->rect.w) - rect.x) < 20) {
                xVel = BALL_VEL;
                std::cout << "Right edge" << std::endl;
            }
            else {
                break;
            }
        }
    }
    //player collision
    if (SDL_HasRectIntersectionFloat(&rect, &(p->rect))) {
        yVel = -(BALL_VEL);
    }
}
void Ball::ballDraw() {
    SDL_RenderTexture(renderer, image, NULL, &rect);
}