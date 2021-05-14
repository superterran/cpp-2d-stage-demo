
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <chrono>
#include <thread>

#include "yaml-cpp/yaml.h"

#include "globals.h"
#include "input.h"
#include "main.h"

int main(int argc, const char* argv[]) {
    Main Main;
    return 0;
}

Main::Main() {
    SDL_CreateWindowAndRenderer(globals::TILE_WIDTH*globals::TILE_ROWS, globals::TILE_WIDTH * globals::TILE_COLS, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Chicora Fantasy");

    this->_timer = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

    this->gameLoop();
}

Main::~Main() {
    SDL_DestroyWindow(this->_window);
}

void Main::gameLoop() {

    // this->loadYaml();

    this->loadLevel();
    auto FPS = std::chrono::milliseconds(1000 / globals::FPS);

    SDL_Event event;
    Input input;                        


    while(true) {

        input.beginNewFrame();
        
        if(SDL_PollEvent(&event)) {
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            }
            else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            else if (event.type == SDL_QUIT) {
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
            return;
        } 
    
        std::chrono::milliseconds timer = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        
        if (timer >= (this->_timer + FPS)) {

            this->_timer = timer;
            
            this->draw();   
            this->move();

            SDL_RenderPresent(this->_renderer);
            SDL_RenderClear(this->_renderer);  

        }
    } 
}

void Main::move() {
    this->drawRect(2, 2, "P");
}


void Main::draw() {

    for (int y = 0; y < globals::TILE_COLS; y++) {

        for (int x = 0; x < globals::TILE_ROWS; x++) {

            std::string chr;
            chr.push_back(this->_level[y].val[x]);

            this->drawRect(x, y, chr);
        }
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
    this->_level[4].val = "w                       w";
    this->_level[5].val = "w                       w";
    this->_level[6].val = "w                       w";
    this->_level[7].val = "w                       w";
    this->_level[8].val = "wwwwwwwwwwwwwwwwwwwwwwwww";

    this->_sprites[" "] = { 0, 0, 0, 255 };
    this->_sprites["w"] = { 0, 255, 0, 255 };
    this->_sprites["P"] = { 0, 0, 255, 255 };

    this->_chars["P"] = {"Lil Wolf", 5, 5, true};
}


void Main::log(const char* message) {
    std::cout << message << std::endl;
}
