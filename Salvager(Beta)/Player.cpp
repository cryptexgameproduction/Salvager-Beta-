#include "Player.h"

Player::Player()
{

	m_rSrc.x = 0;	m_rDst.x = 450;
	m_rSrc.y = 0;	m_rDst.y = 700;
	m_rSrc.w = 32;	m_rDst.w = 50;
	m_rSrc.h = 32;	m_rDst.h = 50;
	speed = 3;		m_iRad = (m_rDst.w + m_rDst.h - 30) / 4;
	m_iLife = 5;	
	m_iSavedX = 450;
	m_iSavedY = 700;

	//cout<< "x ="<<m_rDst.x<<endl;
	

}

Player::~Player()
{
}

void Player::movex(int m)
{

	m_rDst.x += m * speed;

}

void Player::movey(int m)
{

	m_rDst.y += m * speed;

}

void Player::animation()
{

	if (delayCtr == delayMax)
	{

		if (frameCtr < frameMax)
		{

			m_rSrc.x = 32 * frameCtr;
			frameCtr++;

		}

		else if (frameCtr == frameMax)
		{

			frameCtr = 0;

		}

		delayCtr = 0;

	}

	delayCtr++;

}

int Player::returnLife() {

	return m_iLife;

}

void Player::setLife() {

	m_iLife -= 1;

}
int Player::getSavedX()
{
	return m_iSavedX;
}


int Player::getSavedY()
{
	return m_iSavedY;
}


void Player::setSavedX(int x)
{
	m_iSavedX = x;

}

void Player::setSavedY(int y)
{
	m_iSavedY = y;
}



void Player::reset() {

	m_iLife = 5;
	m_rDst.x = 450;
	m_rDst.y = 700;
	m_iSavedX = 450;
	m_iSavedY = 700;

}

void Player::moveOn()
{
	m_rDst.x = 450;
	//setSavedY(y);
	m_rDst.y = 700;

}