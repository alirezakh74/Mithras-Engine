#pragma once

#include <SDL2/SDL.h>

#include "EntityManager.h"

class Game
{
public:

	Game();
	~Game();

	void init();

	void handleEvents();
	void update(float deltaTime);
	void render();

	void run();

	void clean();

	bool isRunning() { return m_bRunning; }
	static SDL_Renderer* renderer;

	void loadLevel(int level);

private:

	bool m_bRunning;
	SDL_Window* m_window;
	float m_deltaTime = 0.0f;
	int m_frameCount = 0;
	EntityManager m_manager;
};

