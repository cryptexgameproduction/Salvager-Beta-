#include "Background.h"


Background::Background()
{
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 1600;
	m_rSrc.h = 900;

	m_rDst.x = 0;
	m_rDst.y = 0;
	m_rDst.w = 1024;
	m_rDst.h = 768;

}

Background::~Background()
{
}

Background::Background(int x, int y)
{
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 1600;
	m_rSrc.h = 900;

	m_rDst.x = x;
	m_rDst.y = y;
	m_rDst.w = 1024;
	m_rDst.h = 768;

	temp = y;

}
void Background::sideScroll()
{

	m_rDst.y += 3;

	if (m_rDst.y >= (temp + 0))
	{

		m_rDst.y -= 768;
	}

}