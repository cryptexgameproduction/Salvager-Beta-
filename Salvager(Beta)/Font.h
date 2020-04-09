#pragma once

#include "Sprite.h"
#include "Timer.h"
#include <fstream>
#define filename "Assets/Score.txt"

class Font {
public:
	SDL_Surface* m_pFontSurface, * m_pGameFontSurface;
	SDL_Rect m_GameMessage_Rect, Message_rect;
	Font();
	void MakeFont();
	void printCurrScore(string &m_sCurrScoreText);
	void saveScore(Timer *m_Timer);
private:
	int m_iHighScore;
	string m_sHighScoreText;
	TTF_Font* m_pGameFont;
	SDL_Color m_pFontColour;
};