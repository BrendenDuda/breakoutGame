#include "..\include\game.hpp"
#include <SDL3/SDL_main.h> //Must be in main.cpp, with the int main function, not main.hpp


int main(int argc, char *argv[]) {
    Game *game = NULL;
    bool exitStatus = EXIT_FAILURE;

    if (gameNew(&game)){
        gameRun(game);

        exitStatus = EXIT_SUCCESS;
    }

    gameFree(&game);

    return exitStatus;
}   