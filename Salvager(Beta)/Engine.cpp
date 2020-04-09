#include "Engine.h"

#include <chrono>

using namespace chrono;

bool Engine::init(const char*title, int xpos, int ypos, int width, int height, int flags)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		cout << "SDL INIT SUCCESS" << endl;
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)
		{

			cout << "Window Creation Successful" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{

				cout << "Renderer Creation successful" << endl;
				IMG_Init(IMG_INIT_PNG);

				SDL_Surface* m_pPlayerShipSurface = IMG_Load("Assets/player_ship_3.png");
				SDL_Surface* m_pBackgroundSurfaceOne = IMG_Load("Assets/background.png");
				SDL_Surface* m_pBackgroundSurfaceTwo = IMG_Load("Assets/background_2.png");
				SDL_Surface* m_pBackgroundSurfaceThree = IMG_Load("Assets/background_3.png");
				SDL_Surface* m_pBackgroundSurfaceFour = IMG_Load("Assets/background_4.png");
				SDL_Surface* m_pBackgroundSurfaceFive = IMG_Load("Assets/background.png");
				SDL_Surface* m_pCloudSurface = IMG_Load("Assets/astroid.png");
				SDL_Surface* m_pEnemySurface = IMG_Load("Assets/New_Enemy.png");
				SDL_Surface* m_pWinSurface = IMG_Load("Assets/victory.png");
				SDL_Surface* m_pLoseSurface = IMG_Load("Assets/Game_Over.png");
				SDL_Surface* m_pGroupLogoSurface = IMG_Load("Assets/cellblock_d_logo.png");
				SDL_Surface* m_pPauseSurface = IMG_Load("Assets/salvager_pause.png");
				SDL_Surface* m_pMainMenuSurface = IMG_Load("Assets/MainMenu.png");
				SDL_Surface* m_pHealthSurface = IMG_Load("Assets/health.png");

				m_pHealthTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pHealthSurface);
				m_pPlayerShipTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pPlayerShipSurface);
				m_pBackgroundTexture[0] = SDL_CreateTextureFromSurface(m_pRenderer, m_pBackgroundSurfaceOne);
				m_pBackgroundTexture[1] = SDL_CreateTextureFromSurface(m_pRenderer, m_pBackgroundSurfaceTwo);
				m_pBackgroundTexture[2] = SDL_CreateTextureFromSurface(m_pRenderer, m_pBackgroundSurfaceThree);
				m_pBackgroundTexture[3] = SDL_CreateTextureFromSurface(m_pRenderer, m_pBackgroundSurfaceFour);
				m_pBackgroundTexture[4] = SDL_CreateTextureFromSurface(m_pRenderer, m_pBackgroundSurfaceFive);
				m_pEnemyTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pEnemySurface);
				m_pCloudTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pCloudSurface);
				m_pMainMenuTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pMainMenuSurface);
				m_pPauseTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pPauseSurface);
				m_pWinTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pWinSurface);
				m_pLoseTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pLoseSurface);
				m_pGroupLogoTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pGroupLogoSurface);

				SDL_FreeSurface(m_pBackgroundSurfaceOne);
				SDL_FreeSurface(m_pBackgroundSurfaceTwo);
				SDL_FreeSurface(m_pBackgroundSurfaceThree);
				SDL_FreeSurface(m_pBackgroundSurfaceFour);
				SDL_FreeSurface(m_pBackgroundSurfaceFive);
				SDL_FreeSurface(m_pEnemySurface);
				SDL_FreeSurface(m_pCloudSurface);
				SDL_FreeSurface(m_pPlayerShipSurface);
				SDL_FreeSurface(m_pMainMenuSurface);
				SDL_FreeSurface(m_pPauseSurface);
				SDL_FreeSurface(m_pWinSurface);
				SDL_FreeSurface(m_pLoseSurface);
				SDL_FreeSurface(m_pGroupLogoSurface);
				SDL_FreeSurface(m_pHealthSurface);

				TTF_Init();


				if (TTF_Init() == -1) {
					std::cout << "TTF_Init: %s\n", TTF_GetError();
					exit(2);
				}
				else {
					std::cout << "TTF Loaded" << endl;
				}


				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					std::cout << "Error: " << Mix_GetError() << std::endl; // If Fails to Initialize Audio, Will Display this Error.
				}
			}

			else
			{

				cout << "Renderer Failed" << endl;

				return false;

			}

		}

		else
		{

			cout << "WINDOW CREATION Failed" << endl;

			return false;

		}

	}

	else
	{

		cout << "SDL SYSTEMS Failed" << endl;

		return false;

	}
	
	m_Mainmenu = new MainMenu();
	m_Win = new Win();
	m_Lose = new Lose();
	m_Paused = new Paused();
	m_Group = new GroupLogo();
	m_Player = new Player();
	m_pBackground = new Background();
	m_Levels = new Levels();
	m_Clouds = new Asteroid();
	m_Music = new Music();
	m_Timer = new Timer();
	m_Enemy = new Hazard();
	m_Font = new Font();
	setState(State::TITLE);
	cout << "Everything worked" << endl;
	m_Music->BaseMusic();
	m_Font->MakeFont();
	SDL_FreeSurface(m_Font->m_pFontSurface);
	m_bRunning = true;
	//First start with Main screen. Will render main screen first
	//Set Current Level to 0
	m_iCurrLvl = 0;
	//Game is paused.
	m_bPause = false;

	return true;

}

bool Engine::running()
{

	return m_bRunning;

}

bool Engine::tick()
//Timer
{

	auto duration = steady_clock::now().time_since_epoch();
	auto count = duration_cast<microseconds>(duration).count();

	int tick = 1000000 / m_iFps;

	if (count % tick < 100) // Drops potential duplicate frames.
	{

		if (m_bGotTick == false)
		{

			m_bGotTick = true;
			//cout << "Tick " << tick << " @ " << count << endl;
			return true;

		}

		return false;

	}

	else m_bGotTick = false;

	return false;

}

void Engine::update()
//Updates Player, Hazard, Background
{
	
	if (getState() == State::TITLE || getState() == State::WIN || getState() == State::LOSE) {
		backgroundMovement();
	}

	if (getState() == State::SCORE) {
		backgroundMovement();
		m_Font->MakeFont();
		m_pFontTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Font->m_pFontSurface);
		SDL_FreeSurface(m_Font->m_pFontSurface);
	}
	//If paused, player don't move, hazards dont move.
	if (!m_bPause && getState() == State::GAME)
	{
		backgroundMovement();

		m_sCurrScoreText = to_string(int(m_Timer->get_ticks() / 1000.f));

		m_Font->printCurrScore(m_sCurrScoreText);
		m_pGameFontTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Font->m_pGameFontSurface);

		SDL_FreeSurface(m_Font->m_pGameFontSurface);

		m_Collision.cloudCollision(m_Player, m_Levels, m_iCurrLvl,m_Music);
		if (m_Collision.hazardCollision(m_Player, m_Levels, m_iCurrLvl, m_Music, m_Timer)) {
			setState(State::LOSE);
		}
		nextLevel();
		move();

		//if (m_bUp || m_bDown || m_bLeft || m_bRight)

		m_Player->animation();

		for (int i = 0; i < totalHazards; i++)
		{

			if (m_Levels->hazards[m_iCurrLvl][i].alive == true)
			{

				m_Levels->hazards[m_iCurrLvl][i].frameAnimation();
			}

		}

	}
}


void Engine::render()
//Renders based on boolean
{

	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pBackgroundTexture[m_iCurrLvl], m_Backgrounds[0].getSource(), m_Backgrounds[0].getDes());
	SDL_RenderCopy(m_pRenderer, m_pBackgroundTexture[m_iCurrLvl], m_Backgrounds[1].getSource(), m_Backgrounds[1].getDes());
	

	m_checkState();

	SDL_RenderPresent(m_pRenderer);

}

void Engine::handleEvents()
//Key Down/Up Events
{

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{

		case SDL_QUIT:

			m_bRunning = false;
			break;

		case SDL_KEYDOWN:

			switch (event.key.keysym.sym)
			{

			case SDLK_ESCAPE:

				if (getState() == State::TITLE || getState() == State::WIN || getState() == State::LOSE || getState() == State::SCORE || getState() == State::GAME)
				{
					m_bRunning = false;
				}

				break;

			case'w':
			case 'W':

				if (!m_bUp)
				{

					m_bUp = true;

				}

				break;

			case'a':
			case 'A':

				if (!m_bLeft)
				{

					m_bLeft = true;

				}

				break;

			case's':
			case 'S':
				if (getState() == State::TITLE)
				{
					setState(State::SCORE);
					break;
				}

				if (getState() == State::SCORE)
				{
					setState(State::TITLE);
					break;
				}

				if (getState() == State::GAME && !m_bDown)
				{

					m_bDown = true;

				}

				break;

			case'd':
			case 'D':

				if (!m_bRight)
				{

					m_bRight = true;

				}

				break;

				//Start game from main menu
			case'r':
			case 'R':

				if (getState() == State::WIN || getState() == State::LOSE)
				{
					m_Player->reset();
					resetLevel();
					break;
				}

				if (getState() == State::TITLE)
				{
				
					setState(State::GAME);
					m_Timer->start();
					break;
				}

				if (getState() == State::SCORE)
				{
				
					setState(State::GAME);
					m_Timer->start();
					break;
				}
				break;

				// Pause
			case'p':
			case'P':

				pause();

				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{

			case'w':
			case 'W':
				m_bUp = false;

				break;

			case'a':
			case 'A':

				m_bLeft = false;

				break;

			case's':
			case 'S':

				m_bDown = false;

				break;

			case'd':
			case 'D':

				m_bRight = false;

				break;

			}

			break;

		}
	}
}

void Engine::clean()
//Cleans the program
{
	delete m_Player;
	delete m_Levels;
	delete m_Clouds;
	delete m_Music;
	delete m_Timer;
	delete m_Enemy;
	delete m_Mainmenu;
	delete m_Win;
	delete m_Lose;
	delete m_Paused;
	delete m_Group;
	delete m_pBackground;
	delete m_Font;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	destroyTexture();
	SDL_DestroyTexture(m_pFontTexture);
	SDL_DestroyTexture(m_pGameFontTexture);
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

}

void Engine::pause()
//Pause Game
{

	if (getState() == State::GAME && !m_bPause)
	{

		m_bPause = true;
		m_Timer->pause();

	}

	else
	{

		m_bPause = false;
		m_Timer->unpause();
	}
}

void Engine::nextLevel()
{
	if ((m_Player->m_rDst.x + m_Player->m_rDst.w) <= 1024 && (m_Player->m_rDst.y + m_Player->m_rDst.h) <= 50 )
	{

		if (m_iCurrLvl < 2)
		{

			m_iCurrLvl++;

		}

		else
		{
			setState(State::WIN);
			m_Font->saveScore(m_Timer);
			m_Timer->stop();

		}
		m_Player->moveOn();

	}
}

void Engine::backgroundMovement()
{
	m_Backgrounds[0].sideScroll();
	m_Backgrounds[1].sideScroll(); 
	
}

void Engine::mainMenu()
{
	SDL_RenderCopy(m_pRenderer, m_pMainMenuTexture, m_Mainmenu->getSource(), m_Mainmenu->getDes());
	SDL_RenderCopy(m_pRenderer, m_pGroupLogoTexture, m_Group->getSource(), m_Group->getDes());
}

void Engine::endMenu()
{
	if (getState() == State::WIN) {
		SDL_RenderCopy(m_pRenderer, m_pWinTexture, m_Win->getSource(), m_Win->getDes());
	}
	if (getState() == State::LOSE) {
		SDL_RenderCopy(m_pRenderer, m_pLoseTexture, m_Lose->getSource(), m_Lose->getDes());
	}
}

void Engine::gameMenu()
{

	SDL_RenderCopy(m_pRenderer, m_pPlayerShipTexture, m_Player->getSource(), m_Player->getDes());
	SDL_QueryTexture(m_pGameFontTexture, NULL, NULL, &m_Font->m_GameMessage_Rect.w, &m_Font->m_GameMessage_Rect.h);
	SDL_RenderCopy(m_pRenderer, m_pGameFontTexture, NULL, &m_Font->m_GameMessage_Rect);

	for (int i = 0; i < totalHazards; i++)
	{

		if (m_Levels->hazards[m_iCurrLvl][i].alive == true)
		{

			SDL_RenderCopy(m_pRenderer, m_pEnemyTexture, m_Levels->hazards[m_iCurrLvl][i].getSource(), m_Levels->hazards[m_iCurrLvl][i].getDes());
		}

	}
	for (int i = 0; i < totalAsteroids; i++) {
		SDL_RenderCopy(m_pRenderer, m_pCloudTexture, m_Levels->Asteroids[m_iCurrLvl][i].getSource(), m_Levels->Asteroids[m_iCurrLvl][i].getDes());
	}

	for (int i = 0; i < m_Player->returnLife(); i++)
	{
		SDL_RenderCopy(m_pRenderer, m_pHealthTexture, m_PlayerHp[i].getSource(), m_PlayerHp[i].getDes());
	}

	if (m_bPause) {
		SDL_RenderCopy(m_pRenderer, m_pPauseTexture, m_Paused->getSource(), m_Paused->getDes());
	}

}

void Engine::scoreMenu()
{
	SDL_QueryTexture(m_pFontTexture, NULL, NULL, &m_Font->Message_rect.w, &m_Font->Message_rect.h);
	SDL_RenderCopy(m_pRenderer, m_pFontTexture, NULL, &m_Font->Message_rect);
}


void Engine::move()
{
	if (m_bUp == true && m_Player->m_rDst.y > 0)
	{
		m_Player->movey(-1);
	}

	if (m_bDown == true && m_Player->m_rDst.y < 768 - 50)
	{
		m_Player->movey(1);
	}

	if (m_bLeft == true && m_Player->m_rDst.x > 0)
	{
		m_Player->movex(-1);
	}

	if (m_bRight == true && m_Player->m_rDst.x < 1024 - 50)
	{
		m_Player->movex(1);
	}
}

void Engine::resetLevel()
//Resets Level
{
	m_Timer->stop();
	setState(State::TITLE);
	m_iCurrLvl = 0;

	for (int i = 0; i < 4; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			m_Levels->hazards[i][j].reset();

		}
	}
}

void Engine::destroyTexture()
{
	SDL_DestroyTexture(m_pBackgroundTexture[0]);
	SDL_DestroyTexture(m_pBackgroundTexture[1]);
	SDL_DestroyTexture(m_pBackgroundTexture[2]);
	SDL_DestroyTexture(m_pBackgroundTexture[3]);
	SDL_DestroyTexture(m_pBackgroundTexture[4]);
	SDL_DestroyTexture(m_pBackgroundTexture[5]);
	SDL_DestroyTexture(m_pPlayerShipTexture);
	SDL_DestroyTexture(m_pEnemyTexture);
	SDL_DestroyTexture(m_pMainMenuTexture);
	SDL_DestroyTexture(m_pCloudTexture);
	SDL_DestroyTexture(m_pPauseTexture);
	SDL_DestroyTexture(m_pHealthTexture);
	SDL_DestroyTexture(m_pWinTexture);
	SDL_DestroyTexture(m_pLoseTexture);
	SDL_DestroyTexture(m_pFontTexture);
	SDL_DestroyTexture(m_pGroupLogoTexture);
}


void Engine::m_checkState()
{
	switch (getState())
	{
	case State::TITLE:
		mainMenu();
		break;
	case State::GAME:
		gameMenu();
		break;
	case State::WIN:
		endMenu();
		break;
	case State::LOSE:
		endMenu();
		break;
	case State::SCORE:
		scoreMenu();
		break;
	}
}

State Engine::getState()
{
	return m_State;
}

void Engine::setState(State m_newState)
{
	m_State = m_newState;
}

