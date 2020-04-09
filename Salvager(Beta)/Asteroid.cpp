#include "Asteroid.h"


Asteroid::Asteroid() {


	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 120;
	m_rSrc.h = 120;

	m_iRad = ((m_rDst.w) + (m_rDst.h) - 10 ) / 5;//m_rDst.h / 2;
}

Asteroid::~Asteroid()
{
}

void Asteroid::animation()
{

}

Asteroid::Asteroid(int x, int y, int w, int h)
{

	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 120;
	m_rSrc.h = 120;

	m_rDst.x = x;
	m_rDst.y = y;
	m_rDst.w = w;
	m_rDst.h = h;

	m_iRad = ((m_rDst.w ) + (m_rDst.h) - 10)  / 5;//m_rDst.h / 2;
}