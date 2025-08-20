#include "loadMedia.hpp"

bool gameLoadMedia(Game *g) {
    g->background = IMG_LoadTexture(g->renderer, "images/background.png");
    if (g->background == NULL) {
        fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());
        return false;
    }

    return true;
}