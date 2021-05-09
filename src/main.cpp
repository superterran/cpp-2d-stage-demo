
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "globals.h"
#include "main.h"

int main(int argc, const char* argv[]) {
    Main Main;
    return 0;
}

Main::Main() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Chicora Fantasy");
    this->gameLoop();
}

Main::~Main() {
    SDL_DestroyWindow(this->_window);
}

void Main::gameLoop() {

    while(true) {

    }
}


SDL_Surface* Main::loadImage(const std::string &filePath) {
 
    if(this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }

    return  this->_spriteSheets[filePath];
}

void Main::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Main::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Main::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Main::getRenderer() const {
    return this->_renderer;
}


