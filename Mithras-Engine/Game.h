#pragma once

#include <SDL2/SDL.h>

class Game
{
public:

	Game();
	~Game();

	void init();

	void handleEvents();
	void update();
	void render();

	void run();

	void clean();

	bool isRunning() { return m_bRunning; }

private:

	bool m_bRunning;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

