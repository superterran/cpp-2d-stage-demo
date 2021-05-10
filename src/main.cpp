
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
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
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
    
  //  while(true) {
    
        for (int x = 0; x < 9; x++) {
            
            std::cout << "\n";
            for (int y = 0; y < 14; y++) {
    
                std::cout << this->_level[x].val[y] << " ";
     
                std::string chr;
                chr.push_back(this->_level[x].val[y]);

                this->drawRect(x, y, chr);
            }
        }
    
        SDL_RenderPresent(this->_renderer);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        SDL_RenderClear(this->_renderer);
    
   // }
}

void Main::drawRect(int x, int y, std::string tile) {

    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;

    for (int i = 0; i < 26; i++) {

        if (this->_tiles[i].id == tile) {
            r = this->_tiles[i].r;
            g = this->_tiles[i].g;
            b = this->_tiles[i].b;
            a = this->_tiles[i].a;
            break;
        }
    }
    
    SDL_Rect rect;
    rect.x = x*10;
    rect.y = y*10;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(this->_renderer, r, g, b, a);
    
    SDL_RenderFillRect(this->_renderer, &rect);


}

void Main::loadYaml() {
    YAML::Node config = YAML::LoadFile("levels/basic.yaml");
    // this->_level[] = config["level"];
}

void Main::loadLevel() {
    this->_level[0].val = "wwwwwwwwwwwwww";
    this->_level[1].val = "w            w";
    this->_level[2].val = "w            w";
    this->_level[3].val = "w            w";
    this->_level[4].val = "w     P      w";
    this->_level[5].val = "w            w";
    this->_level[6].val = "w            w";
    this->_level[7].val = "w            w";
    this->_level[8].val = "wwwwwwwwwwwwww";

    this->_tiles[0].id = " "; 
    this->_tiles[0].r = 0;
    this->_tiles[0].g = 0;
    this->_tiles[0].b = 0;
    this->_tiles[0].a = 255;

    this->_tiles[1].id = "w";
    this->_tiles[1].r = 0;
    this->_tiles[1].g = 255;
    this->_tiles[1].b = 0;
    this->_tiles[1].a = 255;

    this->_tiles[2].id = "P";
    this->_tiles[2].r = 0;
    this->_tiles[2].g = 0;
    this->_tiles[2].b = 255;
    this->_tiles[2].a = 255;

}


void Main::log(const char* message) {
    std::cout << message << std::endl;
}
