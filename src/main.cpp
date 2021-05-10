
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "yaml-cpp/yaml.h"


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

    this->loadYaml();
    this->drawRect(0, 0, 100, 100);
    
    // while(true) {

    // }
}

void Main::drawRect(int x, int y, int h, int w) {

    SDL_RenderClear(this->_renderer);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
    
    SDL_RenderFillRect(this->_renderer, &rect);

    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);

    SDL_RenderPresent(this->_renderer);


}

void Main::loadYaml() {
    YAML::Node config = YAML::LoadFile("levels/basic.yml");
    this->log("this is a test");
}

void Main::log(const char* message) {
    std::cout << message << std::endl;
}
