#pragma once
#include "Sprite.h"
#include "Levels.h"
#include "Player.h"
#include "SoundManager.h"
#include "Timer.h"
#include "Font.h"

class Collision {
public:
	Collision();
	~Collision();
	void cloudCollision(Player *m_Player, Levels *m_Levels, int &m_currLvl, Music* m_Music);
	bool hazardCollision(Player *m_Player, Levels *m_Levels, int &m_currLvl, Music *m_Music, Timer *m_Timer);
	bool circleCollision(double x1, double x2, double y1, double y2, double r1, double r2);

private:
};