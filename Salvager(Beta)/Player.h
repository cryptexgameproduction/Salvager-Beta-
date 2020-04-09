#pragma once

#include "Sprite.h"

class Player : public Sprite
{
public:
	Player();
	~Player();

	void movex(int m);
	void movey(int m);
	void animation();

	int returnLife();

	void setLife();
	int getSavedY();
	int getSavedX();
	void setSavedY(int y);
	void setSavedX(int x);
	void reset();

	void moveOn();
private:

	int speed;
	int frameCtr = 0;
	int frameMax = 3;
	int delayCtr = 0;
	int delayMax = 8;
	int m_iLife;
	int m_iSavedX;
	int m_iSavedY;

};

class Health : public Sprite
{
public:
	Health(int x,int y)
	{
		m_rSrc.x = m_rSrc.y = 0;
		m_rSrc.w = 135, m_rSrc.h = 120;
		m_rDst.x = x, m_rDst.y = y;
		m_rDst.w = 40, m_rDst.h = 50;
	}
	~Health() {}

};