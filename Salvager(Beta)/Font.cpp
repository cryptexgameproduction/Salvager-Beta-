#include "Font.h"

Font::Font()
{

}

void Font::MakeFont()
{

	Message_rect.x = 724 / 2;  //controls the rect's x coordinate 
	Message_rect.y = 668 / 2; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 100;

	ifstream m_inputFile(filename);

	if (m_inputFile.is_open())
	{
		m_inputFile >> m_iHighScore;
		m_sHighScoreText = "High Score : " + to_string(m_iHighScore);

		m_pGameFont = TTF_OpenFont("Raleway-Black.ttf", 48);

		if (m_pGameFont == NULL) {

			fprintf(stderr, "error: font not found\n");

		}
		else {

			m_pFontColour = { 255 , 165, 0 };
			m_pFontSurface = TTF_RenderText_Solid(m_pGameFont, m_sHighScoreText.c_str(), m_pFontColour); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

		}
	}

	TTF_CloseFont(m_pGameFont);
	m_inputFile.close();
}

void Font::printCurrScore(string &m_sCurrScoreText)
{
	m_GameMessage_Rect.x = 50;
	m_GameMessage_Rect.y = 700;
	m_GameMessage_Rect.w = 100;
	m_GameMessage_Rect.h = 100;

	m_pGameFont = TTF_OpenFont("Raleway-Black.ttf", 48);

	if (m_pGameFont == NULL) {

		fprintf(stderr, "error: font not found\n");

	}
	else {

		m_pFontColour = {255 , 165, 0 };
		m_pGameFontSurface = TTF_RenderText_Solid(m_pGameFont, m_sCurrScoreText.c_str(), m_pFontColour); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	}

	TTF_CloseFont(m_pGameFont);

}

void Font::saveScore(Timer *m_Timer)
{
	ifstream m_inputFile("Assets/Score.txt");
	if (m_inputFile.is_open())
	{
		m_inputFile >> m_iHighScore;
	}
	if (int(m_Timer->get_ticks() / 1000.f) < m_iHighScore || m_iHighScore == 0) {

		ofstream m_outputFile(filename);

		if (m_outputFile.is_open()) {

			m_outputFile << int(m_Timer->get_ticks() / 1000.f);

		}

		m_outputFile.close();

	}
}
