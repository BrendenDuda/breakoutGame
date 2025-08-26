#include "..\include\text.hpp"

bool textNew(Text **text, SDL_Renderer *renderer) {
    *text = new Text;
    Text *t = *text;

    t->renderer = renderer;

    TTF_Font *font = TTF_OpenFont("fonts/Times New Roman.ttf", TEXT_SIZE);
    if (font == NULL) {
        fprintf(stderr, "Error opening font: %s\n", SDL_GetError());
        return false;
    }

    SDL_Surface *surf = TTF_RenderText_Blended(font, TEXT_STR, 0, WHITE_COLOUR);
    TTF_CloseFont(font);//Once surface is made, no longer need font
    font = NULL;
    if (surf == NULL) {
        fprintf(stderr, "Error rendering text to surface: %s\n", SDL_GetError());
        return false;
    }

    t->rect.w = (float)surf->w;
    t->rect.h = (float)surf->h;

    t->image = SDL_CreateTextureFromSurface(t->renderer, surf);

    SDL_DestroySurface(surf);//No longer need surface, converted into texture t->image.
    surf = NULL;
    if (t->image == NULL) {
        fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
        return false;
    }

    t->xVel = TEXT_VEL;
    t->yVel = TEXT_VEL;

    return true;
}
void textFree(Text **text) {
    if (*text) {
        Text *t = *text; //Allows use of t

        if (t->image) {
            SDL_DestroyTexture(t->image);
            t->image = NULL;
        }
        t->renderer = NULL;
        delete(t);
        t = NULL;
        *text = NULL;

        std::cout << "Text Freed" << std::endl;

    }
}


void textUpdate(Text *t) {
    t->rect.x += t->xVel;
    t->rect.y += t->yVel;
    //x-axis
    if (t->rect.x + t->rect.w > WINDOW_WIDTH) {
        t->xVel = -(TEXT_VEL);        
    }
    else if (t->rect.x < 0) {
        t->xVel = TEXT_VEL;
    }
    //y-axis
    if (t->rect.y + t->rect.h > WINDOW_HEIGHT) {
        t->yVel = -(TEXT_VEL);        
    }
    else if (t->rect.y < 0) {
        t->yVel = TEXT_VEL;
    }
}
void textDraw(const Text *t) {
    SDL_RenderTexture(t->renderer, t->image, NULL, &t->rect);
}