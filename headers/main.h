#ifndef MAIN_H
#define MAIN_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Main {
public:
	Main();
	~Main();

	SDL_Surface* loadImage(const std::string &filePath);

	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	void gameLoop();

	void flip();

	void clear();

	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif