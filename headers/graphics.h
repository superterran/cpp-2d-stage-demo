#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;
struct SDL_Texture;
struct SDL_Surface;

class Graphics {
    public:
        Graphics();
        ~Graphics();

        /**
         * loads an image into the _spritesheets map if it doesn't already exist 
         * as a result, each image will only be loaded once. 
         * Returns the image from the map regardless if image was not just loaded
         */
        SDL_Surface* loadImage(const std::string &filePath);

        /**
         * void BlitSurface
         * draws a texture to part of the screen
         */
        void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

        /**
         * Renders everything to the screen
         */
        void flip();

        /**
         * clears the screen
         */
        void clear();

        /**
         * returns the renderer
         */
        SDL_Renderer* getRenderer() const;
    
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;

        std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif