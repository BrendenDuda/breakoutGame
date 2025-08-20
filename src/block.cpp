#include "..\include\block.hpp"


bool Block :: blockNew (Block * b, SDL_Renderer *ren, float x, float y, int row) {
    b->renderer = ren;
    b->rect.x = x;
    b->rect.y = y;

    b->image = IMG_LoadTexture(b->renderer, "images/block.png");
    if (b->image == NULL) {
        fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());
        return false;
    }
    if (!SDL_GetTextureSize(b->image, &b->rect.w, &b->rect.h)) {
        fprintf(stderr, "Error getting texture size: %s\n", SDL_GetError());
        return false;

    }

}
Block :: ~Block() {
    if (image) {
            SDL_DestroyTexture(image);
            image = NULL;
        }
    renderer = NULL;

    std::cout << "Block Freed" << std::endl;
}


void Block :: blockUpdate(Ball * b) {




}
void Block :: blockDraw() {
    SDL_RenderTexture(renderer, image, NULL, &rect);
}