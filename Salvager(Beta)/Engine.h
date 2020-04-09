#pragma once

#include "fstream"

#include "Sprite.h"
#include "Background.h"
#include "Player.h"
#include "Hazard.h"
#include "Levels.h"
#include "Images.h"
#include "SoundManager.h"
#include "Asteroid.h"
#include "Timer.h"
#include "Font.h"
#include "Collision.h"

#define fps 60

enum State {
	TITLE,
	GAME,
	WIN,
	LOSE,
	SCORE
};

class Engine
{

public:

	Engine() :m_iFps(fps), m_bGotTick(false) {}
	~Engine() {}

	bool init(const char*title, int xpos, int ypos, int width, int height, int flags);

	bool running();
	bool tick();
	void update();
	void render();
	void clean();
	void pause();
	void handleEvents();
	void nextLevel();
	void backgroundMovement();
	void mainMenu();
	void endMenu();
	void gameMenu();
	void scoreMenu();
	void move();
	void resetLevel();
	void destroyTexture();
	void m_checkState();
	State getState();
	void setState(State m_newState);
	static Engine* I()
	{

		static Engine* instance = new Engine();
		return instance;

	}

private:

	int m_iFps, m_iCurrLvl;
	int m_iHighScore;

	bool m_bRunning, m_bGotTick, m_bPause;
	bool m_bUp, m_bDown, m_bLeft, m_bRight;

	string m_sCurrScoreText;
	State m_State;

	MainMenu *m_Mainmenu;
	Win *m_Win;
	Lose *m_Lose;
	Paused *m_Paused;
	GroupLogo *m_Group;

	Player *m_Player;
	Levels *m_Levels;
	Asteroid *m_Clouds;
	Music *m_Music;
	Timer *m_Timer;
	Hazard *m_Enemy;
	Background *m_pBackground;

	Font * m_Font;
	Collision m_Collision;
	Health m_PlayerHp[5] = { Health(980, 715), Health(947, 715), Health(914, 715), Health(881, 715) , Health(848, 715) };
	Background m_Backgrounds[2] = { Background(0, 0), Background( 0, 768)};

	SDL_Window*m_pWindow;
	SDL_Renderer*m_pRenderer;

	SDL_Texture* m_pFontTexture, *m_pGameFontTexture;

	SDL_Texture*m_pBackgroundTexture[levels];
	SDL_Texture*m_pPlayerShipTexture; 
	SDL_Texture* m_pHealthTexture;
	SDL_Texture*m_pEnemyTexture;

	SDL_Texture*m_pGroupLogoTexture;
	SDL_Texture*m_pMainMenuTexture;
	SDL_Texture*m_pCloudTexture;
	SDL_Texture*m_pPauseTexture;
	SDL_Texture*m_pWinTexture;
	SDL_Texture*m_pLoseTexture;
};

