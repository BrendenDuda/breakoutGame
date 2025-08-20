#include "..\include\initSTL.hpp"

bool gameInitSDL (Game * g) {
    if (!SDL_Init(SDL_FLAGS)) {
        fprintf(stderr, "Error initializing sdl3: %s\n", SDL_GetError());
        return false;
    }
    if (!TTF_Init()) {
        fprintf(stderr, "Error initializing sdl3_ttf: %s\n", SDL_GetError());
        return false;
    }

    g->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (g->window == NULL) {
        fprintf(stderr, "Error Creating Window: %s\n", SDL_GetError());
        return false;
    }

    g->renderer = SDL_CreateRenderer(g->window, NULL);
    if (g->renderer == NULL) {
        fprintf(stderr, "Error Creating Renderer: %s\n", SDL_GetError());
        return false;
    }

    //Create window icon
    SDL_Surface * iconSurf = IMG_Load("images/icon.png");
    if (iconSurf == NULL) {
        fprintf(stderr, "Error loading surface: %s\n", SDL_GetError());
        return false;
    }
    if (!SDL_SetWindowIcon(g->window, iconSurf)){
        fprintf(stderr, "Error setting window icon: %s\n", SDL_GetError());
        SDL_DestroySurface(iconSurf);
        return false;
    }
    SDL_DestroySurface(iconSurf);


    return true;
}
