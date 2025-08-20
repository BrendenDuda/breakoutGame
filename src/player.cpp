#include "player.hpp"

bool playerNew(Player **player, SDL_Renderer *renderer) {
    *player = new Player;
    Player *p = *player;

    p->renderer = renderer;

    p->image = IMG_LoadTexture(p->renderer, "images/player.png");
    if (p->image == NULL) {
        fprintf(stderr, "Error loading texture: %s\n", SDL_GetError());
        return false;
    }

    if (!SDL_GetTextureSize(p->image, &p->rect.w, &p->rect.h)) {
        fprintf(stderr, "Error getting texture size: %s\n", SDL_GetError());
        return false;

    }
    p->rect.x = 0;
    p->rect.y = 0;

    p->keystate = SDL_GetKeyboardState(NULL);

    return true;
}
void playerFree(Player **player) {
    if (*player) {
        Player *p = *player; //Allows use of p

        if (p->image) {
            SDL_DestroyTexture(p->image);
            p->image = NULL;
        }
        p->renderer = NULL;
        p->keystate = NULL;

        delete(p);
        p = NULL;
        *player = NULL;

        std::cout << "Player Freed" << std::endl;
    }

}

void playerUpdate(Player *p) {
    if (p->keystate[SDL_SCANCODE_LEFT] || p->keystate[SDL_SCANCODE_A]) {
        if (p->rect.x != 0) {
            p->rect.x -= PLAYER_VEL;
        }
    }
    if (p->keystate[SDL_SCANCODE_RIGHT] || p->keystate[SDL_SCANCODE_D]) {
        if (!(p->rect.x + p->rect.w > WINDOW_WIDTH)) {//If at right edge of window dont move right
            p->rect.x += PLAYER_VEL;
        }
    }
    if (p->keystate[SDL_SCANCODE_UP] || p->keystate[SDL_SCANCODE_W]) {
        if (p->rect.y > 0) { //If not at top, allow to move up
            p->rect.y -= PLAYER_VEL;
        }
    }
    if (p->keystate[SDL_SCANCODE_DOWN] || p->keystate[SDL_SCANCODE_S]) {
        if (!(p->rect.y + p->rect.h > WINDOW_HEIGHT)) {
            p->rect.y += PLAYER_VEL;
        }
    }
}

void playerDraw(const Player *p) {
    SDL_RenderTexture(p->renderer, p->image, NULL, &p->rect);
}
