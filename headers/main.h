#ifndef MAIN_H
#define MAIN_H

#include <map>
#include <string>
#include <array> 
#include <chrono>

struct SDL_Window;
struct SDL_Renderer;

struct Level {
	std::string val;
};

struct Sprite {
	int r;
	int g;
	int b;
	int a;
};

struct Char {
	std::string name;
	int x;
	int y;
	bool player;
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

	void draw();

	void move();

	Level _level[20];
	
	std::map<std::string, Sprite> _sprites;
	std::chrono::milliseconds _timer ;
	std::map<std::string, Char> _chars;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif