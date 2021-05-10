#ifndef MAIN_H
#define MAIN_H

#include <map>
#include <string>
#include <array> 

struct SDL_Window;
struct SDL_Renderer;

struct Level {
	std::string val;
};

struct Tiles {
	std::string id;
	int r;
	int g;
	int b;
	int a;
};

class Main {

public:
	Main();
	~Main();

	void gameLoop();

	void drawRect(int x, int y, std::string tile);

	void log(const char* message);

	SDL_Renderer* getRenderer() const;

	void loadYaml();

	void loadLevel();

	Level _level[20];
	Tiles _tiles[26];

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif