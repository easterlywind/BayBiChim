#include"GameLoop.hpp"

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	p.setSrc(0, 0, 24, 32);
	p.setDest(25, HEIGHT/2, 28, 38);
	ground1.setSrc(0, 0, 112, 336);
	ground1.setDest(0, 420, 112, 336);
	ground2.setSrc(0, 0, 112, 336);
	ground2.setDest(336, 420, 112, 336);
}

bool GameLoop::getGameState()
{
	return GameState;
}

void GameLoop::Intialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("BabyChim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Succeeded!" << std::endl;
			GameState = true;
			p.CreateTexture("assets/image/yellowbird1.png", renderer);
			p.CreateTexture1("assets/image/yellowbird2.png", renderer);
			p.CreateTexture2("assets/image/yellowbird3.png", renderer);
			b.CreateTexture("assets/image/background-day.png", renderer);
			ground1.CreateTexture("assets/image/base.png", renderer);
			ground2.CreateTexture("assets/image/base.png", renderer);
		}
		else
		{
			std::cout << "Not created!" << std::endl;
		}
	}
	else
	{
		std::cout << "window not created!" << std::endl;
	}
}

void GameLoop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = false;
	}
	if (event1.type == SDL_KEYDOWN)
	{
		if (event1.key.keysym.sym == SDLK_UP)
		{
			if (!p.JumpState())
			{
				p.Jump();
			}
			else
			{
				p.Gravity();
			}
		}
	}
	else
	{
		p.Gravity();
	}
}

void GameLoop::Update()
{
	//ground1.GroundUpdate1();
	//ground2.GroundUpdate2();
}

void GameLoop::Render()
{
	SDL_RenderClear(renderer);
	b.Render(renderer);
	//ground1.GroundRender(renderer);
	//ground2.GroundRender(renderer);
	p.Render(renderer);
	SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

