#include "..\include\block.hpp"

Block :: Block (SDL_Renderer *ren, float x, float y, int row) {
    rect.x = x;
    rect.y = y;
    renderer = ren;
    image = IMG_LoadTexture(ren, "images/block.png");
    if (image == NULL) {
        fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());

    }

    if (!SDL_GetTextureSize(image, &rect.w, &rect.h)) {
        fprintf(stderr, "Error getting texture size: %s\n", SDL_GetError());
    }
}

Block :: ~Block() {
    if (image) {
            SDL_DestroyTexture(image);
            image = NULL;
        }

    std::cout << "Block Freed" << std::endl;
}


void Block :: blockUpdate(Ball *b) {
    if (!(SDL_HasRectIntersectionFloat(&rect, &(b->rect)))) {
        return;
    }
    hit = true;
}

void Block :: blockDraw() {
    if(!SDL_RenderTexture(renderer, image, NULL, &rect)) {
        fprintf(stderr, "Error rendering block: %s\n", SDL_GetError());
    }
}

bool Block :: isHit () {
    return hit;
}