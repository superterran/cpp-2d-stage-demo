#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>


#include <string>


// struct SDL_Rect;
// struct SDL_Texture;

class Graphics;

class Sprite {
    public:
        Sprite();
        Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);

        virtual ~Sprite();
        virtual void update();
        void draw(Graphics &graphics, int x, int y);

    private:
        SDL_Rect _sourceRect;
        SDL_Texture* _spriteSheet;

        float _x, _y;

};

#endif