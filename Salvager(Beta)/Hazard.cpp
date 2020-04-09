#include "Hazard.h"

Hazard::Hazard() {


}

Hazard::~Hazard()
{
}

Hazard::Hazard(int x, int y, int dL)
{

	resetX = x;
	resetY = y;

	m_rSrc.x = 0;	m_rDst.x = x;
	m_rSrc.y = 0;	m_rDst.y = y;
	m_rSrc.w = 32;	m_rDst.w = 64;
	m_rSrc.h = 32;	m_rDst.h = 64;

	m_iRad = (m_rDst.w + m_rDst.h - 30) / 4;


	upLimit = y;
	downLimit = dL;

	alive = true;

	down = true;
	up = false;

	speed = 3;

}

void Hazard::animation()
{
	m_rDst.y += 1.5 * speed;

	if (m_rDst.y >= 800)
	{
		m_rDst.y = resetY - 700;

	}
	//if (down)
	//{

	//	if ((m_rDst.y + m_rDst.h) <= downLimit)
	//	{

	//		m_rDst.y += 1 * speed;

	//	}

	//	if ((m_rDst.y + m_rDst.h) >= downLimit)
	//	{

	//		up = true;
	//		down = false;

	//	}

	//}

	//if (up)
	//{

	//	if (m_rDst.y >= upLimit)
	//	{

	//		m_rDst.y += -1 * speed;

	//	}

	//	if ((m_rDst.y) <= upLimit)
	//	{

	//		up = false;
	//		down = true;

	//	}

	//}

}

void Hazard::frameAnimation()
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

void Hazard::reset()
{

	alive = true;
	m_rDst.x = resetX;
	m_rDst.y = resetY;

}