#include "Game.h"

#include <iostream>

#include "Constants.h"
#include "TransformComponent.h"

Game::Game() : m_bRunning(false), m_window(NULL), m_renderer(NULL), m_deltaTime(0.0f)
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
	loadLevel(0);
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

void Game::update(float deltaTime)
{
	m_manager.update(deltaTime);
}

void Game::render()
{

	SDL_SetRenderDrawColor(m_renderer, 101, 101, 101, 255);
	SDL_RenderClear(m_renderer);

	m_manager.render();

	SDL_RenderPresent(m_renderer);
}

void Game::run()
{
	init();

	float startTime = 0.0f;
	float frameTime = 0.0f;
	float secondCounter = 0.0f;

	while (m_bRunning)
	{
		startTime = SDL_GetTicks();

		handleEvents();
		update(m_deltaTime);
		render();

		frameTime = SDL_GetTicks() - startTime;
		if (frameTime < TIME_PER_FRAME)
		{
			SDL_Delay((int)TIME_PER_FRAME - frameTime);
			//float t = TIME_PER_FRAME - frameTime;
			//float ts = t / 1000.0f;
		}

		frameTime = SDL_GetTicks() - startTime;
		// Clamp dt
		m_deltaTime = (frameTime > TIME_PER_FRAME) ? TIME_PER_FRAME : frameTime;
		m_deltaTime /= 1000; // convert ms to s
		//std::cout << "dt = " << m_deltaTime << "\n";

		++m_frameCount;
		// at every second print FPS
		if ((SDL_GetTicks() - secondCounter) >= 1000.0f)
		{
			std::cout << "FPS: " << m_frameCount << "\n";
			//std::cout << "\x1b[A"; // go back one line up
			secondCounter += 1000.0f;
			m_frameCount = 0;
		}
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

void Game::loadLevel(int level)
{
	Entity& entity = m_manager.addEntity("bullet");

	Vector2D p = Vector2D(0.0f, 0.0f);
	Vector2D v = Vector2D(100.0f, 100.0f);
	Vector2D a = Vector2D(0.0f, 0.0f);

	entity.addComponent<TransformComponent>(p, v, a, 100, 100, 0.0f, 1.0f);
	entity.getComponent<TransformComponent>().setRenderer(m_renderer);

	Entity& entity2 = m_manager.addEntity("missile");

	entity2.addComponent<TransformComponent>(Vector2D(200, 200), Vector2D(200, 20), Vector2D(10, 10), 50, 50, 0.0f, 1.0f);
	entity2.getComponent<TransformComponent>().setRenderer(m_renderer);

	Entity& entity3 = m_manager.addEntity("missile2");

	entity3.addComponent<TransformComponent>(Vector2D(150, 200), Vector2D(0, 40), Vector2D(0, 0), 25, 25, 0.0f, 1.0f);
	entity3.getComponent<TransformComponent>().setRenderer(m_renderer);

	for (auto& _entity : m_manager.getEntities())
	{
		std::cout << "Entity Name: " << _entity->getName() << std::endl;
		for (auto& component : _entity->getComponents())
		{
			std::string type = typeid(*component).name(); // class SomthingComponent
			type.erase(0, 6);
			std::cout << "\tComponent<" << type << ">" << std::endl;
			//std::cout << "\tComponent<" << typeid(*component).name() << ">" << std::endl;
		}
	}
}
