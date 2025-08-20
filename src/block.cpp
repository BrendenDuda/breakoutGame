#include "..\include\block.hpp"



Block :: Block(float x, float y, int row) {




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




}