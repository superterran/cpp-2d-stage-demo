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

	void gameLoop();

	void drawRect(int x, int y, int h, int w);

	void log(const char* message);

	SDL_Renderer* getRenderer() const;

	void loadYaml();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif