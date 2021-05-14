
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <chrono>
#include <thread>


#include "yaml-cpp/yaml.h"


#include "globals.h"
#include "main.h"

int main(int argc, const char* argv[]) {
    Main Main;
    return 0;
}

Main::Main() {
    SDL_CreateWindowAndRenderer(globals::TILE_WIDTH*globals::TILE_ROWS, globals::TILE_WIDTH * globals::TILE_COLS, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Chicora Fantasy");
    this->gameLoop();
}

Main::~Main() {
    SDL_DestroyWindow(this->_window);
}

void Main::gameLoop() {

    // this->loadYaml();
    this->loadLevel();
   // this->drawRect(0, 0, 100, 100);
    
    while(true) {
    
        for (int y = 0; y < globals::TILE_COLS; y++) {

            for (int x = 0; x < globals::TILE_ROWS; x++) {

                std::string chr;
                chr.push_back(this->_level[y].val[x]);

                this->drawRect(x, y, chr);
            }
        }
    
        SDL_RenderPresent(this->_renderer);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        SDL_RenderClear(this->_renderer);
    
    }
}

void Main::drawRect(int x, int y, std::string sprite) {

    int r = this->_sprites[sprite].r;
    int g = this->_sprites[sprite].g;
    int b = this->_sprites[sprite].b;
    int a = this->_sprites[sprite].a;

    SDL_Rect rect;

    rect.x = x * globals::TILE_WIDTH;
    rect.y = y * globals::TILE_WIDTH;
    rect.w = globals::TILE_WIDTH;
    rect.h = globals::TILE_WIDTH;

    SDL_SetRenderDrawColor(this->_renderer, r, g, b, a);
    
    SDL_RenderFillRect(this->_renderer, &rect);


}

void Main::loadYaml() {
    YAML::Node config = YAML::LoadFile("levels/basic.yaml");
    // this->_level[] = config["level"];
}

void Main::loadLevel() {
    this->_level[0].val = "wwwwwwwwwwwwwwwwwwwwwwwww";
    this->_level[1].val = "w                       w";
    this->_level[2].val = "w                       w";
    this->_level[3].val = "w                       w";
    this->_level[4].val = "w           P           w";
    this->_level[5].val = "w                       w";
    this->_level[6].val = "w                       w";
    this->_level[7].val = "w                       w";
    this->_level[8].val = "wwwwwwwwwwwwwwwwwwwwwwwww";

    this->_sprites[" "] = { 0, 0, 0, 255 };
    this->_sprites["w"] = { 0, 255, 0, 255 };
    this->_sprites["P"] = { 0, 0, 255, 255 };
}


void Main::log(const char* message) {
    std::cout << message << std::endl;
}
