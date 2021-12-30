#pragma once

class Game
{
public:

	Game();
	~Game();

	void initialize();

	void handleInput();
	void update();
	void render();

	void clean();

private:
};

