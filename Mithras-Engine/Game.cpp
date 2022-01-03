#include "Game.h"

#include <iostream>

#include "Constants.h"

Game::Game() : m_bRunning(false), m_window(NULL), m_renderer(NULL)
{
}

Game::~Game()
{
}

void Game::init()
{
	m_window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		std::cerr << "window creation is failed." << "\n";
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (m_renderer == NULL)
	{
		std::cerr << "Renderer creation is failed." << "\n";
		return;
	}

	m_bRunning = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				m_bRunning = false;
			}
			break;
		default:
			break;
		}
	}
}

float posX = 0.0f;
float posY = 0.0f;
float velX = 0.1f;
float velY = 0.1f;

void Game::update()
{
	posX += velX;
	posY += velY;
}

void Game::render()
{
	SDL_Rect myRect = { posX, posY, 10, 10 };

	SDL_SetRenderDrawColor(m_renderer, 101, 101, 101, 255);
	SDL_RenderClear(m_renderer);

	SDL_SetRenderDrawColor(m_renderer, 255, 101, 101, 255);
	SDL_RenderFillRect(m_renderer, &myRect);

	SDL_RenderPresent(m_renderer);
}

void Game::run()
{
	init();

	while (m_bRunning)
	{
		handleEvents();
		update();
		render();
	}

	clean();
}

void Game::clean()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = NULL;
	SDL_DestroyWindow(m_window);
	m_window = NULL;
}
