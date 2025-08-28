#include "..\include\game.hpp"
#include "..\include\initSTL.hpp"
#include "..\include\loadMedia.hpp"
#include "..\include\block.hpp"

void gameEvents(Game *g);
void gameUpdate(Game *g);
void gameDraw(Game *g);

bool gameNew(Game **game) {//Game constructor
    *game = new Game;
    Game *g = *game; //Allows g-> vs (*game)->
    if(!gameInitSDL(g)){
        return false;
    }

    if(!gameLoadMedia(g)){
        return false;
    }

    if (!textNew(&g->text, g->renderer)){
        return false;
    }
    if (!playerNew(&g->player, g->renderer)){
        return false;
    }
    g->isRunning = true;

    g->bl.push_back(std::make_unique<Block>(g->renderer,10.0,10.0,0));
    g->b = new Ball(g->renderer);   
    return true;
}

void gameFree(Game **game) {

    if (*game){
        Game * g = *game;
        if (g->player) {
            playerFree(&g->player);
        }
        if (g->text) {
            textFree(&g->text);
        }

        if (g->background) {
            SDL_DestroyTexture(g->background);
            g->background = NULL;
        }

        if (g->renderer != NULL){
            SDL_DestroyRenderer(g->renderer);
            g->renderer = NULL;
        }
        
        if (g->window != NULL){
            SDL_DestroyWindow(g->window);
            g->window = NULL;
        }
    if(g->bl[0]) {
        g->bl.erase(g->bl.begin());
    }
    delete (g->b);

    TTF_Quit();
    SDL_Quit();
    delete (g);
    g = NULL;
    *game = NULL;
    std::cout << "All Clean" << std::endl;
    }
}

void gameEvents(Game *g){
    while (SDL_PollEvent(&g->event)) {
        switch(g->event.type) {
            case SDL_EVENT_QUIT: //Quit game
                g->isRunning = false;
                break;
            case SDL_EVENT_KEY_DOWN: //Keyboard event
                switch (g->event.key.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        g->isRunning = false;
                        break;
                    default:
                        break;
                }
            default:
                break;
            }
        }
}

void gameUpdate(Game *g) {
    textUpdate(g->text);
    playerUpdate(g->player);
    if (g->bl[0]) {
        g->bl[0]->blockUpdate(g->b);
    }
    g->b->ballUpdate(g->bl);
    if (g->bl[0]) {
        if (g->bl[0]->isHit()) {
            g->bl.erase(g->bl.begin());
        }
    }
}

void gameDraw(Game *g) {
    SDL_RenderClear(g->renderer);
    SDL_RenderTexture(g->renderer, g->background, NULL, NULL);
    textDraw(g->text);
    playerDraw(g->player);
    if (g->bl[0]){
        g->bl[0]->blockDraw();
    }
    g->b->ballDraw();

    SDL_RenderPresent(g->renderer);
}

void gameRun(Game *g){
    while (g->isRunning) {
        gameEvents(g);
        gameUpdate(g);
        SDL_Delay(16); //1000ms/60frames (~60fps)
        gameDraw(g);
    }
    
    SDL_Delay(16);
}
