#include "..\include\ball.hpp"

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




void Ball :: ballUpdate() {
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
}
void Ball::ballDraw() {
    SDL_RenderTexture(renderer, image, NULL, &rect);
}